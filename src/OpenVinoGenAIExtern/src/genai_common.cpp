// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//
#include "genai_common.h"

std::vector<std::string> char_arrays_to_str_array(const ov_genai_char_arrays_t inputs_array) {
    std::vector<std::string> strs;
    for (int i = 0; i < inputs_array.size; ++i)
    {
        strs.push_back(std::string(inputs_array.string_array[i]));
    }
    return strs;
}

size_t timepoint_to_nanoseconds(std::chrono::steady_clock::time_point timepoint) {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(timepoint.time_since_epoch()).count();
}


std::chrono::steady_clock::time_point nanoseconds_to_timepoint(size_t nanoseconds) {
    return std::chrono::steady_clock::time_point(std::chrono::nanoseconds(nanoseconds));
}




char* str_to_char_array(const std::string& str) {
    std::unique_ptr<char> _char_array(new char[str.length() + 1]);
    char* char_array = _char_array.release();
    std::copy_n(str.c_str(), str.length() + 1, char_array);
    return char_array;
}

static std::string last_err_msg;
static std::mutex last_msg_mutex;
void dup_last_err_msg(const char* msg) {
    std::lock_guard<std::mutex> lock(last_msg_mutex);
    last_err_msg = std::string(msg);
}
const char* ov_genai_get_last_err_msg() {
    std::lock_guard<std::mutex> lock(last_msg_mutex);
    char* res = nullptr;
    if (!last_err_msg.empty()) {
        res = str_to_char_array(last_err_msg);
    }
    return res;
}
