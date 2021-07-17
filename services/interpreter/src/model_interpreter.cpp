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

#include "model_interpreter.h"

#include <iostream>

#include "aie_log.h"
#include "infer_wrapper_factory.h"

using namespace OHOS::AI;

namespace OHOS {
namespace AI {
namespace dllite {
ModelInterpreter::ModelInterpreter(const ModelConfig &modelConfig)
    : isLoad_(false), modelConfig_(modelConfig), inferWrapper_(nullptr), wrapperHandle_(nullptr)
{
}

ModelInterpreter::~ModelInterpreter() = default;

ReturnCode ModelInterpreter::Init()
{
    InferFramework *inferPtr = InferWrapperFactory::CreateWrapper(modelConfig_, wrapperHandle_);
    if (inferPtr == nullptr) {
        HILOGE("get wrapper failed");

        wrapperHandle_ = nullptr;
        return ReturnCode::UNKNOWN;
    }

    inferWrapper_.reset(inferPtr);

    return ReturnCode::SUCCESS;
}

ReturnCode ModelInterpreter::Term()
{
    inferWrapper_.reset();

    ReturnCode rtn = InferWrapperFactory::DestroyWrapper(wrapperHandle_);
    if (rtn != ReturnCode::SUCCESS) {
        HILOGE("Failed to destroy wrapper"); // Allow this error, do not return.
    }

    wrapperHandle_ = nullptr;

    return ReturnCode::SUCCESS;
}

ReturnCode ModelInterpreter::Load()
{
    if (isLoad_) {
        HILOGE("Load() has been executed [LOAD_REPEATED]");
        return ReturnCode::LOAD_REPEATED;
    }

    if (inferWrapper_.get() == nullptr) {
        HILOGE("inferWrapper_.get() [INVALID_POINTER]");
        return ReturnCode::INVALID_POINTER;
    }

    ReturnCode returnCode = inferWrapper_->Load();
    if (returnCode != ReturnCode::SUCCESS) {
        HILOGE("inferWrapper_->Load() [FAIL] returnCode:%d", (int)returnCode);
        return returnCode;
    }

    isLoad_ = true;

    return ReturnCode::SUCCESS;
}

ReturnCode ModelInterpreter::Invoke(const std::vector<IOTensor> &inputs, std::vector<IOTensor> &outputs) const
{
    if (isLoad_ == false) {
        HILOGE("Load has not been executed [LOAD_NOT_EXECUTED]");
        return ReturnCode::LOAD_NOT_EXECUTED;
    }

    if (inferWrapper_.get() == nullptr) {
        HILOGE("inferWrapper_.get() == nullptr [INVALID_POINTER]");
        return ReturnCode::INVALID_POINTER;
    }

    ReturnCode returnCode = inferWrapper_->Invoke(inputs, outputs);
    if (returnCode != ReturnCode::SUCCESS) {
        HILOGE("inferWrapper_->Invoke(inputs, outputs) [FAIL] returnCode:%d", (int)returnCode);
    }

    return returnCode;
}

ReturnCode ModelInterpreter::Unload()
{
    if (isLoad_ == false) {
        HILOGE("Load() has not been executed [UNLOAD_REPEATED]");
        return ReturnCode::UNLOAD_REPEATED;
    }

    if (inferWrapper_.get() == nullptr) {
        HILOGE("inferWrapper_.get() == nullptr [INVALID_POINTER]");
        return ReturnCode::INVALID_POINTER;
    }

    ReturnCode returnCode = inferWrapper_->Unload();
    if (returnCode != ReturnCode::SUCCESS) {
        HILOGE("inferWrapper_->Unload() [FAIL] returnCode:%d", (int)returnCode);
        return returnCode;
    }

    isLoad_ = false;

    return ReturnCode::SUCCESS;
}

ReturnCode ModelInterpreter::CreateTensors(std::vector<IOTensor> &tensors, IOFlag flag)
{
    if (!isLoad_) {
        HILOGE("Model is not loaded [LOAD_NOT_EXECUTED]");
        return ReturnCode::LOAD_NOT_EXECUTED;
    }

    tensors.clear();

    if (inferWrapper_ == nullptr) {
        HILOGE("inferWrapper_.get() [INVALID_POINTER]");
        return ReturnCode::INVALID_POINTER;
    }

    ReturnCode returnCode = ReturnCode::UNKNOWN;
    if (flag == IOFlag::INPUT) {
        returnCode = inferWrapper_->CreateInputBuffers(tensors);
    } else if (flag == IOFlag::OUTPUT) {
        returnCode = inferWrapper_->CreateOutputBuffers(tensors);
    } else {
        returnCode = ReturnCode::INVALID_PARAM;
    }

    return returnCode;
}

ReturnCode ModelInterpreter::DestroyTensors(std::vector<IOTensor> &tensors)
{
    ReturnCode returnCode = ReturnCode::UNKNOWN;

    if (!isLoad_) {
        HILOGE("model is not loaded [LOAD_NOT_EXECUTED]");
        return ReturnCode::LOAD_NOT_EXECUTED;
    }

    returnCode = inferWrapper_->DestroyIOBuffers(tensors);

    return returnCode;
}

ReturnCode ModelInterpreter::GetTensors(std::vector<IOTensor> &tensors, IOFlag flag) const
{
    if (inferWrapper_.get() == nullptr) {
        HILOGE("inferWrapper_.get() == nullptr [INVALID_POINTER]");
        return ReturnCode::INVALID_POINTER;
    }

    ReturnCode returnCode = ReturnCode::UNKNOWN;
    if (flag == IOFlag::INPUT) {
        std::cout << "get input buffer" << std::endl;
        returnCode = inferWrapper_->GetInputBuffers(tensors);
    } else if (flag == IOFlag::OUTPUT) {
        returnCode = inferWrapper_->GetOutputBuffers(tensors);
    } else {
        returnCode = ReturnCode::INVALID_PARAM;
    }

    return returnCode;
}
} // namespace dllite
} // namespace AI
} // namespace OHOS
