// Copyright (C) 2024 Yan Guojin
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_generation_config.c
* @brief This is a header file for the ov_genai_generation_config C API, which is a C wrapper for ov::genai::GenerationConfig.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/7/21
*/

#include "ov_genai_generation_config.h"
#include <memory>

#include "genai_common.h"
#include <cstdarg>



ov_status_e ov_genai_generation_config_create_with_json(
    const char* json_path,
    ov_genai_generation_config_t** generation_config)
{
    if (!generation_config || !json_path) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        std::unique_ptr<ov_genai_generation_config_t> _generation_config(new ov_genai_generation_config_t);
        _generation_config->object = std::make_shared<ov::genai::GenerationConfig>(json_path);
        *generation_config = _generation_config.release();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e ov_genai_generation_config_create(
    ov_genai_generation_config_t** generation_config){
    return ov_genai_generation_config_create_with_json("", generation_config);
}


ov_status_e ov_genai_generation_config_get_max_new_tokens(
    const ov_genai_generation_config_t* generation_config,
    size_t prompt_length, size_t* max_new_tokens) {
    if (!generation_config || !max_new_tokens) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        if (prompt_length == 0) {
            *max_new_tokens = generation_config->object->get_max_new_tokens();
        }
        else {
            *max_new_tokens = generation_config->object->get_max_new_tokens(prompt_length);
        }
        
    }
    CATCH_OV_GENAI_EXCEPTIONS
    return ov_status_e::OK;
}


bool ov_genai_generation_config_is_greedy_decoding(
    const ov_genai_generation_config_t* generation_config) {
    if (generation_config->object->is_greedy_decoding()) {
        return true;
    }
    return false;
}


bool ov_genai_generation_config_is_beam_search(
    const ov_genai_generation_config_t* generation_config) {
    if (generation_config->object->is_beam_search()) {
        return true;
    }
    return false;
}

bool ov_genai_generation_config_is_multinomial(
    const ov_genai_generation_config_t* generation_config) {
    if (generation_config->object->is_multinomial()) {
        return true;
    }
    return false;
}


ov_status_e ov_genai_generation_config_update_generation_config(
    const ov_genai_generation_config_t* generation_config, 
    const size_t property_args_size, ...) {
    if (!generation_config || property_args_size % 2 != 0) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        ov::AnyMap property = {};
        va_list args_ptr;
        va_start(args_ptr, property_args_size);
        size_t property_size = property_args_size / 2;
        for (size_t i = 0; i < property_size; i++) {
            GET_PROPERTY_FROM_ARGS_LIST;
        }
        va_end(args_ptr);

        generation_config->object->update_generation_config(property);
    }
    CATCH_OV_GENAI_EXCEPTIONS
    return ov_status_e::OK;
}


ov_status_e validate(
    const ov_genai_generation_config_t* generation_config) {
    if (!generation_config) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        generation_config->object->validate();
    }
    CATCH_OV_GENAI_EXCEPTIONS
    return ov_status_e::OK;
}