// Copyright 2011 WebDriver committers
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef WEBDRIVER_IE_SENDKEYSCOMMANDHANDLER_H_
#define WEBDRIVER_IE_SENDKEYSCOMMANDHANDLER_H_

#include <ctime>
#include "Session.h"
#include "interactions.h"
#include "logging.h"

const LPCTSTR fileDialogNames[] = {
	_T("#32770"),
	_T("ComboBoxEx32"),
	_T("ComboBox"),
	_T("Edit"),
	NULL
};

namespace webdriver {

class SendKeysCommandHandler : public CommandHandler {
public:
	struct FileNameData {
		HWND main;
		HWND hwnd;
		DWORD ieProcId;
		const wchar_t* text;
	};

	SendKeysCommandHandler(void) {
	}

	virtual ~SendKeysCommandHandler(void) {
	}

protected:
	void SendKeysCommandHandler::ExecuteInternal(const IESessionWindow& session, const LocatorMap& locator_parameters, const ParametersMap& command_parameters, Response * response)
	{
		LocatorMap::const_iterator id_parameter_iterator = locator_parameters.find("id");
		ParametersMap::const_iterator value_parameter_iterator = command_parameters.find("value");
		if (id_parameter_iterator == locator_parameters.end()) {
			response->SetErrorResponse(400, "Missing parameter in URL: id");
			return;
		} else if (value_parameter_iterator == command_parameters.end()) {
			response->SetErrorResponse(400, "Missing parameter: value");
			return;
		} else {
			std::wstring element_id = CA2W(id_parameter_iterator->second.c_str(), CP_UTF8);

			std::wstring keys = L"";
			Json::Value key_array = value_parameter_iterator->second;
			for (unsigned int i = 0; i < key_array.size(); ++i ) {
				std::string key(key_array[i].asString());
				keys.append(CA2W(key.c_str(), CP_UTF8));
			}

			BrowserHandle browser_wrapper;
			int status_code = session.GetCurrentBrowser(&browser_wrapper);
			if (status_code != SUCCESS) {
				response->SetErrorResponse(status_code, "Unable to get browser");
				return;
			}
			HWND window_handle = browser_wrapper->GetWindowHandle();
			TCHAR pszClassName[25];
			::GetClassName(window_handle, pszClassName, 25);

			ElementHandle element_wrapper;
			status_code = this->GetElement(session, element_id, &element_wrapper);

			if (status_code == SUCCESS) {
				bool displayed;
				status_code = element_wrapper->IsDisplayed(&displayed);
				if (status_code != SUCCESS || !displayed) {
					response->SetErrorResponse(EELEMENTNOTDISPLAYED, "Element is not displayed");
					return;
				}

				if (!element_wrapper->IsEnabled()) {
					response->SetErrorResponse(EELEMENTNOTENABLED, "Element is not enabled");
					return;
				}

				CComQIPtr<IHTMLElement> element(element_wrapper->element());

				element->scrollIntoView(CComVariant(VARIANT_TRUE));

				CComQIPtr<IHTMLInputFileElement> file(element);
				if (file) {
					DWORD ie_process_id;
					::GetWindowThreadProcessId(window_handle, &ie_process_id);
					HWND top_level_window_handle = browser_wrapper->GetTopLevelWindowHandle();

					FileNameData key_data;
					key_data.main = top_level_window_handle;
					key_data.hwnd = window_handle;
					key_data.text = keys.c_str();
					key_data.ieProcId = ie_process_id;

					unsigned int thread_id;
					HANDLE thread_handle = reinterpret_cast<HANDLE>(_beginthreadex(NULL, 0, &SendKeysCommandHandler::SetFileValue, (void *) &key_data, 0, &thread_id));

					element->click();
					// We're now blocked until the dialog closes.
					::CloseHandle(thread_handle);
					return;
				}

				this->WaitUntilElementFocused(element);

				sendKeys(window_handle, keys.c_str(), session.speed());
				response->SetResponse(SUCCESS, Json::Value::null);
				return;
			} else {
				response->SetErrorResponse(status_code, "Element is no longer valid");
				return;
			}
		}
	}
private:
	static unsigned int WINAPI SendKeysCommandHandler::SetFileValue(void *file_data) {
		FileNameData* data = reinterpret_cast<FileNameData*>(file_data);
		::Sleep(100);
		HWND ie_main_window_handle = data->main;
		HWND dialog_window_handle = ::GetLastActivePopup(ie_main_window_handle);

		int max_wait = 10;
		while ((dialog_window_handle == ie_main_window_handle) && --max_wait) {
			::Sleep(100);
			dialog_window_handle = ::GetLastActivePopup(ie_main_window_handle);
		}

		if (!dialog_window_handle || (dialog_window_handle == ie_main_window_handle)) {
			// No dialog directly owned by the top-level window.
			// Look for a dialog belonging to the same process as
			// the IE server window. This isn't perfect, but it's
			// all we have for now.
			max_wait = 10;
			while ((dialog_window_handle == ie_main_window_handle) && --max_wait) {
				ProcessWindowInfo process_win_info;
				process_win_info.dwProcessId = data->ieProcId;
				::EnumWindows(&BrowserFactory::FindDialogWindowForProcess, (LPARAM)&process_win_info);
				if (process_win_info.hwndBrowser != NULL) {
					dialog_window_handle = process_win_info.hwndBrowser;
				}
			}
		}

		if (!dialog_window_handle || (dialog_window_handle == ie_main_window_handle)) {
			LOG(WARN) << "No dialog found";
			return false;
		}

		return SendKeysToFileUploadAlert(dialog_window_handle, data->text);
	}

