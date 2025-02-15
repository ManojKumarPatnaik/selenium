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

#ifndef WEBDRIVER_IE_SETELEMENTSELECTEDCOMMANDHANDLER_H_
#define WEBDRIVER_IE_SETELEMENTSELECTEDCOMMANDHANDLER_H_

#include "Session.h"

namespace webdriver {

class SetElementSelectedCommandHandler : public CommandHandler {
public:
	SetElementSelectedCommandHandler(void) {
	}

	virtual ~SetElementSelectedCommandHandler(void) {
	}

protected:
	void SetElementSelectedCommandHandler::ExecuteInternal(const IESessionWindow& session, const LocatorMap& locator_parameters, const ParametersMap& command_parameters, Response * response) {
		LocatorMap::const_iterator id_parameter_iterator = locator_parameters.find("id");
		if (id_parameter_iterator == locator_parameters.end()) {
			response->SetErrorResponse(400, "Missing parameter in URL: id");
			return;
		} else {
			std::wstring element_id = CA2W(id_parameter_iterator->second.c_str(), CP_UTF8);

			BrowserHandle browser_wrapper;
			int status_code = session.GetCurrentBrowser(&browser_wrapper);
			if (status_code != SUCCESS) {
				response->SetErrorResponse(status_code, "Unable to get browser");
				return;
			}

			ElementHandle element_wrapper;
			status_code = this->GetElement(session, element_id, &element_wrapper);
			if (status_code == SUCCESS) {
				bool currently_selected = element_wrapper->IsSelected();

				if (!element_wrapper->IsEnabled()) {
					response->SetErrorResponse(EELEMENTNOTENABLED, "Cannot select disabled element");
					return;
				} else {
					bool displayed;
					status_code = element_wrapper->IsDisplayed(&displayed);
					if (status_code != SUCCESS || !displayed) {
						response->SetErrorResponse(EELEMENTNOTDISPLAYED, "Cannot select hidden element");
						return;
					} else {
						bool requires_native_click = false;
						CComBSTR attribute_name;
						if (element_wrapper->IsCheckBox()) {
							requires_native_click = true;
							attribute_name = L"checked";
						} else if (element_wrapper->IsRadioButton()) {
							requires_native_click = true;
							attribute_name = L"selected";
						}

						// TODO(malcolmr): Why not: if (isSelected()) return; ? Do we really need to
						// re-set 'checked=true' for checkbox and do effectively nothing for select?
						// Maybe we should check for disabled elements first?
						if (requires_native_click) {
							if (!element_wrapper->IsSelected()) {
								element_wrapper->Click();
								browser_wrapper->set_wait_required(true);
							}

							CComBSTR is_true(L"true");
							CComVariant attribute_value(is_true);
							element_wrapper->element()->setAttribute(attribute_name, attribute_value, 0);

							if (currently_selected != element_wrapper->IsSelected()) {
								CComQIPtr<IHTMLDOMNode> element_node(element_wrapper->element());
								element_wrapper->FireEvent(element_node, L"onchange");
							}
							response->SetResponse(SUCCESS, Json::Value::null);
							return;
						} else {
							CComQIPtr<IHTMLOptionElement> option(element_wrapper->element());
							if (option) {
								option->put_selected(VARIANT_TRUE);

								// Looks like we'll need to fire the event on the select element and not
								// the option. Assume for now that the parent node is a select. Which is dumb.
								CComQIPtr<IHTMLDOMNode> option_node(element_wrapper->element());
								CComPtr<IHTMLDOMNode> parent;
								option_node->get_parentNode(&parent);

								if (currently_selected != element_wrapper->IsSelected()) {
									element_wrapper->FireEvent(parent, L"onchange");
								}
								response->SetResponse(SUCCESS, Json::Value::null);
								return;
							} else {
								response->SetErrorResponse(EELEMENTNOTSELECTED, "Element type not selectable");
								return;
							}
						}
					}
				}
			} else {
				response->SetErrorResponse(status_code, "Element is no longer valid");
				return;
			}
		}
	}
};

} // namespace webdriver

#endif // WEBDRIVER_IE_SETELEMENTSELECTEDCOMMANDHANDLER_H_
