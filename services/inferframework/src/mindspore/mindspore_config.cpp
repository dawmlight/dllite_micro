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

#include "mindspore_config.h"

namespace OHOS {
namespace AI {
namespace dllite {
/**
 * Set the inference information.
 *
 * @param [in] modelConfig model config for wrapper
 * @return return the return code of function execution.
 */
ReturnCode MindsporeConfig::SetRawConfig(const dllite::ModelConfig &modelConfig)
{
    modelPath_ = modelConfig.modelPath_;
    weightPath_ = modelConfig.weightPath_;
    weightSeparateFlag_ = modelConfig.weightSeparateFlag_;
    return ReturnCode::SUCCESS;
}
} // namespace dllite
} // namespace AI
} // namespace OHOS
