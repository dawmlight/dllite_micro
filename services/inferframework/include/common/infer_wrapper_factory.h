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

#ifndef INFER_WRAPPER_FACTORY_H
#define INFER_WRAPPER_FACTORY_H

#include "infer_framework.h"
#include "model_config.h"

namespace OHOS {
namespace AI {
namespace dllite {
class InferWrapperFactory {
public:
    static InferFramework *CreateWrapper(ModelConfig &modelConfig, void *&handle);
    static ReturnCode DestroyWrapper(void *handle);
};
} // namespace dllite
} // namespace AI
} // namespace OHOS

#endif // INFER_WRAPPER_FACTORY_H
