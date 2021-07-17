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

#ifndef MODEL_INTERPRETER_H
#define MODEL_INTERPRETER_H

#include "model_config.h"

namespace OHOS {
namespace AI {
namespace dllite {
class InferFramework;

enum class IOFlag {
    INPUT,
    OUTPUT,
};

class ModelInterpreter {
public:
    ModelInterpreter(const ModelConfig &modelConfig);
    ~ModelInterpreter();

    /**
     * Load the modelInterpreter.
     *
     * @return Return the return code of function execution.
     */
    ReturnCode Load();

    /**
     * Invoke the model inference.
     *
     * @return Return the return code of function execution.
     */
    ReturnCode Invoke(const std::vector<IOTensor> &inputs, std::vector<IOTensor> &outputs) const;

    /**
     * Unload the modelInterpreter.
     *
     * @return Return the return code of function execution.
     */
    ReturnCode Unload();

    /**
     * Create the buffers of tensors of inputs or outputs.
     *
     * @param [in] tensors The vector of IOTensor which includes tensor information.
     * @param [in] flag The flag indicates inputs or outputs.
     * @return Return the return code of function execution.
     */
    ReturnCode CreateTensors(std::vector<IOTensor> &tensors, IOFlag flag);

    /**
     * Destroy the buffers of tensors of inputs or outputs.
     *
     * @param [in] tensors The vector of IOTensor which includes tensor information.
     * @return Return the return code of function execution.
     */
    ReturnCode DestroyTensors(std::vector<IOTensor> &tensors);

    /**
     * Get the tensors of inputs or outputs.
     *
     * @param [in] tensors The vector of IOTensor which includes tensor information.
     * @param [out] flag The flag indicates inputs or outputs.
     * @return Return the return code of function execution.
     */
    ReturnCode GetTensors(std::vector<IOTensor> &tensors, IOFlag flag) const;

    friend class FeatureInterpreter;

private:
    ReturnCode Init();
    ReturnCode Term();

private:
    bool isLoad_;
    ModelConfig modelConfig_;
    std::shared_ptr<dllite::InferFramework> inferWrapper_;
    void *wrapperHandle_; // The library that manages the ModelInterpreter instance dlopen
};
} // namespace dllite
} // namespace AI
} // namespace OHOS

#endif // MODEL_INTERPRETER_H
