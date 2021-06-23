/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef DLLITE_HETERNEURAL_UTILS_H
#define DLLITE_HETERNEURAL_UTILS_H

#include "aie_log.h"
#include "type_define.h"
#include <fstream>
#include <string>

namespace OHOS {
namespace AI {
namespace dllite {
/**
 * Read File.
 *
 * @param [in] file the file to be read.
 * @param [out] modelBuffer the result read data.
 * @return return he return code of funtion execution.
 */
ReturnCode ReadFile(const std::string &file, std::pair<char *, size_t> &modelBuffer);

/**
 * Release File.
 *
 * @param [in] modelBuffer the buffer to be released.
 * @return return the return code of function execution.
 */
void ReleaseFile(std::pair<char *, size_t> &modelBuffer);
} // namespace dllite
} // namespace AI
} // namespace OHOS

#endif
