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

#ifndef TYPE_DEFINE_H
#define TYPE_DEFINE_H

#include <string>

#include "ohos_types.h"

namespace OHOS {
namespace AI {
namespace dllite {
enum class ReturnCode {
    SUCCESS,
    UNKNOWN,
    INVALID_PARAM,
    INVALID_POINTER,
    REGISTER_REPEATED,
    REGISTER_EXCEED_NUM_LIMIT,
    UNREGISTER_WITH_TASK,
    DESTROY_WITH_TASK,
    LOAD_EXCEED_NUM_LIMIT,
    LOAD_EXCEED_MEM_LIMIT,
    LOAD_REPEATED,
    LOAD_NOT_EXECUTED,
    UNLOAD_MODEL_NOT_EXIST,
    UNLOAD_MODEL_WITH_TASK,
    UNLOAD_REPEATED,
    UNLOAD_HAS_EXECUTED,
    INVOKE_NOT_EXISTED_MODEL,
    INVOKE_TENSOR_NOT_MATCH,
    UNSUPPORTED_API,
    SERVER_BINDER_NOT_INIT,
    EMPTY_RESOURCE,
    INVALID_MODEL_FILE,
    FAILED_TO_GET_RESOURCE,
};
} // namespace dllite
} // namespace AI
} // namespace OHOS

#endif // TYPE_DEFINE_H
