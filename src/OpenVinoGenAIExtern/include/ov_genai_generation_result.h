// Copyright (C) 2024 Yan Guojin
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_perf_metrics.h
* @brief This is a header file for the ov_genai_generation_result C API, which is a C wrapper for ov::genai::GenerationResult.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/9/8
*/


#pragma once
#include "openvino/genai//generation_handle.hpp"

#include "ov_genai_common.h"
#include "genai_common.h"
/**
* @struct ov_genai_generation_result
* @brief This is an interface of ov::genai::GenerationResult.
*/
typedef struct ov_genai_generation_result ov_genai_generation_result_t;

void
ov_genai_generation_result_free(
	ov_genai_generation_result_t* generation_result);

OPENVINO_C_API(ov_status_e)
ov_genai_generation_result_get_request_id(
	ov_genai_generation_result_t* generation_result,
	uint64_t* request_id);

OPENVINO_C_API(ov_status_e)
ov_genai_generation_result_get_generation_ids(
	ov_genai_generation_result_t* generation_result,
	ov_genai_char_arrays_t* generation_ids);


OPENVINO_C_API(ov_status_e)
ov_genai_generation_result_get_scores(
	ov_genai_generation_result_t* generation_result,
	float* request_id,
	size_t* scores);


OPENVINO_C_API(ov_status_e)
ov_genai_generation_result_get_status(
	ov_genai_generation_result_t* generation_result,
	int* status);