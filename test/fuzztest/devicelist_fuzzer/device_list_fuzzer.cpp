/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <securec.h>
#include "device_manager_impl.h"
#include "device_manager.h"
#include "dm_constants.h"
#include "dm_log.h"
#include "device_manager_callback.h"
#include "dm_app_image_info.h"
#include "dm_device_info.h"
#include "dm_subscribe_info.h"
#include "device_list_fuzzer.h"

namespace OHOS {
namespace DistributedHardware {
void DeviceListFuzzTest(const uint8_t* data, size_t size)
{
    if ((data == nullptr) || (size <= 0)) {
        return;
    }

    std::string extra(reinterpret_cast<const char*>(data), size);
    std::vector<DmDeviceInfo> devList;
    std::string bundleName(reinterpret_cast<const char*>(data), size);
    DmDeviceInfo deviceInfo;

    int32_t ret = DeviceManager::GetInstance().GetTrustedDeviceList(bundleName, extra, devList);
    ret = DeviceManager::GetInstance().GetLocalDeviceInfo(bundleName, deviceInfo);
}
}
}

/* Fuzzer entry point */
extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
{
    /* Run your code on data */
    OHOS::DistributedHardware::DeviceListFuzzTest(data, size);
    return 0;
}
