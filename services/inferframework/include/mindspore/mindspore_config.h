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

#ifndef MINDSPORE_CONFIG_H
#define MINDSPORE_CONFIG_H

#include "model_config.h"

namespace OHOS {
namespace AI {
namespace dllite {
class MindsporeConfig {
public:
    MindsporeConfig() = default;
    ~MindsporeConfig() = default;
    ReturnCode SetRawConfig(const dllite::ModelConfig &modelConfig);

public:
    std::string modelPath_;
    std::string modelName_;
    std::string weightPath_;
    bool weightSeparateFlag_ = false;
};
} // namespace dllite
} // namespace AI
} // namespace OHOS

#endif // MINDSPORE_CONFIG_H