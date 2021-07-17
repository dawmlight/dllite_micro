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

#include "mindspore_wrapper.h"

#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "securec.h"
#include "utils.h"

namespace OHOS {
namespace AI {
namespace dllite {
MindsporeWrapper::MindsporeWrapper()
    : pSession_(nullptr),
      createMSSessionFuncPtr_(nullptr),
      createMSSessionWithWeightFuncPtr_(nullptr),
      destoryMSSessionFuncPtr_(nullptr)
{
}

MindsporeWrapper::~MindsporeWrapper()
{
    // Release function pointer
    createMSSessionFuncPtr_ = nullptr;
    createMSSessionWithWeightFuncPtr_ = nullptr;
    destoryMSSessionFuncPtr_ = nullptr;

    // Release modelBuffer_
    if ((modelBuffer_.first != nullptr) || (modelBuffer_.second != 0)) {
        ReleaseFile(modelBuffer_);
    }

    // Release model and Session
    if ((modelHandle_ != nullptr) || (pSession_ != nullptr)) {
        ClearModelAndSession();
    }
}

ReturnCode MindsporeWrapper::Init(const ModelConfig &modelConfig)
{
    ReturnCode rnt = modelConfig_.SetRawConfig(modelConfig);
    if (rnt != ReturnCode::SUCCESS) {
        HILOGE("set MindSpore fail");
    }

    return rnt;
}

ReturnCode MindsporeWrapper::LoadDynamicLib()
{
    if (modelConfig_.modelPath_.empty()) {
        HILOGE("modelPath is empty");
        return ReturnCode::INVALID_PARAM;
    }

    // Open dynamic library
    modelHandle_ = dlopen(modelConfig_.modelPath_.c_str(), RTLD_LAZY | RTLD_NODELETE);
    if (modelHandle_ == nullptr) {
        HILOGE("dlopen modelPath %s error, errno: %d.", modelConfig_.modelPath_.c_str(), errno);
        return ReturnCode::UNKNOWN;
    }

    // Get dynamic lib function
    ReturnCode rnt = GetLibFuncPtr();
    if (rnt != ReturnCode::SUCCESS) {
        (void)dlclose(modelHandle_);
        modelHandle_ = nullptr;
        return rnt;
    }

    return ReturnCode::SUCCESS;
}

ReturnCode MindsporeWrapper::GetLibFuncPtr()
{
    // Get pointer of CreateMSSession func
    createMSSessionFuncPtr_ = (MINDSPORE_CREATEMSSESSION_T)dlsym(modelHandle_, MINDSPORE_CREATEMSSESSION_NAME);
    if (createMSSessionFuncPtr_ == nullptr) {
        HILOGE("get CreateMSSession function error, errno: %d.", errno);
        return ReturnCode::UNKNOWN;
    }

    // Get pointer of CreateMSSessionWithWeight func
    createMSSessionWithWeightFuncPtr_ =
        (MINDSPORE_CREATEMSSESSIONWITHWEIGHT_T)dlsym(modelHandle_, MINDSPORE_CREATEMSSESSIONWITHWEIGHT_NAME);
    if (createMSSessionWithWeightFuncPtr_ == nullptr) {
        HILOGE("get CreateMSSessionWithWeight function error, errno: %d.", errno);
        return ReturnCode::UNKNOWN;
    }

    // Get pointer of DestoryMSSession func
    destoryMSSessionFuncPtr_ = (MINDSPORE_DESTROYMSSESSION_T)dlsym(modelHandle_, MINDSPORE_DESTROYMSSESSION_NAME);
    if (destoryMSSessionFuncPtr_ == nullptr) {
        HILOGE("get DestoryMSSession function error, errno: %d.", errno);
        return ReturnCode::UNKNOWN;
    }

    return ReturnCode::SUCCESS;
}

ReturnCode MindsporeWrapper::Load()
{
    ReturnCode rnt = LoadDynamicLib();
    if (rnt != ReturnCode::SUCCESS) {
        HILOGE("load dynamic library failed");
        return rnt;
    }

    // Create Session
    const mindspore::lite::Context *context = nullptr;
    if (!modelConfig_.weightSeparateFlag_) {
        pSession_ = createMSSessionFuncPtr_(context);
    } else {
        ReadFile(modelConfig_.weightPath_, modelBuffer_);
        if ((modelBuffer_.first == nullptr) || (modelBuffer_.second == 0)) {
            std::cout << "model buffer exist" << std::endl;
            HILOGE("Failed to read weight File");
            return ReturnCode::INVALID_MODEL_FILE;
        }
        pSession_ = createMSSessionWithWeightFuncPtr_(modelBuffer_.first, modelBuffer_.second, context);
    }

    rnt = GetInputsOutputsPointer();
    if (rnt != ReturnCode::SUCCESS) {
        HILOGE("Get Inputs and Outputs Pointer fail");
        ClearModelAndSession();
        return rnt;
    }

    return ReturnCode::SUCCESS;
}

ReturnCode MindsporeWrapper::GetInputsOutputsPointer()
{
    if (pSession_ == nullptr) {
        HILOGE("pSession_ is nullptr");
        return ReturnCode::INVALID_POINTER;
    }

    // init msInputs_
    msInputs_ = pSession_->GetInputs();
    if (msInputs_.size() == 0) {
        HILOGE("Failed to get inputs");
        return ReturnCode::EMPTY_RESOURCE;
    }

    // init msOutputs_
    mindspore::Vector<mindspore::String> outputTensorNames = pSession_->GetOutputTensorNames();
    if (outputTensorNames.size() == 0) {
        HILOGE("Failed to get outputTensorNames");
        return ReturnCode::EMPTY_RESOURCE;
    }
    for (const auto &name : outputTensorNames) {
        mindspore::tensor::MSTensor *output = pSession_->GetOutputByTensorName(name);
        msOutputs_.insert(std::pair<std::string, mindspore::tensor::MSTensor *>(name.c_str(), output));
    }

    return ReturnCode::SUCCESS;
}

void MindsporeWrapper::ClearModelAndSession()
{
    if (modelHandle_ != nullptr) {
        (void)dlclose(modelHandle_);
        modelHandle_ = nullptr;
    }

    if (pSession_ != nullptr) {
        destoryMSSessionFuncPtr_(pSession_);
        pSession_ = nullptr;
    }
}

ReturnCode MindsporeWrapper::CheckInvokePara(const std::vector<IOTensor> &inputs, const std::vector<IOTensor> &outputs)
{
    if (pSession_ == nullptr) {
        HILOGE("m_pSession is nullptr");
        return ReturnCode::INVALID_POINTER;
    }

    if (inputs.empty()) {
        HILOGE("IOTensor inputs is empty");
        return ReturnCode::INVALID_PARAM;
    }

    // Check inputs size
    if (inputs.size() != msInputs_.size()) {
        HILOGE("MindsporeWrapper::Invoke, inputs.size() != msInputs_.size()");
        return ReturnCode::INVALID_PARAM;
    }

    // Check outputs size
    if (outputs.size() != msOutputs_.size()) {
        HILOGE("MindsporeWrapper::Invoke, outputs.size() != msOutputs_.size()");
        return ReturnCode::INVALID_PARAM;
    }

    // check inputs buffer
    const size_t inputLen = inputs.size();
    for (size_t i = 0; i < inputLen; ++i) {
        if (inputs[i].buffer.first == nullptr || inputs[i].buffer.second == 0) {
            HILOGE("inputs buffer is nullptr or inputs buffer size is 0, error.");
            return ReturnCode::INVALID_PARAM;
        }
    }

    return ReturnCode::SUCCESS;
}

ReturnCode MindsporeWrapper::Invoke(const std::vector<IOTensor> &inputs, std::vector<IOTensor> &outputs)
{
    if (pSession_ == nullptr) {
        HILOGE("pSession_ is nullptr");
        return ReturnCode::INVALID_POINTER;
    }

    ReturnCode rnt = CheckInvokePara(inputs, outputs);
    if (rnt != ReturnCode::SUCCESS) {
        HILOGE("InvokePara is invalid");
        return rnt;
    }

    size_t inputs_num = inputs.size();
    for (size_t inputIndex = 0; inputIndex < inputs_num; ++inputIndex) {
        void *inputData = msInputs_[inputIndex]->MutableData();
        size_t inputDataSize = msInputs_[inputIndex]->Size();
        memcpy_s(inputData, inputDataSize, inputs[inputIndex].buffer.first, inputs[inputIndex].buffer.second);
    }

    // Run Graph
    pSession_->RunGraph();

    return ReturnCode::SUCCESS;
}

ReturnCode MindsporeWrapper::Unload()
{
    if (modelHandle_ == nullptr) {
        HILOGE("modelHandle_ is nullptr");
        return ReturnCode::INVALID_POINTER;
    }

    // Close model dynamic library
    int rnt = dlclose(modelHandle_);
    if (rnt != 0) {
        HILOGE("Failed to close lib, errno: %d", errno);
        return ReturnCode::UNKNOWN;
    }
    modelHandle_ = nullptr;

    // Release modelBuffer_
    if ((modelBuffer_.first != nullptr) || (modelBuffer_.second != 0)) {
        ReleaseFile(modelBuffer_);
    }

    // Release model and Session
    if ((modelHandle_ != nullptr) || (pSession_ != nullptr)) {
        ClearModelAndSession();
    }

    return ReturnCode::SUCCESS;
}

int MindsporeWrapper::DataTypeSize(const mindspore::TypeId &dataType) const
{
    int rnt = FLOAT32_SIZE;
    switch (dataType) {
        case mindspore::kNumberTypeFloat: {
            rnt = FLOAT32_SIZE;
            break;
        }
        case mindspore::kNumberTypeFloat16: {
            rnt = FLOAT16_SIZE;
            break;
        }
        case mindspore::kNumberTypeInt8: {
            rnt = INT8_SIZE;
            break;
        }
        case mindspore::kNumberTypeUInt8: {
            rnt = UINT8_SIZE;
            break;
        }
        case mindspore::kNumberTypeInt16: {
            rnt = INT16_SIZE;
            break;
        }
        case mindspore::kNumberTypeUInt16: {
            rnt = UINT16_SIZE;
            break;
        }
        case mindspore::kNumberTypeInt32: {
            rnt = INT32_SIZE;
            break;
        }
        case mindspore::kNumberTypeUInt32: {
            rnt = UINT32_SIZE;
            break;
        }
        case mindspore::kNumberTypeInt64: {
            rnt = INT64_SIZE;
            break;
        }
        case mindspore::kNumberTypeUInt64: {
            rnt = UINT64_SIZE;
            break;
        }
        default: {
            rnt = FLOAT32_SIZE;
            break;
        }
    }

    return rnt;
}

void MindsporeWrapper::SetIOTensor(const mindspore::tensor::MSTensor *msTensor, IOTensor &tensor) const
{
    // Set tensor name
    tensor.name = msTensor->tensor_name().c_str();

    // Set tensor shape
    SetTensorShape(msTensor, tensor);

    // Set tensor type
    SetTensorType(msTensor, tensor);

    // Set tensor buffer
    SetTensorBuffer(msTensor, tensor);
}

void MindsporeWrapper::SetTensorShape(const mindspore::tensor::MSTensor *msTensor, IOTensor &tensor) const
{
    mindspore::Vector<int> msShape = msTensor->shape();

    for (size_t i = 0; i < msShape.size(); ++i) {
        tensor.shape.push_back(static_cast<size_t>(msShape[i]));
    }
}

void MindsporeWrapper::SetTensorType(const mindspore::tensor::MSTensor *msTensor, IOTensor &tensor) const
{
    mindspore::TypeId typeId = msTensor->data_type();
    switch (typeId) {
        case mindspore::kNumberTypeFloat: {
            tensor.type = TensorType::FLOAT;
            break;
        }
        case mindspore::kNumberTypeFloat16: {
            tensor.type = TensorType::FLOAT16;
            break;
        }
        case mindspore::kNumberTypeInt8: {
            tensor.type = TensorType::INT8;
            break;
        }
        case mindspore::kNumberTypeUInt8: {
            tensor.type = TensorType::UINT8;
            break;
        }
        case mindspore::kNumberTypeInt16: {
            tensor.type = TensorType::INT16;
            break;
        }
        case mindspore::kNumberTypeUInt16: {
            tensor.type = TensorType::UINT16;
            break;
        }
        case mindspore::kNumberTypeInt32: {
            tensor.type = TensorType::INT32;
            break;
        }
        case mindspore::kNumberTypeUInt32: {
            tensor.type = TensorType::UINT32;
            break;
        }
        case mindspore::kNumberTypeInt64: {
            tensor.type = TensorType::INT64;
            break;
        }
        default: {
            tensor.type = TensorType::FLOAT;
            break;
        }
    }
}

void MindsporeWrapper::SetTensorBuffer(const mindspore::tensor::MSTensor *msTensor, IOTensor &tensor) const
{
    int tensorSize = 1;
    mindspore::Vector<int> msShape = msTensor->shape();
    const size_t ndim = msShape.size();
    for (size_t dim = 0; dim < ndim; ++dim) {
        tensorSize *= msShape[dim];
    }

    mindspore::tensor::MSTensor *msNonConstTensor = const_cast<mindspore::tensor::MSTensor *>(msTensor);
    tensor.buffer.first = msNonConstTensor->data();
    tensor.buffer.second = static_cast<size_t>(tensorSize * DataTypeSize(msTensor->data_type()));
}

ReturnCode MindsporeWrapper::GetInputBuffers(std::vector<IOTensor> &inputs) const
{
    if (pSession_ == nullptr) {
        HILOGE("pSession_ is nullptr");
        return ReturnCode::INVALID_POINTER;
    }

    inputs.clear();

    // MS GetInputs
    mindspore::Vector<mindspore::tensor::MSTensor *> msInputs = pSession_->GetInputs();
    inputs.resize(msInputs.size());
    for (size_t i = 0; i < msInputs.size(); ++i) {
        const mindspore::tensor::MSTensor *msTensor = const_cast<const mindspore::tensor::MSTensor *>(msInputs[i]);
        SetIOTensor(msTensor, inputs[i]);
    }

    return ReturnCode::SUCCESS;
}

ReturnCode MindsporeWrapper::GetOutputBuffers(std::vector<IOTensor> &outputs) const
{
    if (pSession_ == nullptr) {
        HILOGE("pSession_ is nullptr");
        return ReturnCode::INVALID_POINTER;
    }

    outputs.clear();

    // MS GetOutputs
    mindspore::Vector<mindspore::String> outputsName = pSession_->GetOutputTensorNames();
    outputs.resize(outputsName.size());
    mindspore::tensor::MSTensor *msOutput = nullptr;
    for (size_t i = 0; i < outputsName.size(); ++i) {
        msOutput = pSession_->GetOutputByTensorName(outputsName[i]);
        const mindspore::tensor::MSTensor *msTensor = const_cast<const mindspore::tensor::MSTensor *>(msOutput);
        SetIOTensor(msTensor, outputs[i]);
    }
    msOutput = nullptr;

    return ReturnCode::SUCCESS;
}

ReturnCode MindsporeWrapper::CreateInputBuffers(std::vector<IOTensor> &tensors)
{
    return ReturnCode::UNSUPPORTED_API;
}

ReturnCode MindsporeWrapper::CreateOutputBuffers(std::vector<IOTensor> &tensors)
{
    return ReturnCode::UNSUPPORTED_API;
}

ReturnCode MindsporeWrapper::DestroyIOBuffers(std::vector<IOTensor> &tensors)
{
    return ReturnCode::SUCCESS;
}
} // namespace dllite
} // namespace AI
} // namespace OHOS
