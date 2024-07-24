// Copyright (C) 2024 Yan Guojin. All rights reserved.
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_llm_pipeline.h
* @brief This is a header file for the ov_genai_llm_pipeline C API, which is a C wrapper for ov::genai::LLMPipeline.
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
#include "ov_infer_request.h"
#include "ov_genai_generation_config.h"
#include "ov_genai_tokenizer.h"


/**
 * @struct ov_genai_llm_pipeline_t
 * @ingroup ov_genai_llm_pipeline_c_api
 * @brief type define ov_genai_llm_pipeline_t from ov_genai_llm_pipeline
 */
typedef struct ov_genai_llm_pipeline ov_genai_llm_pipeline_t;


OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_create(ov_genai_llm_pipeline_t** llm_pipeline);


OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_create_with_model_path(
	ov_genai_llm_pipeline_t** llm_pipeline, 
	const char* model_path, 
	const char* device_name, ...);

OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_create_with_request(
	ov_genai_llm_pipeline_t** llm_pipeline, 
	ov_infer_request_t* infer_request, 
	ov_genai_tokenizer_t* tokenizer, 
	ov_genai_generation_config_t* generation_config);


OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_create_with_model_path_tokenizer(
	ov_genai_llm_pipeline_t** llm_pipeline,
	const char* model_path,
	ov_genai_tokenizer_t* tokenizer,
	const char* device_name, ...);


OPENVINO_C_API(void)
ov_genai_llm_pipeline_free(ov_genai_llm_pipeline_t* llm_pipeline);