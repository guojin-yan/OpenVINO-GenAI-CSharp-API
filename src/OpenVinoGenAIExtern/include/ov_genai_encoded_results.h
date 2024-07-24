// Copyright (C) 2024 Yan Guojin. All rights reserved.
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_encoded_results.h
* @brief This is a header file for the ov_genai_encoded_results C API, which is a C wrapper for ov::genai::EncodedResults.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/7/24
*/

#pragma once
#include "openvino/genai/generation_config.hpp"
#include "openvino/genai/llm_pipeline.hpp"
#include "openvino/genai/streamer_base.hpp"
#include "openvino/genai/tokenizer.hpp"
#include "openvino/genai/visibility.hpp"

#include "ov_genai_common.h"

/**
 * @struct ov_genai_encoded_results_t
 * @ingroup ov_genai_encoded_results_c_api
 * @brief type define ov_genai_encoded_results_t from ov_genai_encoded_results
 */
typedef struct ov_genai_encoded_results ov_genai_encoded_results_t;

OPENVINO_C_API(ov_status_e)
ov_genai_encoded_results_create(ov_genai_encoded_results_t** encoded_results);

OPENVINO_C_API(void)
ov_genai_encoded_results_free(ov_genai_encoded_results_t* encoded_results);