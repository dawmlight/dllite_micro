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

#include "infer_wrapper_factory.h"

#include <cerrno>
#include <dlfcn.h>

#include "aie_log.h"

namespace OHOS {
namespace AI {
namespace dllite {
/**
 * Create wrapper by infer framework type
 *
 * @param [in] modelConfig model config for wrapper
 * @param [out] handle the handle get from dlopen
 * @return return the pointer of wrapper
 */
InferFramework *InferWrapperFactory::CreateWrapper(ModelConfig &modelConfig, void *&handle)
{
    handle = nullptr;

    switch (modelConfig.inferFrameworkType_) {
        case InferFrameworkType::MINDSPORE: {
            handle = dlopen("libdlliteclient_mslite_for_iot.so", RTLD_LAZY | RTLD_NODELETE);
            break;
        }
        default: {
            HILOGE("Unknown framework type");
            return nullptr;
        }
    }

    if (handle == nullptr) {
        HILOGE("dlopen error, errno: %d.", errno);
        return nullptr;
    }

    void *(*createMethod)(void *) = (void *(*)(void *))dlsym(handle, "CreateWrapper");
    if (createMethod == nullptr) {
        HILOGE("dlsym error, errno: %d.", errno);
        (void)dlclose(handle);
        handle = nullptr;
        return nullptr;
    }

    void *inferWrapper = createMethod(reinterpret_cast<void *>(&modelConfig));
    if (inferWrapper == nullptr) {
        HILOGE("Unsuccessfully create wrapper.");
        (void)dlclose(handle);
        handle = nullptr;
        return nullptr;
    }

    return reinterpret_cast<InferFramework *>(inferWrapper);
}

/**
 * create wrapper by infer framework type
 *
 * @param [in] handle the handle get from dlopen
 * @return return the return code of function execution.
 */
ReturnCode InferWrapperFactory::DestroyWrapper(void *handle)
{
    if (handle == nullptr) {
        HILOGE("Null ptr while destroy wrapper.");
        return ReturnCode::INVALID_POINTER;
    }

    int rtn = dlclose(handle);
    if (rtn != 0) {
        HILOGE("Failed to close lib, errno: %d.", errno);
        return ReturnCode::UNKNOWN;
    }

    return ReturnCode::SUCCESS;
}
} // namespace dllite
} // namespace AI
} // namespace OHOS
