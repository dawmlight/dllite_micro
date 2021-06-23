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

#ifndef MODEL_CONFIG_H
#define MODEL_CONFIG_H

#include <map>
#include <memory>
#include <utility>
#include <vector>

#include "type_define.h"

namespace OHOS {
namespace AI {
namespace dllite {
const int MAX_STRING_LENGTH = 128;
const int MAX_PATH_LENGTH = 256;
const size_t MAX_MODEL_SIZE = 300 * 1024; // 300KB

const int32 UINT8_ENUM = 0;
const int32 INT8_ENUM = 1;
const int32 INT16_ENUM = 2;
const int32 UINT32_ENUM = 3;
const int32 INT32_ENUM = 4;
const int32 FP16_ENUM = 5;
const int32 FP32_ENUM = 6;
const int32 FLOAT_ENUM = 7;
const int32 FLOAT16_ENUM = 8;
const int32 INT64_ENUM = 9;
const int32 UINT16_ENUM = 10;

// Tensor type
enum class TensorType {
    FLOAT = FLOAT_ENUM,
    FLOAT16 = FLOAT16_ENUM,
    INT8 = INT8_ENUM,
    INT32 = INT32_ENUM,
    UINT8 = UINT8_ENUM,
    INT16 = INT16_ENUM,
    UINT32 = UINT32_ENUM,
    INT64 = INT64_ENUM,
    UINT16 = UINT16_ENUM,
};

// Tensor layout
const int32 NONE_ENUM = -1;
const int32 NCHW_ENUM = 0;
const int32 NHWC_ENUM = 1;
const int32 NCHWC8_ENUM = 2;
const int32 ROW_MAJOR_ENUM = 3;
const int32 LSTM_MTK_ENUM = 4;
const int32 HWKC_ENUM = 5;
const int32 HWCK_ENUM = 6;
const int32 KCHW_ENUM = 7;
const int32 CKHW_ENUM = 8;
const int32 KHWC_ENUM = 9;
const int32 CHWK_ENUM = 10;
const int32 HC4HW4_ENUM = 11;

enum class TensorLayout {
    NONE = NONE_ENUM,
    NCHW = NCHW_ENUM,
    NHWC = NHWC_ENUM,
    HWKC = HWKC_ENUM,
    HWCK = HWCK_ENUM,
    KCHW = KCHW_ENUM,
    CKHW = CKHW_ENUM,
    KHWC = KHWC_ENUM,
    CHWK = CHWK_ENUM,
    NC4HW4 = HC4HW4_ENUM,
    NCHWC8 = NCHWC8_ENUM,
    ROW_MAJOR = ROW_MAJOR_ENUM,
    LSTM_MTK = LSTM_MTK_ENUM,
};

struct IOTensor {
    std::string name;
    TensorType type;
    TensorLayout layout;
    std::vector<size_t> shape;
    std::pair<void *, size_t> buffer;
};

const int32 INFER_ENUM = -1;
const int32 MINDSPORE_ENUM = 0;

enum class InferFrameworkType {
    INFER = INFER_ENUM,
    MINDSPORE = MINDSPORE_ENUM,
};

class ModelConfig {
public:
    ModelConfig();
    ~ModelConfig();

    /**
     * Check model config valid.
     *
     * @return Return the return code of function execution.
     */
    ReturnCode CheckModelConfig() const;

public:
    std::string modelName_;
    std::string modelPath_;
    std::string weightPath_;
    bool weightSeparateFlag_;
    InferFrameworkType inferFrameworkType_;
};
} // namespace dllite
} // namespace AI
} // namespace OHOS

#endif // MODEL_CONFIG_H
