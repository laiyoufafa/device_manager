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

#include "UTTest_device_manager_service_listener.h"

#include <memory>

#include "dm_anonymous.h"
#include "dm_constants.h"
#include "dm_log.h"
#include "ipc_notify_auth_result_req.h"
#include "ipc_notify_device_found_req.h"
#include "ipc_notify_device_state_req.h"
#include "ipc_notify_discover_result_req.h"
#include "ipc_notify_verify_auth_result_req.h"

namespace OHOS {
namespace DistributedHardware {
void DeviceManagerServiceListenerTest::SetUp()
{
}
void DeviceManagerServiceListenerTest::TearDown()
{
}
void DeviceManagerServiceListenerTest::SetUpTestCase()
{
}
void DeviceManagerServiceListenerTest::TearDownTestCase()
{
}

namespace {
/**
 * @tc.name: OnDeviceStateChange_001
 * @tc.desc: OnDeviceStateChange, construct a dummy listener, pass in pkgName, use the constructed listener to get
 * deviceTypeId
 * @tc.type: FUNC
 * @tc.require: AR000GHSJK
 */
HWTEST_F(DeviceManagerServiceListenerTest, OnDeviceStateChange_001, testing::ext::TestSize.Level0)
{
    std::shared_ptr<DeviceManagerServiceListener> listener_ = std::make_shared<DeviceManagerServiceListener>();
    std::string pkgName = "com.ohos.helloworld";
    DmDeviceState state = DEVICE_STATE_ONLINE;
    DmDeviceInfo info = {
        .deviceId = "asdad",
        .deviceName = "asda",
        .deviceTypeId = 1,
    };
    listener_->OnDeviceStateChange(pkgName, state, info);
    std::shared_ptr<IpcNotifyDeviceStateReq> pReq =
        std::static_pointer_cast<IpcNotifyDeviceStateReq>(listener_->ipcServerListener_.req_);
    int32_t dmState = pReq->GetDeviceState();
    EXPECT_EQ(1, dmState);
}

/**
 * @tc.name: OnAuthResult_001
 * @tc.desc:OnAuthResult, construct a dummy listener, pass in pkgName, use the constructed listener to get pkgName
 * @tc.type: FUNC
 * @tc.require: AR000GHSJK
 */
HWTEST_F(DeviceManagerServiceListenerTest, OnAuthResult_001, testing::ext::TestSize.Level0)
{
    std::shared_ptr<DeviceManagerServiceListener> listener_ = std::make_shared<DeviceManagerServiceListener>();
    std::string pkgName = "com.ohos.helloworld";
    std::string deviceId = "dkdkd";
    std::string token = "kdkddk";
    int32_t status = 3;
    std::string reason = "kddk";
    listener_->OnAuthResult(pkgName, deviceId, token, status, reason);
    std::shared_ptr<IpcNotifyAuthResultReq> pReq =
        std::static_pointer_cast<IpcNotifyAuthResultReq>(listener_->ipcServerListener_.req_);
    std ::string ret = pReq->GetPkgName();
    EXPECT_EQ(ret, pkgName);
}

/**
 * @tc.name: OnVerifyAuthResult_001
 * @tc.desc: OnVerifyAuthResult,construct a dummy listener, pass in pkgName, use the constructed listener to get
 * deviceId
 * @tc.type: FUNC
 * @tc.require: AR000GHSJK
 */
HWTEST_F(DeviceManagerServiceListenerTest, OnVerifyAuthResult_001, testing::ext::TestSize.Level0)
{
    std::shared_ptr<DeviceManagerServiceListener> listener_ = std::make_shared<DeviceManagerServiceListener>();
    std::string pkgName = "com.ohos.helloworld";
    std::string deviceId = "dkdkd";
    int32_t resultCode = 1;
    std::string flag = "true";
    listener_->OnVerifyAuthResult(pkgName, deviceId, resultCode, flag);
    std::shared_ptr<IpcNotifyVerifyAuthResultReq> pReq =
        std::static_pointer_cast<IpcNotifyVerifyAuthResultReq>(listener_->ipcServerListener_.req_);
    std ::string ret = pReq->GetDeviceId();
    EXPECT_EQ(ret, deviceId);
}
} // namespace
} // namespace DistributedHardware
} // namespace OHOS