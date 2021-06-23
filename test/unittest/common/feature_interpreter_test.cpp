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
#include "type_define.h"

using namespace OHOS::AI::dllite;
using namespace testing::ext;

namespace {
const char CONST_CH = '9';
const std::string EMPTY_STRING = "";
const std::string FRAMEWORK_MINDSPORE = "MindSpore";
const std::string INPUT_MODEL_NAME = "test_mnist";
const std::string INPUT_MODEL_PATH = "/storage/data/dllite_micro_libmnist.so";
const std::string INPUT_WEIGHT_PATH = "/storage/data/dllite_micro_mnist.bin";
const std::string FRAMEWORK_NAME = "test_framework";
const std::string FEATURE_NAME = "test_feature";
} // namespace

class FeatureInterpreterTest : public testing::Test {
public:
    // SetUpTestCase: The preset action of the test suite is executed before the first TestCase
    static void SetUpTestCase(){};

    // TearDownTestCase: The test suite cleanup action is executed after the last TestCase
    static void TearDownTestCase(){};

    // SetUp: Execute before each test case
    void SetUp(){};

    // TearDown: Execute after each test case
    void TearDown(){};
};

static std::string GenerateRandomStr(const char ch, const size_t length)
{
    char genStr[length];
    for (size_t i = 0; i < length; i++) {
        genStr[i] = ch;
    }
    return std::string(genStr, length);
}

