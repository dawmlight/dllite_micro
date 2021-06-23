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

#ifndef MINDSPORE_WRAPPER_H
#define MINDSPORE_WRAPPER_H

#include <algorithm>
#include <dlfcn.h>
#include <map>
#include <vector>

#include "aie_log.h"
#include "infer_framework.h"
#include "lite_session.h"
#include "mindspore_config.h"

namespace OHOS {
namespace AI {
namespace dllite {
// Framework function type
using MINDSPORE_CREATEMSSESSION_T = mindspore::session::LiteSession *(*)(const mindspore::lite::Context *);
using MINDSPORE_CREATEMSSESSIONWITHWEIGHT_T = mindspore::session::LiteSession *(*)(const char *,
                                                                                   size_t,
                                                                                   const mindspore::lite::Context *);
using MINDSPORE_DESTROYMSSESSION_T = void (*)(mindspore::session::LiteSession *);

// Framework function name
const char *const MINDSPORE_CREATEMSSESSION_NAME = "CreateMSSession";
const char *const MINDSPORE_CREATEMSSESSIONWITHWEIGHT_NAME = "CreateMSSessionWithWeight";
const char *const MINDSPORE_DESTROYMSSESSION_NAME = "DestroyMSSession";

const int FLOAT32_SIZE = 4;
const int FLOAT16_SIZE = 2;
const int INT8_SIZE = 1;
const int UINT8_SIZE = 1;
const int INT16_SIZE = 2;
const int UINT16_SIZE = 2;
const int INT32_SIZE = 4;
const int UINT32_SIZE = 4;
const int INT64_SIZE = 8;
const int UINT64_SIZE = 8;

class MindsporeWrapper : public InferFramework {
public:
    MindsporeWrapper();
    virtual ~MindsporeWrapper();

    virtual ReturnCode Init(const ModelConfig &modelConfig);

    // Common methods
    virtual ReturnCode Load() override;
    virtual ReturnCode Invoke(const std::vector<IOTensor> &inputs, std::vector<IOTensor> &outputs) override;
    virtual ReturnCode Unload() override;

    // Memory methods
    virtual ReturnCode GetInputBuffers(std::vector<IOTensor> &inputs) const override;
    virtual ReturnCode GetOutputBuffers(std::vector<IOTensor> &outputs) const override;

    // Unsupported
    virtual ReturnCode CreateInputBuffers(std::vector<IOTensor> &inputs) override;
    virtual ReturnCode CreateOutputBuffers(std::vector<IOTensor> &outputs) override;
    virtual ReturnCode DestroyIOBuffers(std::vector<IOTensor> &tensors) override;

protected:
    ReturnCode LoadDynamicLib();
    ReturnCode GetLibFuncPtr();
    ReturnCode CheckInvokePara(const std::vector<IOTensor> &inputs, const std::vector<IOTensor> &outputs);
    ReturnCode GetInputsOutputsPointer();
    void ClearModelAndSession();
    void SetIOTensor(const mindspore::tensor::MSTensor *msTensor, IOTensor &tensor) const;
    void SetTensorShape(const mindspore::tensor::MSTensor *msTensor, IOTensor &tensor) const;
    void SetTensorType(const mindspore::tensor::MSTensor *msTensor, IOTensor &tensor) const;
    void SetTensorBuffer(const mindspore::tensor::MSTensor *msTensor, IOTensor &tensor) const;
    int DataTypeSize(const mindspore::TypeId &dataType) const;

protected:
    MindsporeConfig modelConfig_;
    std::pair<char *, size_t> modelBuffer_;
    mindspore::session::LiteSession *pSession_;
    mindspore::Vector<mindspore::tensor::MSTensor *> msInputs_;
    std::map<std::string, mindspore::tensor::MSTensor *> msOutputs_;

    // Dynamic link library handle
    void *modelHandle_;

    // Function pointer
    MINDSPORE_CREATEMSSESSION_T createMSSessionFuncPtr_;                     // Mindspore CreateMSSession
    MINDSPORE_CREATEMSSESSIONWITHWEIGHT_T createMSSessionWithWeightFuncPtr_; // Mindspore CreateMSSessonWithWeight
    MINDSPORE_DESTROYMSSESSION_T destoryMSSessionFuncPtr_;                   // Mindspore DestoryMSSession
};
} // namespace dllite
} // namespace AI
} // namespace OHOS

#endif // MINDSPORE_WRAPPER_H
