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

#include "StdAfx.h"
#include "IESession.h"
#include "IESessionWindow.h"
#include "logging.h"

namespace webdriver {

IESession::IESession(int port) : Session(port) {
}


IESession::~IESession(void) {
}

std::wstring IESession::Initialize(void) {
	unsigned int thread_id = 0;
	HWND session_window_handle = NULL;
	HANDLE event_handle = ::CreateEvent(NULL, TRUE, FALSE, EVENT_NAME);
	HANDLE thread_handle = reinterpret_cast<HANDLE>(_beginthreadex(NULL, 0, &IESessionWindow::ThreadProc, reinterpret_cast<void*>(&session_window_handle), 0, &thread_id));
	if (event_handle != NULL) {
		::WaitForSingleObject(event_handle, INFINITE);
		::CloseHandle(event_handle);
	}

	if (thread_handle != NULL) {
		::CloseHandle(thread_handle);
	}

	::SendMessage(session_window_handle, WD_INIT, static_cast<WPARAM>(this->port()), NULL);

	vector<TCHAR> window_text_buffer(37);
	::GetWindowText(session_window_handle, &window_text_buffer[0], 37);
	std::wstring session_id = &window_text_buffer[0];

	this->session_window_handle_ = session_window_handle;
	return session_id;
}

void IESession::ShutDown(void) {
	DWORD process_id;
	DWORD thread_id = ::GetWindowThreadProcessId(this->session_window_handle_, &process_id);
	HANDLE thread_handle = ::OpenThread(SYNCHRONIZE, FALSE, thread_id);
	::SendMessage(this->session_window_handle_, WM_CLOSE, NULL, NULL);
	if (thread_handle != NULL) {
		DWORD wait_result = ::WaitForSingleObject(thread_handle, 30000);
		if (wait_result != WAIT_OBJECT_0) {
			LOG(DEBUG) << "Waiting for thread to end returned " << wait_result;
		}
		::CloseHandle(thread_handle);
	}
}

bool IESession::ExecuteCommand(const std::wstring& serialized_command, std::wstring* serialized_response) {
	// Sending a command consists of five actions:
	// 1. Setting the command to be executed
	// 2. Executing the command
	// 3. Waiting for the response to be populated
	// 4. Retrieving the response
	// 5. Retrieving whether the command sent caused the session to be ready for shutdown
	::SendMessage(this->session_window_handle_, WD_SET_COMMAND, NULL, reinterpret_cast<LPARAM>(serialized_command.c_str()));
	::PostMessage(this->session_window_handle_, WD_EXEC_COMMAND, NULL, NULL);
	
	int response_length = static_cast<int>(::SendMessage(this->session_window_handle_, WD_GET_RESPONSE_LENGTH, NULL, NULL));
	while (response_length == 0) {
		// Sleep a short time to prevent thread starvation on single-core machines.
		::Sleep(10);
		response_length = static_cast<int>(::SendMessage(this->session_window_handle_, WD_GET_RESPONSE_LENGTH, NULL, NULL));
	}

	// Must add one to the length to handle the terminating character.
	std::vector<TCHAR> response_buffer(response_length + 1);
	::SendMessage(this->session_window_handle_, WD_GET_RESPONSE, NULL, reinterpret_cast<LPARAM>(&response_buffer[0]));
	*serialized_response = &response_buffer[0];
	bool session_is_valid = ::SendMessage(this->session_window_handle_, WD_IS_SESSION_VALID, NULL, NULL) != 0;
	return session_is_valid;
}

}
