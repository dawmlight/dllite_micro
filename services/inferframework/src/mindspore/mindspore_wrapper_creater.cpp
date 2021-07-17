/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
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

#include "mindspore_wrapper_creater.h"

#include "aie_log.h"
#include "mindspore_wrapper.h"

using namespace OHOS::AI::dllite;

extern "C" {
    /**
     * Create Mindspore Wrapper
     *
     * @param [in] modelConfig model config for wrapper
     * @return return the pointer of wrapper
     */
    void *CreateWrapper(const void *modelConfig)
    {
        const ModelConfig *getModelConfig = reinterpret_cast<const ModelConfig*>(modelConfig);
        MindsporeWrapper *msWrapper = new (std::nothrow) MindsporeWrapper;
        if (msWrapper == nullptr) {
            HILOGE("new MindsporeWrapper fail");
            return nullptr;
        }

        ReturnCode rnt = msWrapper->Init(*getModelConfig);
        if (rnt != ReturnCode::SUCCESS) {
            HILOGE("MindsporeWrapper init fail");
            delete msWrapper;
            msWrapper = nullptr;
            return nullptr;
        }

        return static_cast<void*>(msWrapper);
    }
}
