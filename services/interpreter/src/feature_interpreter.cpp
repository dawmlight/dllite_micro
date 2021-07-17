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

#include "feature_interpreter.h"

#include "aie_log.h"

using namespace OHOS::AI;

namespace OHOS {
namespace AI {
namespace dllite {
const std::string DLLITE_VERSION = "HiAI DLLite_micro 11.1.0.201";
const std::string FRAMEWORK_VERSION = "11.1.0.201";

const std::string FRAMEWORK_MINDSPORE = "MindSpore";

size_t FeatureInterpreter::featureNum_ = 0;
std::mutex FeatureInterpreter::regMutex_;

FeatureInterpreter::FeatureInterpreter(const FeatureConfig &featureConfig) : featureConfig_(featureConfig), modelNum_(0)
{
    modelInterpreterMapTable.clear();
}

FeatureInterpreter::~FeatureInterpreter() = default;

ReturnCode FeatureInterpreter::GetVersion(VersionInfo &versionInfo)
{
    versionInfo.version = DLLITE_VERSION;

    versionInfo.frameworkInfos.push_back(FRAMEWORK_MINDSPORE);

    return ReturnCode::SUCCESS;
}

ReturnCode FeatureInterpreter::GetFrameworkInfo(const std::string &frameworkName, FrameworkInfo &frameworkInfo)
{
    frameworkInfo.version = FRAMEWORK_VERSION;

    if (frameworkName == FRAMEWORK_MINDSPORE) {
        frameworkInfo.option = FRAMEWORK_MINDSPORE;
    } else {
        frameworkInfo.option = "";
        return ReturnCode::INVALID_PARAM;
    }

    return ReturnCode::SUCCESS;
}

std::shared_ptr<FeatureInterpreter> FeatureInterpreter::RegisterFeature(const FeatureConfig &featureConfig)
{
    std::lock_guard<std::mutex> guard(regMutex_);

    std::shared_ptr<FeatureInterpreter> pFeature = nullptr;
    size_t length = featureConfig.featureName.length();
    if (length > MAX_PATH_LENGTH) {
        HILOGE("Feature name is too long with len = %lu", length);
        return pFeature;
    }

    std::map<std::string, std::shared_ptr<FeatureInterpreter>>::iterator iter =
        featureInterpreterMapTable.find(featureConfig.featureName);
    if (iter != featureInterpreterMapTable.end()) {
        HILOGI("FeatureName %s has exist in mapTable, register feature fail.", featureConfig.featureName.c_str());
        return pFeature;
    }

    if (featureNum_ >= MAX_FEATURE_NUM) {
        HILOGE("Feature interpreters exceed the maximum %lu", MAX_FEATURE_NUM);
        return pFeature;
    }

    pFeature = std::make_shared<FeatureInterpreter>(featureConfig);
    if (pFeature == nullptr) {
        HILOGE("Register feature fail");
        return pFeature;
    }

    featureInterpreterMapTable.insert(
        std::pair<std::string, std::shared_ptr<FeatureInterpreter>>(featureConfig.featureName, pFeature));

    ++featureNum_;
    HILOGI("RegisterFeature success");

    return pFeature;
}

ReturnCode FeatureInterpreter::UnregisterFeature(std::shared_ptr<FeatureInterpreter> &pFeatureInterpreter)
{
    std::lock_guard<std::mutex> guard(regMutex_);

    if (pFeatureInterpreter == nullptr) {
        HILOGE("Invalid pFeatureInterpreter, unregister feature fail");
        return ReturnCode::INVALID_POINTER;
    }

    if (featureNum_ == 0) {
        HILOGE("Zero feature, unregister feature fail");
        return ReturnCode::UNKNOWN;
    }

    std::map<std::string, std::shared_ptr<FeatureInterpreter>>::iterator iter =
        featureInterpreterMapTable.find(pFeatureInterpreter->featureConfig_.featureName);
    if (iter == featureInterpreterMapTable.end()) {
        HILOGE("pFeatureInterpreter not exist in mapTable, unregister feature fail");
        return ReturnCode::INVALID_PARAM;
    }
    featureInterpreterMapTable.erase(iter);

    pFeatureInterpreter.reset();
    --featureNum_;
    HILOGI("UnregisterFeature success");

    return ReturnCode::SUCCESS;
}

std::shared_ptr<FeatureInterpreter> FeatureInterpreter::GetFeatureInterpreterByFeatureName(
    const std::string &featureName)
{
    std::shared_ptr<FeatureInterpreter> pFeature = nullptr;
    std::map<std::string, std::shared_ptr<FeatureInterpreter>>::iterator iter =
        featureInterpreterMapTable.find(featureName);
    if (iter == featureInterpreterMapTable.end()) {
        HILOGI("FeatureName %s not exist in mapTable.", featureName.c_str());
        return pFeature;
    }
    pFeature = iter->second;

    return pFeature;
}

std::vector<std::string> FeatureInterpreter::GetFeatureNameList()
{
    std::vector<std::string> featureNameList;

    for (auto featurePair : featureInterpreterMapTable) {
        featureNameList.push_back(featurePair.first);
    }

    return featureNameList;
}

std::shared_ptr<ModelInterpreter> FeatureInterpreter::CreateModelInterpreter(const ModelConfig &modelConfig)
{
    std::lock_guard<std::mutex> guard(modelMutex_);

    std::shared_ptr<ModelInterpreter> pModel = nullptr;
    if (modelConfig.CheckModelConfig() != ReturnCode::SUCCESS) {
        HILOGE("INVALID ModelConfig");
        return pModel;
    }

    if (modelNum_ >= MAX_MODEL_NUM) {
        HILOGE("Model interpreters exceeds the maximum %lu", MAX_MODEL_NUM);
        return pModel;
    }

    std::map<std::string, std::shared_ptr<ModelInterpreter>>::iterator iter =
        modelInterpreterMapTable.find(modelConfig.modelName_);
    if (iter != modelInterpreterMapTable.end()) {
        HILOGI("ModelName %s has exist in mapTable, create model-interpreter fail.", modelConfig.modelName_.c_str());
        return pModel;
    }

    pModel = std::make_shared<ModelInterpreter>(modelConfig);
    if (pModel == nullptr) {
        HILOGE("CreateModelInterpreter error");
        return pModel;
    }

    modelInterpreterMapTable.insert(
        std::pair<std::string, std::shared_ptr<ModelInterpreter>>(modelConfig.modelName_, pModel));

    // Create InferWrapper
    ReturnCode returnCode = pModel->Init();
    if (returnCode != ReturnCode::SUCCESS) {
        HILOGE("ModelInterpreter Init error");
        pModel.reset();
        return pModel;
    }

    ++modelNum_;
    HILOGI("CreateModelInterpreter success");

    return pModel;
}

ReturnCode FeatureInterpreter::DestroyModelInterpreter(std::shared_ptr<ModelInterpreter> &pModelInterpreter)
{
    std::lock_guard<std::mutex> guard(modelMutex_);

    if ((modelNum_ <= 0) || (pModelInterpreter == nullptr)) {
        HILOGE("DestroyModelInterpreter Invalid Param");
        return ReturnCode::INVALID_PARAM;
    }

    ReturnCode returnCode = pModelInterpreter->Term();
    if (returnCode != ReturnCode::SUCCESS) {
        HILOGE("ModelInterpreter terminate error");
        return returnCode;
    }

    std::map<std::string, std::shared_ptr<ModelInterpreter>>::iterator iter =
        modelInterpreterMapTable.find(pModelInterpreter->modelConfig_.modelName_);
    if (iter == modelInterpreterMapTable.end()) {
        HILOGI("pModelInterpreter not exist in mapTable, destroy model-interpreter fail.");
        return ReturnCode::INVALID_PARAM;
    }
    modelInterpreterMapTable.erase(iter);

    pModelInterpreter.reset();
    --modelNum_;
    HILOGI("DestroyModelInterpreter success");

    return ReturnCode::SUCCESS;
}

std::shared_ptr<ModelInterpreter> FeatureInterpreter::GetModelInterpreterByModelName(const std::string &modelName)
{
    std::shared_ptr<ModelInterpreter> pModel = nullptr;
    std::map<std::string, std::shared_ptr<ModelInterpreter>>::iterator iter = modelInterpreterMapTable.find(modelName);
    if (iter == modelInterpreterMapTable.end()) {
        HILOGI("ModelName %s not exist in mapTable.", modelName.c_str());
        return pModel;
    }
    pModel = iter->second;

    return pModel;
}

std::vector<std::string> FeatureInterpreter::GetModelNameList()
{
    std::vector<std::string> modelNameList;

    for (auto modelPair : modelInterpreterMapTable) {
        modelNameList.push_back(modelPair.first);
    }

    return modelNameList;
}
} // namespace dllite
} // namespace AI
} // namespace OHOS
