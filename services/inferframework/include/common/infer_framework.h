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

#ifndef INFER_FRAMEWORK_H
#define INFER_FRAMEWORK_H

#include "model_config.h"
#include <vector>

namespace OHOS {
namespace AI {
namespace dllite {
class InferFramework {
public:
    InferFramework(){};
    virtual ~InferFramework(){};

    // Infer Framework methods
    virtual ReturnCode Load() = 0;
    virtual ReturnCode Invoke(const std::vector<IOTensor> &inputs, std::vector<IOTensor> &outputs) = 0;
    virtual ReturnCode Unload() = 0;

    // Create tensor: The buffer is created by dllite.
    virtual ReturnCode CreateInputBuffers(std::vector<IOTensor> &inputs) = 0;
    virtual ReturnCode CreateOutputBuffers(std::vector<IOTensor> &outputs) = 0;

    // Get tensor: The buffer is created by infer framework.
    virtual ReturnCode GetInputBuffers(std::vector<IOTensor> &inputs) const = 0;
    virtual ReturnCode GetOutputBuffers(std::vector<IOTensor> &outputs) const = 0;

    // Destory tensor
    virtual ReturnCode DestroyIOBuffers(std::vector<IOTensor> &tensors) = 0;
};
} // namespace dllite
} // namespace AI
} // namespace OHOS

#endif // INFER_FRAMEWORK_H