	static bool SendKeysToFileUploadAlert(HWND dialog_window_handle, const wchar_t* value) 
	{
		HWND edit_field_window_handle = NULL;
		int maxWait = 10;
		while (!edit_field_window_handle && --maxWait) {
			wait(200);
			edit_field_window_handle = dialog_window_handle;
			for (int i = 1; fileDialogNames[i]; ++i) {
				edit_field_window_handle = getChildWindow(edit_field_window_handle, fileDialogNames[i]);
			}
		}

		if (edit_field_window_handle) {
			// Attempt to set the value, looping until we succeed.
			const wchar_t* filename = value;
			size_t expected = wcslen(filename);
			size_t curr = 0;

			while (expected != curr) {
				::SendMessage(edit_field_window_handle, WM_SETTEXT, 0, (LPARAM) filename);
				wait(1000);
				curr = ::SendMessage(edit_field_window_handle, WM_GETTEXTLENGTH, 0, 0);
			}

			for (int i = 0; i < 10000; i++) {
				HWND open_window_handle = ::GetDlgItem(dialog_window_handle, IDOK);
				if (open_window_handle) {
					LRESULT total = 0;
					total += ::SendMessage(open_window_handle, WM_LBUTTONDOWN, 0, 0);
					total += ::SendMessage(open_window_handle, WM_LBUTTONUP, 0, 0);

					if (total == 0)
					{
						return true;
					}

					wait(500);
				}
			}

			LOG(ERROR) << "Unable to set value of file input dialog";
			return false;
		}

		LOG(WARN) << "No edit found";
		return false;
	}

	bool SendKeysCommandHandler::WaitUntilElementFocused(IHTMLElement *element) {
		// Check we have focused the element.
		bool has_focus = false;
		CComPtr<IDispatch> dispatch;
		element->get_document(&dispatch);
		CComQIPtr<IHTMLDocument2> document(dispatch);

		// If the element we want is already the focused element, we're done.
		CComPtr<IHTMLElement> active_element;
		if (document->get_activeElement(&active_element) == S_OK) {
			if (active_element.IsEqualObject(element)) {
				return true;
			}
		}

		CComQIPtr<IHTMLElement2> element2(element);
		element2->focus();

		clock_t max_wait = clock() + 1000;
		for (int i = clock(); i < max_wait; i = clock()) {
			wait(1);
			CComPtr<IHTMLElement> active_wait_element;
			if (document->get_activeElement(&active_wait_element) == S_OK) {
				CComQIPtr<IHTMLElement2> active_wait_element2(active_wait_element);
				if (element2.IsEqualObject(active_wait_element2)) {
					this->SetInsertionPoint(element);
					has_focus = true;
					break;
				}
			}
		}

		if (!has_focus) {
			cout << "We don't have focus on element." << endl;
		}

		return has_focus;
	}

	bool SendKeysCommandHandler::SetInsertionPoint(IHTMLElement* element) {
		CComPtr<IHTMLTxtRange> range;
		CComQIPtr<IHTMLInputTextElement> input_element(element);
		if (input_element) {
			input_element->createTextRange(&range);
		} else {
			CComQIPtr<IHTMLTextAreaElement> text_area_element(element);
			if (text_area_element) {
				text_area_element->createTextRange(&range);
			}
		}

		if (range) {
			range->collapse(VARIANT_FALSE);
			range->select();
			return true;
		}

		return false;
	}
};

} // namespace webdriver

#endif // WEBDRIVER_IE_SENDKEYSCOMMANDHANDLER_H_