/**
 * @tc.name: TestDLLiteGetVersion001
 * @tc.desc: Test DLLite GetVersion API
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteGetVersion001, TestSize.Level0)
{
    HILOGI("[Test] Begin TestDLLiteGetVersion001.");

    VersionInfo versionInfo;
    ReturnCode returnCode;
    returnCode = FeatureInterpreter::GetVersion(versionInfo);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    std::string expectStr = "HiAI DLLite_micro";
    EXPECT_TRUE(strncmp(versionInfo.version.c_str(), expectStr.c_str(), expectStr.size()) == 0);
}

/**
 * @tc.name: TestDLLiteGetFrameworkInfo001
 * @tc.desc: Test DLLite GetFrameworkInfo API, normal.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteGetFrameworkInfo001, TestSize.Level0)
{
    HILOGI("[Test] Begin TestDLLiteGetFrameworkInfo001.");

    std::string frameworkName = FRAMEWORK_MINDSPORE;
    FrameworkInfo frameworkInfo;
    ReturnCode returnCode;
    returnCode = FeatureInterpreter::GetFrameworkInfo(frameworkName, frameworkInfo);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
    EXPECT_TRUE(frameworkInfo.version != "");
}

/**
 * @tc.name: TestDLLiteGetFrameworkInfo002
 * @tc.desc: Test DLLite GetFrameworkInfo API, invalid frameworkName.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteGetFrameworkInfo002, TestSize.Level0)
{
    HILOGI("[Test] Begin TestDLLiteGetFrameworkInfo002.");

    std::string frameworkName = FRAMEWORK_NAME;
    FrameworkInfo frameworkInfo;
    ReturnCode returnCode;
    returnCode = FeatureInterpreter::GetFrameworkInfo(frameworkName, frameworkInfo);
    EXPECT_EQ(ReturnCode::INVALID_PARAM, returnCode);
}

/**
 * @tc.name: TestDLLiteGetFrameworkInfo003
 * @tc.desc: Test DLLite GetFrameworkInfo API, empty frameworkName.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteGetFrameworkInfo003, TestSize.Level0)
{
    HILOGI("[Test] Begin TestDLLiteGetFrameworkInfo003.");

    std::string frameworkName = EMPTY_STRING;
    FrameworkInfo frameworkInfo;
    ReturnCode returnCode;
    returnCode = FeatureInterpreter::GetFrameworkInfo(frameworkName, frameworkInfo);
    EXPECT_EQ(ReturnCode::INVALID_PARAM, returnCode);
}

/**
 * @tc.name: TestDLLiteRegisterFeature001
 * @tc.desc: Test DLLite RegisterFeature API.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteRegisterFeature001, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteRegisterFeature001.");

    FeatureConfig featureConfig;
    featureConfig.featureName = FEATURE_NAME;
    std::shared_ptr<FeatureInterpreter> featureInterpreter = nullptr;
    featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
    EXPECT_NE(nullptr, featureInterpreter);

    ReturnCode returnCode;
    returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreter);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
}

/**
 * @tc.name: TestDLLiteRegisterFeature002
 * @tc.desc: Test DLLite RegisterFeature API, empty featureName.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteRegisterFeature002, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteRegisterFeature002.");

    FeatureConfig featureConfig;
    featureConfig.featureName = EMPTY_STRING;
    std::shared_ptr<FeatureInterpreter> featureInterpreter = nullptr;
    featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
    EXPECT_NE(nullptr, featureInterpreter);

    ReturnCode returnCode;
    returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreter);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
}

/**
 * @tc.name: TestDLLiteRegisterFeature003
 * @tc.desc: Test DLLite RegisterFeature API, RegisterFeature 8 times with different featureName.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteRegisterFeature003, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteRegisterFeature003.");

    FeatureConfig featureConfig;
    std::string featureName = FEATURE_NAME;
    int registerTimes = 8;
    std::vector<std::shared_ptr<FeatureInterpreter>> featureInterpreters;
    for (int i = 0; i < registerTimes; i++) {
        featureConfig.featureName = featureName + std::to_string(i + 1);
        std::shared_ptr<FeatureInterpreter> featureInterpreter;
        featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
        EXPECT_NE(nullptr, featureInterpreter);
        featureInterpreters.push_back(featureInterpreter);
    }

    ReturnCode returnCode;
    while (!featureInterpreters.empty() && registerTimes--) {
        returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreters.back());
        EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
        featureInterpreters.pop_back();
    }
}

/**
 * @tc.name: TestDLLiteRegisterFeature004
 * @tc.desc: Test DLLite RegisterFeature API, RegisterFeature several times with same featureName.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteRegisterFeature004, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteRegisterFeature004.");

    FeatureConfig featureConfig;
    std::string featureName = FEATURE_NAME;
    int registerTimes = 2;
    std::vector<std::shared_ptr<FeatureInterpreter>> featureInterpreters;
    std::shared_ptr<FeatureInterpreter> featureInterpreter;
    featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
    EXPECT_NE(nullptr, featureInterpreter);
    featureInterpreters.push_back(featureInterpreter);
    for (int i = 0; i < registerTimes - 1; i++) {
        featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
        EXPECT_EQ(nullptr, featureInterpreter);
        if (featureInterpreter != nullptr) {
            featureInterpreters.push_back(featureInterpreter);
        }
    }

    ReturnCode returnCode;
    while (!featureInterpreters.empty() && registerTimes--) {
        returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreters.back());
        EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
        featureInterpreters.pop_back();
    }
}

/**
 * @tc.name: TestDLLiteRegisterFeature005
 * @tc.desc: Test DLLite RegisterFeature API, RegisterFeature 9 times.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteRegisterFeature005, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteRegisterFeature005.");

    FeatureConfig featureConfig;
    int registerTimes = 8;
    std::vector<std::shared_ptr<FeatureInterpreter>> featureInterpreters;
    std::shared_ptr<FeatureInterpreter> featureInterpreter = nullptr;
    for (int i = 0; i < registerTimes; i++) {
        featureConfig.featureName = FEATURE_NAME + std::to_string(i + 1);
        featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
        EXPECT_NE(nullptr, featureInterpreter);
        featureInterpreters.push_back(featureInterpreter);
    }

    featureConfig.featureName = FEATURE_NAME + std::to_string(9);
    featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
    EXPECT_EQ(nullptr, featureInterpreter);

    if (featureInterpreter != nullptr) {
        featureInterpreters.push_back(featureInterpreter);
    }

    ReturnCode returnCode;
    while (!featureInterpreters.empty() && registerTimes--) {
        returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreters.back());
        EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
        featureInterpreters.pop_back();
    }
}

/**
 * @tc.name: TestDLLiteRegisterFeature006
 * @tc.desc: Test DLLite RegisterFeature API, featureName exceed MAX_PATH_LENGTH.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteRegisterFeature006, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteRegisterFeature006.");

    FeatureConfig featureConfig;
    featureConfig.featureName = GenerateRandomStr(CONST_CH, MAX_PATH_LENGTH + 1);
    EXPECT_TRUE(featureConfig.featureName.size() == MAX_PATH_LENGTH + 1) << featureConfig.featureName.size();
    std::shared_ptr<FeatureInterpreter> featureInterpreter = nullptr;
    featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
    EXPECT_EQ(nullptr, featureInterpreter) << featureConfig.featureName;

    ReturnCode returnCode;
    if (featureInterpreter != nullptr) {
        returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreter);
        EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
    }
}

/**
 * @tc.name: TestDLLiteRegisterFeature007
 * @tc.desc: Test DLLite RegisterFeature API, RegisterFeature exceed MAX_FEATURE_NUM.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteRegisterFeature007, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteRegisterFeature007.");

    FeatureConfig featureConfig;
    int registerTimes = MAX_FEATURE_NUM + 1;
    std::vector<std::shared_ptr<FeatureInterpreter>> featureInterpreters;
    std::shared_ptr<FeatureInterpreter> featureInterpreter = nullptr;
    for (int i = 1; i <= registerTimes; i++) {
        featureConfig.featureName = FEATURE_NAME + std::to_string(i + 1);
        featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
        if (i <= MAX_FEATURE_NUM) {
            EXPECT_NE(nullptr, featureInterpreter) << featureConfig.featureName;
            if (featureInterpreter != nullptr) {
                featureInterpreters.push_back(featureInterpreter);
            }
        } else {
            EXPECT_EQ(nullptr, featureInterpreter) << featureConfig.featureName;
        }
    }

    ReturnCode returnCode;
    while (!featureInterpreters.empty() && registerTimes--) {
        returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreters.back());
        EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
        featureInterpreters.pop_back();
    }
}

/**
 * @tc.name: TestDLLiteRegisterFeature008
 * @tc.desc: Test DLLite RegisterFeature API, RegisterFeature again after UnRegisterFeature one in MAX_FEATURE_NUM
 * times.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteRegisterFeature008, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteRegisterFeature008.");

    FeatureConfig featureConfig;
    int registerTimes = MAX_FEATURE_NUM;
    std::vector<std::shared_ptr<FeatureInterpreter>> featureInterpreters;
    std::shared_ptr<FeatureInterpreter> featureInterpreter = nullptr;
    for (int i = 1; i <= registerTimes; i++) {
        featureConfig.featureName = FEATURE_NAME + std::to_string(i + 1);
        featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
        EXPECT_TRUE(featureInterpreter != nullptr) << featureConfig.featureName;
        if (featureInterpreter != nullptr) {
            featureInterpreters.push_back(featureInterpreter);
        }
    }

    // unregister
    ReturnCode returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreters.back());
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
    featureInterpreters.pop_back();

    // register again
    featureConfig.featureName = FEATURE_NAME + std::to_string(MAX_FEATURE_NUM + 1);
    featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
    EXPECT_TRUE(featureInterpreter != nullptr);
    if (featureInterpreter != nullptr) {
        featureInterpreters.push_back(featureInterpreter);
    }

    // unregister all
    while (!featureInterpreters.empty() && registerTimes--) {
        returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreters.back());
        EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
        featureInterpreters.pop_back();
    }
}

/**
 * @tc.name: TestDLLiteUnregisterFeature001
 * @tc.desc: Test DLLite UnregisterFeature API.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteUnregisterFeature001, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteUnregisterFeature001.");

    FeatureConfig featureConfig;
    featureConfig.featureName = FEATURE_NAME;
    std::shared_ptr<FeatureInterpreter> featureInterpreter = nullptr;
    featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
    EXPECT_NE(nullptr, featureInterpreter);

    ReturnCode returnCode;
    returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreter);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreter);
    EXPECT_EQ(ReturnCode::INVALID_POINTER, returnCode);
}

/**
 * @tc.name: TestDLLiteCreateModelInterpreter001
 * @tc.desc: Test DLLite CreateModelInterpreter API.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteCreateModelInterpreter001, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteCreateModelInterpreter001.");

    FeatureConfig featureConfig;
    featureConfig.featureName = FEATURE_NAME;
    std::shared_ptr<FeatureInterpreter> featureInterpreter = nullptr;
    featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
    EXPECT_NE(nullptr, featureInterpreter);

    ModelConfig modelConfig;
    modelConfig.modelName_ = INPUT_MODEL_NAME;
    modelConfig.modelPath_ = INPUT_MODEL_PATH;
    modelConfig.weightPath_ = INPUT_WEIGHT_PATH;
    modelConfig.inferFrameworkType_ = InferFrameworkType::MINDSPORE;

    std::shared_ptr<ModelInterpreter> modelInterpreter = nullptr;
    modelInterpreter = featureInterpreter->CreateModelInterpreter(modelConfig);
    EXPECT_NE(nullptr, modelInterpreter);

    ReturnCode returnCode;
    returnCode = featureInterpreter->DestroyModelInterpreter(modelInterpreter);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);

    returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreter);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
}

/**
 * @tc.name: TestDLLiteCreateModelInterpreter002
 * @tc.desc: Test DLLite CreateModelInterpreter API, empty modelPath.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteCreateModelInterpreter002, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteCreateModelInterpreter002.");

    FeatureConfig featureConfig;
    featureConfig.featureName = FEATURE_NAME;
    std::shared_ptr<FeatureInterpreter> featureInterpreter = nullptr;
    featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
    EXPECT_NE(nullptr, featureInterpreter);

    ModelConfig modelConfig;
    modelConfig.modelName_ = INPUT_MODEL_NAME;
    modelConfig.modelPath_ = EMPTY_STRING;
    modelConfig.weightPath_ = INPUT_WEIGHT_PATH;
    modelConfig.inferFrameworkType_ = InferFrameworkType::MINDSPORE;

    std::shared_ptr<ModelInterpreter> modelInterpreter = nullptr;
    modelInterpreter = featureInterpreter->CreateModelInterpreter(modelConfig);
    EXPECT_EQ(nullptr, modelInterpreter);

    ReturnCode returnCode;
    if (modelInterpreter != nullptr) {
        returnCode = featureInterpreter->DestroyModelInterpreter(modelInterpreter);
        EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
    }

    returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreter);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
}

/**
 * @tc.name: TestDLLiteCreateModelInterpreter003
 * @tc.desc: Test DLLite CreateModelInterpreter API, empty modelName.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteCreateModelInterpreter003, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteCreateModelInterpreter003.");

    FeatureConfig featureConfig;
    featureConfig.featureName = FEATURE_NAME;
    std::shared_ptr<FeatureInterpreter> featureInterpreter = nullptr;
    featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
    EXPECT_NE(nullptr, featureInterpreter);

    ModelConfig modelConfig;
    modelConfig.modelName_ = EMPTY_STRING;
    modelConfig.modelPath_ = INPUT_MODEL_PATH;
    modelConfig.weightPath_ = INPUT_WEIGHT_PATH;
    modelConfig.inferFrameworkType_ = InferFrameworkType::MINDSPORE;

    std::shared_ptr<ModelInterpreter> modelInterpreter = nullptr;
    modelInterpreter = featureInterpreter->CreateModelInterpreter(modelConfig);
    EXPECT_EQ(nullptr, modelInterpreter);

    ReturnCode returnCode;
    if (modelInterpreter != nullptr) {
        returnCode = featureInterpreter->DestroyModelInterpreter(modelInterpreter);
        EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
    }

    returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreter);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
}

/**
 * @tc.name: TestDLLiteCreateModelInterpreter004
 * @tc.desc: Test DLLite CreateModelInterpreter API, empty weightPath.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteCreateModelInterpreter004, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteCreateModelInterpreter004.");

    FeatureConfig featureConfig;
    featureConfig.featureName = FEATURE_NAME;
    std::shared_ptr<FeatureInterpreter> featureInterpreter = nullptr;
    featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
    EXPECT_NE(nullptr, featureInterpreter);

    ModelConfig modelConfig;
    modelConfig.modelName_ = INPUT_MODEL_NAME;
    modelConfig.modelPath_ = INPUT_MODEL_PATH;
    modelConfig.weightPath_ = EMPTY_STRING;
    modelConfig.inferFrameworkType_ = InferFrameworkType::MINDSPORE;

    std::shared_ptr<ModelInterpreter> modelInterpreter = nullptr;
    modelInterpreter = featureInterpreter->CreateModelInterpreter(modelConfig);
    EXPECT_EQ(nullptr, modelInterpreter);

    ReturnCode returnCode;
    if (modelInterpreter != nullptr) {
        returnCode = featureInterpreter->DestroyModelInterpreter(modelInterpreter);
        EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
    }

    returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreter);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
}

/**
 * @tc.name: TestDLLiteCreateModelInterpreter005
 * @tc.desc: Test DLLite CreateModelInterpreter API, create several modelInterpreter with same modelName, expect fail.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteCreateModelInterpreter005, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteCreateModelInterpreter005.");

    FeatureConfig featureConfig;
    featureConfig.featureName = FEATURE_NAME;
    std::shared_ptr<FeatureInterpreter> featureInterpreter = nullptr;
    featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
    EXPECT_NE(nullptr, featureInterpreter);

    int createTimes = 2;
    ModelConfig modelConfig;
    modelConfig.modelName_ = INPUT_MODEL_NAME;
    modelConfig.modelPath_ = INPUT_MODEL_PATH;
    modelConfig.weightPath_ = INPUT_WEIGHT_PATH;
    modelConfig.inferFrameworkType_ = InferFrameworkType::MINDSPORE;

    std::shared_ptr<ModelInterpreter> modelInterpreter = nullptr;
    std::vector<std::shared_ptr<ModelInterpreter>> modelInterpreters;
    for (int i = 0; i < createTimes; i++) {
        modelInterpreter = featureInterpreter->CreateModelInterpreter(modelConfig);
        if (i == 0) {
            EXPECT_NE(nullptr, modelInterpreter);
        } else {
            EXPECT_EQ(nullptr, modelInterpreter);
        }
        if (modelInterpreter != nullptr) {
            modelInterpreters.push_back(modelInterpreter);
        }
    }

    ReturnCode returnCode;
    // destroy all modelInterpreters
    while (!modelInterpreters.empty() && createTimes--) {
        returnCode = featureInterpreter->DestroyModelInterpreter(modelInterpreters.back());
        EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
        modelInterpreters.pop_back();
    }

    returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreter);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
}

/**
 * @tc.name: TestDLLiteCreateModelInterpreter006
 * @tc.desc: Test DLLite CreateModelInterpreter API, 2 features, 16 models per featureInterpreter.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteCreateModelInterpreter006, TestSize.Level0)
{
    HILOGI("[Test]Begin TestDLLiteCreateModelInterpreter006.");

    FeatureConfig featureConfig1;
    FeatureConfig featureConfig2;
    featureConfig1.featureName = FEATURE_NAME + std::to_string(1);
    featureConfig2.featureName = FEATURE_NAME + std::to_string(2);
    std::shared_ptr<FeatureInterpreter> featureInterpreter1 = nullptr;
    std::shared_ptr<FeatureInterpreter> featureInterpreter2 = nullptr;
    featureInterpreter1 = FeatureInterpreter::RegisterFeature(featureConfig1);
    EXPECT_NE(nullptr, featureInterpreter1);
    featureInterpreter2 = FeatureInterpreter::RegisterFeature(featureConfig2);
    EXPECT_NE(nullptr, featureInterpreter2);

    int modelNumPerpFeature = 16;
    ModelConfig modelConfig;
    modelConfig.modelPath_ = INPUT_MODEL_PATH;
    modelConfig.weightPath_ = INPUT_WEIGHT_PATH;
    modelConfig.inferFrameworkType_ = InferFrameworkType::MINDSPORE;
    std::shared_ptr<ModelInterpreter> modelInterpreter = nullptr;
    std::vector<std::shared_ptr<ModelInterpreter>> modelInterpretersP1;
    std::vector<std::shared_ptr<ModelInterpreter>> modelInterpretersP2;

    for (int i = 1; i <= modelNumPerpFeature; i++) {
        modelConfig.modelName_ = INPUT_MODEL_PATH + std::to_string(i);
        modelInterpreter = featureInterpreter1->CreateModelInterpreter(modelConfig);
        EXPECT_NE(nullptr, modelInterpreter) << modelConfig.modelName_;
        modelInterpretersP1.push_back(modelInterpreter);

        modelInterpreter = featureInterpreter2->CreateModelInterpreter(modelConfig);
        EXPECT_NE(nullptr, modelInterpreter) << modelConfig.modelName_;
        modelInterpretersP2.push_back(modelInterpreter);
    }

    ReturnCode returnCode;
    while (!modelInterpretersP1.empty() && !modelInterpretersP2.empty() && modelNumPerpFeature--) {
        returnCode = featureInterpreter1->DestroyModelInterpreter(modelInterpretersP1.back());
        EXPECT_EQ(ReturnCode::SUCCESS, returnCode) << modelInterpretersP1.size() << " " << modelNumPerpFeature;
        modelInterpretersP1.pop_back();

        returnCode = featureInterpreter2->DestroyModelInterpreter(modelInterpretersP2.back());
        EXPECT_EQ(ReturnCode::SUCCESS, returnCode) << modelInterpretersP2.size() << " " << modelNumPerpFeature;
        modelInterpretersP2.pop_back();
    }

    returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreter1);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
    returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreter2);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
}

/**
 * @tc.name: TestDLLiteGetFeatureInterpreterByFeatureName001
 * @tc.desc: Test DLLite GetFeatureInterpreterByFeatureName API.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteGetFeatureInterpreterByFeatureName001, TestSize.Level0)
{
    HILOGI("[Test] Begin TestDLLiteGetFeatureInterpreterByFeatureName001");

    FeatureConfig featureConfig;
    int registerTimes = MAX_FEATURE_NUM;
    std::vector<std::shared_ptr<FeatureInterpreter>> featureInterpreters;
    std::shared_ptr<FeatureInterpreter> featureInterpreter;
    for (int i = 1; i <= registerTimes; i++) {
        featureConfig.featureName = FEATURE_NAME + std::to_string(i);
        featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
        EXPECT_NE(nullptr, featureInterpreter) << featureConfig.featureName;
        if (featureInterpreter != nullptr) {
            featureInterpreters.push_back(featureInterpreter);
        }
    }

    // GetFeatureNameList
    std::vector<std::string> featureNameList = FeatureInterpreter::GetFeatureNameList();
    EXPECT_EQ(featureNameList.size(), registerTimes) << featureNameList.size();

    // GetFeatureInterpreter
    for (auto featureName : featureNameList) {
        featureInterpreter = FeatureInterpreter::GetFeatureInterpreterByFeatureName(featureName);
        EXPECT_NE(nullptr, featureInterpreter) << featureName;
    }

    ReturnCode returnCode;
    while (!featureInterpreters.empty() && registerTimes--) {
        returnCode = featureInterpreter->UnregisterFeature(featureInterpreters.back());
        EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
        featureInterpreters.pop_back();
    }
}

/**
 * @tc.name: TestDLLiteGetModelInterpreterByModelName001
 * @tc.desc: Test DLLite GetModelInterpreterByModelName API.
 * @tc.type: FUNC
 * @tc.require: AR000G4GOL
 */
