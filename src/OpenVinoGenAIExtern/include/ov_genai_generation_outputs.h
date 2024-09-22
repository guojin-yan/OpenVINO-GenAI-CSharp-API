// Copyright (C) 2024 Yan Guojin
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_generation_outputs.h
* @brief This is a header file for the ov_genai_generation_output and ov_genai_generation_outputs C API,
* which is a C wrapper for ov::genai::GenerationOutput and ov::genai::GenerationOutputs.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/9/17
*/


#pragma once
#include "openvino/genai//generation_handle.hpp"

#include "ov_genai_common.h"
#include "genai_common.h"

/**
* @struct ov_genai_generation_output_t
* @brief This is an interface of ov::genai::GenerationOutput.
*/
typedef struct ov_genai_generation_output ov_genai_generation_output_t;


/**
* @struct ov_genai_generation_outputs_t
* @brief This is an interface of ov::genai::GenerationOutputs.
*/
typedef struct ov_genai_generation_outputs ov_genai_generation_outputs_t;

OPENVINO_C_API(void)
ov_genai_generation_output_free(
	ov_genai_generation_output_t* generation_output);

OPENVINO_C_API(ov_status_e)
ov_genai_generation_output_get_generated_ids(
	ov_genai_generation_output_t* generation_output,
	int64_t* generated_ids,
	size_t* size);

OPENVINO_C_API(ov_status_e)
ov_genai_generation_output_get_score(
	ov_genai_generation_output_t* generation_output,
	float* score);

OPENVINO_C_API(ov_status_e)
ov_genai_generation_output_get_generated_log_probs(
	ov_genai_generation_output_t* generation_output,
	float* generated_log_probs,
	size_t* size);


OPENVINO_C_API(ov_status_e)
ov_genai_generation_output_get_finish_reason(
	ov_genai_generation_output_t* generation_output,
	int* finish_reason);

OPENVINO_C_API(void)
ov_genai_generation_outputs_free(
	ov_genai_generation_outputs_t* generation_outputs);

OPENVINO_C_API(ov_status_e)
ov_genai_generation_outputs_at(
	ov_genai_generation_outputs_t* generation_outputs,
	uint64_t key,
	ov_genai_generation_output_t** generation_output);