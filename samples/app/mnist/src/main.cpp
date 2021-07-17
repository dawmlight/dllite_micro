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

#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "feature_interpreter.h"
#include "model_config.h"
#include "model_interpreter.h"
#include "securec.h"
#include "type_define.h"

using namespace OHOS::AI::dllite;

namespace {
// const variable
const std::string FEATURE_NAME = "MNIST";
const std::string MODEL_NAME = "mnist";
const int WARM_TRY_COUNT = 3;
const int INVOKE_LOOP_COUNT = 100;
const int CONSTANT_ONE = 1;
const int USEC = 1000000;
const int MSEC = 1000;
const float THOUSANDS_UNIT = 1000.0;

// variable in-use
FeatureConfig g_featureConfig;
ModelConfig g_modelConfig;
std::vector<IOTensor> g_inputs;
std::vector<IOTensor> g_outputs;
std::shared_ptr<FeatureInterpreter> g_featureInterpreter;
std::shared_ptr<ModelInterpreter> g_modelInterpreter;
} // namespace

static void SetInputTensor(std::vector<IOTensor> &inputTensors)
{
    for (uint32 j = 0; j < inputTensors.size(); ++j) {
        size_t inputSize = inputTensors[j].buffer.second;
        int8 *inputData = (int8 *)malloc(inputSize);
        memset_s(inputData, inputSize, 1, inputSize);
        inputTensors[j].buffer.first = static_cast<void *>(inputData);
    }
}

static void PrintTensors(const std::vector<IOTensor> &inputs, const std::vector<IOTensor> &outputs)
{
    // print inputs
    std::cout << "inputs:";
    int8 *pSrc = static_cast<int8 *>(inputs[0].buffer.first);
    std::cout << "input size: " << inputs[0].buffer.second << std::endl;
    for (int i = 0; i < inputs[0].buffer.second; ++i) {
        std::cout << (std::to_string(pSrc[i]) + ", ");
    }
    std::cout << std::endl;

    // print outputs
    std::cout << "outputs:";
    pSrc = static_cast<int8 *>(outputs[0].buffer.first);
    std::cout << "output size: " << outputs[0].buffer.second << std::endl;
    for (int i = 0; i < outputs[0].buffer.second; ++i) {
        std::cout << (std::to_string(pSrc[i]) + ", ");
    }
    std::cout << std::endl;
}

static void WarmUp(const std::shared_ptr<ModelInterpreter> &pModel,
                   const std::vector<IOTensor> &inputs,
                   std::vector<IOTensor> &outputs)
{
    ReturnCode returnCode = ReturnCode::UNKNOWN;
    for (int i = 0; i < WARM_TRY_COUNT; ++i) {
        returnCode = pModel->Invoke(inputs, outputs);
        if (returnCode != ReturnCode::SUCCESS) {
            std::cout << "warm up failed" << std::endl;
            continue;
        }
        std::cout << "warm up success" << std::endl;
        break;
    }
}

static int CreateInterpreter()
{
    // RegisterFeature
    g_featureConfig.featureName = FEATURE_NAME;
    g_featureInterpreter = FeatureInterpreter::RegisterFeature(g_featureConfig);
    if (g_featureInterpreter.get() == nullptr) {
        std::cout << "RegisterFeature failed" << std::endl;
        return -1;
    }

    // CreateModelInterpreter
    g_modelConfig.inferFrameworkType_ = InferFrameworkType::MINDSPORE;
    g_modelInterpreter = g_featureInterpreter->CreateModelInterpreter(g_modelConfig);
    if (g_modelInterpreter == nullptr) {
        std::cout << "CreateModelInterpreter failed" << std::endl;
        return -1;
    }

    return 0;
}

static int ModelInference()
{
    // Load
    ReturnCode returnCode = g_modelInterpreter->Load();
    if (returnCode != ReturnCode::SUCCESS) {
        std::cout << "Load failed" << std::endl;
        return -1;
    }

    // GetTensors
    returnCode = g_modelInterpreter->GetTensors(g_inputs, IOFlag::INPUT);
    if (returnCode != ReturnCode::SUCCESS) {
        std::cout << "GetTensors input failed" << std::endl;
        return -1;
    }
    returnCode = g_modelInterpreter->GetTensors(g_outputs, IOFlag::OUTPUT);
    if (returnCode != ReturnCode::SUCCESS) {
        std::cout << "GetTensors output failed" << std::endl;
        return -1;
    }
    SetInputTensor(g_inputs);

    // Invoke
    std::cout << "warm up" << std::endl;
    WarmUp(g_modelInterpreter, g_inputs, g_outputs);
    for (int i = 0; i < INVOKE_LOOP_COUNT; ++i) {
        returnCode = g_modelInterpreter->Invoke(g_inputs, g_outputs);
        if (returnCode != ReturnCode::SUCCESS) {
            std::cout << "invoke failed" << std::endl;
            return -1;
        }
    }

    returnCode = g_modelInterpreter->GetTensors(g_outputs, IOFlag::OUTPUT);
    PrintTensors(g_inputs, g_outputs);

    // Unload
    returnCode = g_modelInterpreter->Unload();
    if (returnCode != ReturnCode::SUCCESS) {
        std::cout << "unload failed" << std::endl;
        return -1;
    }

    return 0;
}

static int DestroyInterpreter()
{
    // DestroyModelInterpreter
    ReturnCode returnCode = g_featureInterpreter->DestroyModelInterpreter(g_modelInterpreter);
    if (returnCode != ReturnCode::SUCCESS) {
        std::cout << "DestroyModelInterpreter failed" << std::endl;
        return -1;
    }

    // UnregisterFeature
    returnCode = FeatureInterpreter::UnregisterFeature(g_featureInterpreter);
    if (returnCode != ReturnCode::SUCCESS) {
        std::cout << "UnregisterFeature failed" << std::endl;
        return -1;
    }

    return 0;
}

int main(int argc, const char **argv)
{
    g_modelConfig.modelName_ = MODEL_NAME;
    g_modelConfig.modelPath_ = argv[1];
    g_modelConfig.weightPath_ = argv[2];

    int returnCode = 0;
    returnCode = CreateInterpreter();
    if (returnCode) {
        std::cout << "CreateInterpreter failed" << std::endl;
        return returnCode;
    }

    returnCode = ModelInference();
    if (returnCode) {
        std::cout << "ModelInterence failed" << std::endl;
        return returnCode;
    }

    returnCode = DestroyInterpreter();
    if (returnCode) {
        std::cout << "DestroyInterpreter failed" << std::endl;
        return returnCode;
    }

    return 0;
}