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

