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

#ifndef WEBDRIVER_IE_GETALLWINDOWHANDLESCOMMANDHANDLER_H_
#define WEBDRIVER_IE_GETALLWINDOWHANDLESCOMMANDHANDLER_H_

#include "Session.h"

namespace webdriver {

class GetAllWindowHandlesCommandHandler : public CommandHandler {
public:
	GetAllWindowHandlesCommandHandler(void) {
	}

	virtual ~GetAllWindowHandlesCommandHandler(void) {
	}

protected:
	void GetAllWindowHandlesCommandHandler::ExecuteInternal(const IESessionWindow& session, const LocatorMap& locator_parameters, const ParametersMap& command_parameters, Response * response) {
		Json::Value handles(Json::arrayValue);
		std::vector<std::wstring> handle_list;
		session.GetManagedBrowserHandles(&handle_list);
		for (unsigned int i = 0; i < handle_list.size(); ++i) {
			std::string handle = CW2A(handle_list[i].c_str(), CP_UTF8);
			handles.append(handle);
		}

		response->SetResponse(SUCCESS, handles);
	}
};

} // namespace webdriver

#endif // WEBDRIVER_IE_GETALLWINDOWHANDLESCOMMANDHANDLER_H_
