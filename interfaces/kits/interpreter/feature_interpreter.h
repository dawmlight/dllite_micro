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

#ifndef FEATURE_INTERPRETER_H
#define FEATURE_INTERPRETER_H

#include <mutex>

#include "model_interpreter.h"

namespace OHOS {
namespace AI {
namespace dllite {
class FeatureInterpreter;

struct VersionInfo {
    std::string version;
    std::vector<std::string> frameworkInfos;
};

struct FrameworkInfo {
    std::string version; // Framework version
    std::string option;  // Framework name
};

struct FeatureConfig {
    std::string featureName;
};

const size_t MAX_FEATURE_NUM = 8;
const size_t MAX_MODEL_NUM = 16;
static std::map<std::string, std::shared_ptr<FeatureInterpreter>> featureInterpreterMapTable;

class FeatureInterpreter {
public:
    FeatureInterpreter(const FeatureConfig &featureConfig);
    ~FeatureInterpreter();

    /**
     * Get version of dllite-micro.
     *
     * @param [out] versionInfo The versionInfo object.
     * @return Return the return code of function execution.
     */
    static ReturnCode GetVersion(VersionInfo &versionInfo);

    /**
     * Get framework information.
     *
     * @param [in] frameworkName The framework name.
     * @param [out] frameworkInfo The frameworkInfo object of framework.
     * @return Return the return code of function execution.
     */
    static ReturnCode GetFrameworkInfo(const std::string &frameworkName, FrameworkInfo &frameworkInfo);

    /**
     * Register feature-interpreter.
     *
     * @param [in] featureConfig The featureConfig object.
     * @return Return the shared pointer of FeatureInterpreter object.
     */
    static std::shared_ptr<FeatureInterpreter> RegisterFeature(const FeatureConfig &featureConfig);

    /**
     * Unregister feature-interpreter.
     *
     * @param [in] pFeatureInterpreter The shared pointer of FeatureInterpreter object.
     * @return Return the return code of function execution.
     */
    static ReturnCode UnregisterFeature(std::shared_ptr<FeatureInterpreter> &pFeatureInterpreter);

    /**
     * Get feature-interpreter by featureName.
     *
     * @param [in] featureName The feature name.
     * @return Return the shared pointer of FeatureInterpreter object.
     */
    static std::shared_ptr<FeatureInterpreter> GetFeatureInterpreterByFeatureName(const std::string &featureName);

    /**
     * Get featureName list.
     *
     * @return Return the feature name list.
     */
    static std::vector<std::string> GetFeatureNameList();

    /**
     * Create model-interpreter.
     *
     * @param [in] modelConfig The modelConfig object.
     * @return Return the shared pointer of ModelInterpreter object.
     */
    std::shared_ptr<ModelInterpreter> CreateModelInterpreter(const ModelConfig &modelConfig);

    /**
     * Destroy model-interpreter.
     *
     * @param [in] pModelInterpreter The shared pointer of ModelInterpreter object.
     * @return Return the return code of function execution.
     */
    ReturnCode DestroyModelInterpreter(std::shared_ptr<ModelInterpreter> &pModelInterpreter);

    /**
     * Get model-interpreter by modelName.
     *
     * @param [in] modelName The model name.
     * @return Return the shared pointer of ModelInterpreter object.
     */
    std::shared_ptr<ModelInterpreter> GetModelInterpreterByModelName(const std::string &modelName);

    /**
     * Get modelName list.
     *
     * @return Return the model name list.
     */
    std::vector<std::string> GetModelNameList();

private:
    FeatureConfig featureConfig_;
    std::mutex modelMutex_;
    size_t modelNum_;
    static size_t featureNum_;
    static std::mutex regMutex_;
    std::map<std::string, std::shared_ptr<ModelInterpreter>> modelInterpreterMapTable;
};
} // namespace dllite
} // namespace AI
} // namespace OHOS

#endif // FEATURE_INTERPRETER_H
