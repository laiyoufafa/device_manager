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

#ifndef OHOS_DM_IPC_STOP_DISCOVERY_REQ_H
#define OHOS_DM_IPC_STOP_DISCOVERY_REQ_H

#include <cstdint>

#include "ipc_req.h"

namespace OHOS {
namespace DistributedHardware {
class IpcStopDiscoveryReq : public IpcReq {
    DECLARE_IPC_MODEL(IpcStopDiscoveryReq);

public:
    /**
     * @tc.name: IpcStopDiscoveryReq::GetSubscribeId
     * @tc.desc: Ipc stop discovery request get subscription id
     * @tc.type: FUNC
     */
    uint16_t GetSubscribeId() const
    {
        return subscribeId_;
    }

    /**
     * @tc.name: IpcStopDiscoveryReq::SetSubscribeId
     * @tc.desc: Ipc stop discovery request set subscription id
     * @tc.type: FUNC
     */
    void SetSubscribeId(uint16_t subscribeId)
    {
        subscribeId_ = subscribeId;
    }

private:
    uint16_t subscribeId_ { 0 };
};
} // namespace DistributedHardware
} // namespace OHOS
#endif // OHOS_DM_IPC_STOP_DISCOVERY_REQ_H
