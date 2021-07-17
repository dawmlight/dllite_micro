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

#include "utils.h"

namespace OHOS {
namespace AI {
namespace dllite {
namespace {
const size_t MAX_MODEL_SIZE = 200 * 1024 * 1024; // 200M
}

ReturnCode ReadFile(const std::string &file, std::pair<char *, size_t> &modelBuffer)
{
    modelBuffer.first = nullptr;
    modelBuffer.second = 0;

    std::ifstream ifs(file.c_str(), std::ios::in);
    if (!ifs) {
        HILOGE("Failed to open file");
        return ReturnCode::INVALID_PARAM;
    }

    ifs.seekg(0, std::ios::end);
    if (!ifs.good()) {
        HILOGE("seekg() is not good");
        return ReturnCode::INVALID_PARAM;
    }

    size_t fsize = ifs.tellg();
    if (fsize > MAX_MODEL_SIZE) {
        HILOGE("Superlarge model file");
        ifs.close();
        return ReturnCode::INVALID_PARAM;
    }

    if (fsize == 0) {
        HILOGE("Empty model file");
        ifs.close();
        return ReturnCode::INVALID_PARAM;
    }

    char *ptr = new (std::nothrow) char[fsize];
    if (ptr == nullptr) {
        HILOGE("Failed to create file buffer");
        ifs.close();
        return ReturnCode::INVALID_POINTER;
    }

    ifs.seekg(0, std::ios::beg);
    if (!ifs.good()) {
        HILOGE("seekg() is not good");

        delete[] ptr;
        ptr = nullptr;

        return ReturnCode::INVALID_PARAM;
    }

    ifs.read(ptr, fsize);
    if (!ifs.good()) {
        HILOGE("read() is not good");

        delete[] ptr;
        ptr = nullptr;

        return ReturnCode::INVALID_PARAM;
    }

    ifs.close();

    modelBuffer.first = ptr;
    modelBuffer.second = fsize;

    return ReturnCode::SUCCESS;
}

void ReleaseFile(std::pair<char *, size_t> &modelBuffer)
{
    if (modelBuffer.first != nullptr) {
        delete[] modelBuffer.first;
        modelBuffer.first = nullptr;
    }

    if (modelBuffer.second != 0) {
        modelBuffer.second = 0;
    }
}
} // namespace dllite
} // namespace AI
} // namespace OHOS