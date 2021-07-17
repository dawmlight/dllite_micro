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

#include "model_config.h"

#include <fstream>

#include "aie_log.h"

namespace OHOS {
namespace AI {
namespace dllite {
ModelConfig::ModelConfig() : inferFrameworkType_(InferFrameworkType::INFER), weightSeparateFlag_(true) {}

ModelConfig::~ModelConfig() = default;

ReturnCode ModelConfig::CheckModelConfig() const
{
    if (modelName_.empty()) {
        HILOGE("modelName_ is empty");
        return ReturnCode::INVALID_PARAM;
    }

    if (modelName_.length() > MAX_STRING_LENGTH) {
        HILOGE("modelName_'s length is longer than %d", MAX_STRING_LENGTH);
        return ReturnCode::INVALID_PARAM;
    }

    if (modelPath_.length() > MAX_PATH_LENGTH) {
        HILOGE("modelPath_'s length is longer than %d", MAX_PATH_LENGTH);
        return ReturnCode::INVALID_PARAM;
    }

    if (weightPath_.length() > MAX_PATH_LENGTH) {
        HILOGE("weightPath_'s length is longer than %d", MAX_PATH_LENGTH);
        return ReturnCode::INVALID_PARAM;
    }

    // Judge model file exist
    std::ifstream ifs(modelPath_.c_str());
    if (!ifs.good()) {
        HILOGE("model is not exist");
        return ReturnCode::INVALID_PARAM;
    }

    // Judge model file size valid
    ifs.seekg(0, ifs.end);
    size_t modelSize = ifs.tellg();
    if (modelSize > MAX_MODEL_SIZE) {
        HILOGE("model exceed max size limit %lu", MAX_MODEL_SIZE);
        return ReturnCode::INVALID_MODEL_FILE;
    }

    if (modelSize <= 0) {
        HILOGE("model is empty");
        return ReturnCode::EMPTY_RESOURCE;
    }

    // Judge weight file exist when weight separate
    std::ifstream wfs(weightPath_.c_str());
    if (weightSeparateFlag_ && !wfs.good()) {
        HILOGE("weight is not exist");
        return ReturnCode::INVALID_PARAM;
    }

    return ReturnCode::SUCCESS;
}
} // namespace dllite
} // namespace AI
} // namespace OHOS
