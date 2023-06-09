/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
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

#ifndef OHOS_DM_IPC_GET_TRUST_DEVICE_RSP_H
#define OHOS_DM_IPC_GET_TRUST_DEVICE_RSP_H

#include <vector>

#include "dm_device_info.h"
#include "ipc_rsp.h"

namespace OHOS {
namespace DistributedHardware {
class IpcGetTrustDeviceRsp : public IpcRsp {
    DECLARE_IPC_MODEL(IpcGetTrustDeviceRsp);

public:
    /**
     * @tc.name: IpcGetTrustDeviceRsp::GetDeviceVec
     * @tc.desc: Get DeviceVec of the Ipc Get Trust Device Response
     * @tc.type: FUNC
     */
    std::vector<DmDeviceInfo> GetDeviceVec() const
    {
        return deviceVec_;
    }

    /**
     * @tc.name: IpcGetTrustDeviceRsp::SetDeviceVec
     * @tc.desc: Set DeviceVec of the Ipc Get Trust Device Response
     * @tc.type: FUNC
     */
    void SetDeviceVec(std::vector<DmDeviceInfo> &deviceVec)
    {
        deviceVec_ = deviceVec;
    }

private:
    std::vector<DmDeviceInfo> deviceVec_;
};
} // namespace DistributedHardware
} // namespace OHOS
#endif // OHOS_DM_IPC_GET_TRUST_DEVICE_RSP_H