HWTEST_F(FeatureInterpreterTest, TestDLLiteGetModelInterpreterByModelName001, TestSize.Level0)
{
    HILOGI("[Test] Begin TestDLLiteGetModelInterpreterByModelName001");

    FeatureConfig featureConfig;
    featureConfig.featureName = FEATURE_NAME;
    std::shared_ptr<FeatureInterpreter> featureInterpreter = nullptr;
    featureInterpreter = FeatureInterpreter::RegisterFeature(featureConfig);
    EXPECT_NE(nullptr, featureInterpreter);

    int createTimes = MAX_MODEL_NUM;
    ModelConfig modelConfig;
    modelConfig.modelPath_ = INPUT_MODEL_PATH;
    modelConfig.weightPath_ = INPUT_WEIGHT_PATH;
    modelConfig.inferFrameworkType_ = InferFrameworkType::MINDSPORE;

    std::shared_ptr<ModelInterpreter> modelInterpreter = nullptr;
    std::vector<std::shared_ptr<ModelInterpreter>> modelInterpreters;
    for (int i = 1; i <= createTimes; i++) {
        modelConfig.modelName_ = INPUT_MODEL_NAME + std::to_string(i);
        modelInterpreter = featureInterpreter->CreateModelInterpreter(modelConfig);
        EXPECT_NE(nullptr, modelInterpreter);
        if (modelInterpreter != nullptr) {
            modelInterpreters.push_back(modelInterpreter);
        }
    }

    // GetModelNameList
    std::vector<std::string> modelNameList = featureInterpreter->GetModelNameList();
    EXPECT_EQ(modelNameList.size(), createTimes) << modelNameList.size();

    // GetModelInterpreter
    for (auto modelName : modelNameList) {
        modelInterpreter = featureInterpreter->GetModelInterpreterByModelName(modelName);
        EXPECT_NE(nullptr, modelInterpreter) << modelName;
    }

    ReturnCode returnCode;
    // destroy all modelInterpreters
    while (!modelInterpreters.empty() && createTimes--) {
        returnCode = featureInterpreter->DestroyModelInterpreter(modelInterpreters.back());
        EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
        modelInterpreters.pop_back();
    }

    returnCode = FeatureInterpreter::UnregisterFeature(featureInterpreter);
    EXPECT_EQ(ReturnCode::SUCCESS, returnCode);
}
