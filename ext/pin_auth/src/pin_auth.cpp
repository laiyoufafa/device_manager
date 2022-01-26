/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "pin_auth.h"

#include <memory>

#include "dm_constants.h"
#include "dm_log.h"
#include "nlohmann/json.hpp"

namespace OHOS {
namespace DistributedHardware {
const int32_t MAX_VERIFY_TIMES = 3;
PinAuth::PinAuth()
{
    LOGI("PinAuth constructor");
}

PinAuth::~PinAuth()
{
}

int32_t PinAuth::ShowAuthInfo(int32_t code)
{
    return pinAuthUi_->ShowPinDialog(code);
}

int32_t PinAuth::StartAuth(int32_t code, std::shared_ptr<DmAuthManager> authManager)
{
    return pinAuthUi_->InputPinDialog(code, authManager);
}

int32_t PinAuth::VerifyAuthentication(std::string pinToken, int32_t code, const std::string &authParam)
{
    times_ += 1;
    nlohmann::json jsonObject = nlohmann::json::parse(authParam, nullptr, false);
    if (jsonObject.is_discarded()) {
        LOGE("DecodeRequestAuth jsonStr error");
        return DM_FAILED;
    }
    if (!jsonObject.contains(PIN_CODE_KEY) && !jsonObject.contains(PIN_TOKEN)) {
        LOGE("err json string, first time");
        return DM_FAILED;
    }
    int32_t inputPinCode = jsonObject[PIN_CODE_KEY];
    int32_t inputPinToken = jsonObject[PIN_TOKEN];
    if (code == inputPinCode && stoi(pinToken) == inputPinToken) {
        return DM_OK;
    } else if (code != inputPinCode && times_ < MAX_VERIFY_TIMES) {
        return DM_AUTH_INPUT_FAILED;
    } else {
        return DM_FAILED;
    }
}

extern "C" IAuthentication *CreatePinAuthObject(void)
{
    return new PinAuth;
}
} // namespace DistributedHardware
} // namespace OHOS
