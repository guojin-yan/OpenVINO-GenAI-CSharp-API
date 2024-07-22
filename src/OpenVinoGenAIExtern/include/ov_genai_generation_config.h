// Copyright (C) 2024 Yan Guojin. All rights reserved.
// SPDX-License-Identifier: Apache-2.0
//


/**
* @file ov_genai_generation_config.h
* @brief This is a header file for the ov_genai_generation_config C API, which is a C wrapper for ov::genai::GenerationConfig.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/7/21
*/

#pragma once
#include "openvino/genai/generation_config.hpp"
#include "openvino/genai/llm_pipeline.hpp"
#include "openvino/genai/streamer_base.hpp"
#include "openvino/genai/tokenizer.hpp"
#include "openvino/genai/visibility.hpp"

#include "ov_genai_common.h"


/**
 * @struct ov_genai_generation_config_t
 * @ingroup ov_genai_generation_config_c_api
 * @brief type define ov_genai_generation_config_t from ov_genai_generation_config
 */
typedef struct ov_genai_generation_config ov_genai_generation_config_t;


/**
 * @brief Constructs OpenVINO GenAI GenerationConfig instance by default.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the newly created ov_genai_generation_config_t.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_create(ov_genai_generation_config_t** generation_config);

/**
 * @brief Constructs OpenVINO GenAI GenerationConfig instance by default.
 * @ingroup ov_genai_generation_config_c_api
 * @param json_path 
 * @param generation_config A pointer to the newly created ov_genai_generation_config_t.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_create_with_json(const char* json_path,
    ov_genai_generation_config_t** generation_config);


OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_get_max_new_tokens(const ov_genai_generation_config_t* generation_config,
    size_t prompt_length, size_t* max_new_tokens);


OPENVINO_C_API(bool)
ov_genai_generation_config_is_greedy_decoding(const ov_genai_generation_config_t* generation_config);


OPENVINO_C_API(bool)
ov_genai_generation_config_is_beam_search(const ov_genai_generation_config_t* generation_config);


OPENVINO_C_API(bool)
ov_genai_generation_config_is_multinomial(const ov_genai_generation_config_t* generation_config);

OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_update_generation_config(const ov_genai_generation_config_t* generation_config, 
    const size_t property_args_size, ...);

/**
 * @brief Checks that are no conflicting parameters, e.g. do_sample=true and num_beams > 1.
 * @ingroup ov_genai_generation_config_c_api
 * @param core A pointer to the ov_genai_generation_config_t.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
validate(const ov_genai_generation_config_t* generation_config);