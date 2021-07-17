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

#include <cstring>
#include <unistd.h>

#include "gtest/gtest.h"

#include "aie_log.h"
#include "feature_interpreter.h"
#include "model_config.h"
#include "model_interpreter.h"
#include "securec.h"
#include "type_define.h"

using namespace OHOS::AI::dllite;
using namespace testing::ext;

namespace {
    const std::string EMPTY_STRING = "";
    const std::string FRAMEWORK_MINDSPORE = "MindSpore";
    const std::string MNIST_MODEL_NAME = "test_mnist";
    const std::string MNIST_MODEL_PATH = "/storage/data/dllite_micro_libmnist.so";
    const std::string MNIST_WEIGHT_PATH = "/storage/data/dllite_micro_mnist.bin";
    const std::string TEST_NAME = "test";
}

static void SetInputTensor(std::vector<IOTensor> &inputTensors)
{
    for (uint32 j = 0; j < inputTensors.size(); ++j) {
        size_t inputSize = inputTensors[j].buffer.second;
        int8* inputData = (int8*)malloc(inputSize);
        memset_s(inputData, inputSize, 1, inputSize);
        inputTensors[j].buffer.first = static_cast<void*>(inputData);
    }
}

class ModelInterpreterTest : public testing::Test {
public:
    // SetUpTestCase: The preset action of the test suite is executed before the first TestCase
    static void SetUpTestCase() {};

    // TearDownTestCase: The test suite cleanup action is executed after the last TestCase
    static void TearDownTestCase() {};

    // SetUp: Execute before each test case
    void SetUp() {};

    // TearDown: Execute after each test case
    void TearDown() {};
};

/**
 * @tc.name: TestDLLiteLoad001
 * @tc.desc: Test DLLIte Load API
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F (ModelInterpreterTest, TestDLLiteLoad001, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteLoad001.");

    FeatureConfig featureConfig;
    featureConfig.featureName = TEST_NAME;
    std::shared_ptr<FeatureInterpreter> featureInterpreter = nullptr;
    featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
    EXPECT_NE(nullptr, featureInterpreter);

    ModelConfig modelConfig;
    modelConfig.modelName_ = MNIST_MODEL_NAME;
    modelConfig.modelPath_ = MNIST_MODEL_PATH;
    modelConfig.weightPath_ = MNIST_WEIGHT_PATH;
    modelConfig.inferFrameworkType_ = InferFrameworkType::MINDSPORE;

    std::shared_ptr<ModelInterpreter> modelInterpreter;
    modelInterpreter = featureInterpreter->CreateModelInterpreter(modelConfig);
    EXPECT_NE(nullptr, modelInterpreter);

    ReturnCode returnCode;
    returnCode = modelInterpreter->Load();
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    returnCode = modelInterpreter->Unload();
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    returnCode = featureInterpreter->DestroyModelInterpreter(modelInterpreter);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreter);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
}

/**
 * @tc.name: TestDLLiteGetTensors001
 * @tc.desc: Test DLLite GetTensors API, Get inputs.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(ModelInterpreterTest, TestDLLiteGetTensors001, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteGetTensors001.");

    FeatureConfig featureConfig;
    featureConfig.featureName = TEST_NAME;
    std::shared_ptr<FeatureInterpreter> featureInterpreter = nullptr;
    featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
    EXPECT_NE(nullptr, featureInterpreter);

    ModelConfig modelConfig;
    modelConfig.modelName_ = MNIST_MODEL_NAME;
    modelConfig.modelPath_ = MNIST_MODEL_PATH;
    modelConfig.weightPath_ = MNIST_WEIGHT_PATH;
    modelConfig.inferFrameworkType_ = InferFrameworkType::MINDSPORE;

    std::shared_ptr<ModelInterpreter> modelInterpreter;
    modelInterpreter = featureInterpreter->CreateModelInterpreter(modelConfig);
    EXPECT_NE(nullptr, modelInterpreter);

    ReturnCode returnCode;
    returnCode = modelInterpreter->Load();
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    std::vector<IOTensor> inputs;
    returnCode = modelInterpreter->GetTensors(inputs, IOFlag::INPUT);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    returnCode = modelInterpreter->Unload();
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    returnCode = featureInterpreter->DestroyModelInterpreter(modelInterpreter);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreter);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
}

/**
 * @tc.name: TestDLLiteGetTensors002
 * @tc.desc: Test DLLite GetTensors API, Get outputs.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(ModelInterpreterTest, TestDLLiteGetTensors002, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteGetTensors002.");

    FeatureConfig featureConfig;
    featureConfig.featureName = TEST_NAME;
    std::shared_ptr<FeatureInterpreter> featureInterpreter = nullptr;
    featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
    EXPECT_NE(nullptr, featureInterpreter);

    ModelConfig modelConfig;
    modelConfig.modelName_ = MNIST_MODEL_NAME;
    modelConfig.modelPath_ = MNIST_MODEL_PATH;
    modelConfig.weightPath_ = MNIST_WEIGHT_PATH;
    modelConfig.inferFrameworkType_ = InferFrameworkType::MINDSPORE;

    std::shared_ptr<ModelInterpreter> modelInterpreter;
    modelInterpreter = featureInterpreter->CreateModelInterpreter(modelConfig);
    EXPECT_NE(nullptr, modelInterpreter);

    ReturnCode returnCode;
    returnCode = modelInterpreter->Load();
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    std::vector<IOTensor> outputs;
    returnCode = modelInterpreter->GetTensors(outputs, IOFlag::OUTPUT);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    returnCode = modelInterpreter->Unload();
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    returnCode = featureInterpreter->DestroyModelInterpreter(modelInterpreter);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreter);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
}

/**
 * @tc.name: TestDLLiteInvoke001
 * @tc.desc: Test DLLite Invoke API.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(ModelInterpreterTest, TestDLLiteInvoke001, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteInvoke001.");

    FeatureConfig featureConfig;
    featureConfig.featureName = TEST_NAME;
    std::shared_ptr<FeatureInterpreter> featureInterpreter = nullptr;
    featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
    EXPECT_NE(nullptr, featureInterpreter);

    ModelConfig modelConfig;
    modelConfig.modelName_ = MNIST_MODEL_NAME;
    modelConfig.modelPath_ = MNIST_MODEL_PATH;
    modelConfig.weightPath_ = MNIST_WEIGHT_PATH;
    modelConfig.inferFrameworkType_ = InferFrameworkType::MINDSPORE;

    std::shared_ptr<ModelInterpreter> modelInterpreter;
    modelInterpreter = featureInterpreter->CreateModelInterpreter(modelConfig);
    EXPECT_NE(nullptr, modelInterpreter);

    ReturnCode returnCode;
    returnCode = modelInterpreter->Load();
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    std::vector<IOTensor> inputs;
    returnCode = modelInterpreter->GetTensors(inputs, IOFlag::INPUT);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    std::vector<IOTensor> outputs;
    returnCode = modelInterpreter->GetTensors(outputs, IOFlag::OUTPUT);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    SetInputTensor(inputs);
    returnCode = modelInterpreter->Invoke(inputs, outputs);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
    

    returnCode = modelInterpreter->Unload();
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    returnCode = featureInterpreter->DestroyModelInterpreter(modelInterpreter);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreter);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
}