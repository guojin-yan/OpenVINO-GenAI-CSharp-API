// Copyright (C) 2024 Yan Guojin
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_generation_outputs.h
* @brief This is a header file for the ov_genai_generation_handle C API,
* which is a C wrapper for ov::genai::GenerationHandleImpl.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/9/17
*/


#pragma once
#include "openvino/genai//generation_handle.hpp"

#include "ov_genai_common.h"
#include "genai_common.h"
#include "ov_genai_generation_outputs.h"

/**
* @struct ov_genai_generation_handle_t
* @brief This is an interface of ov::genai::GenerationHandleImpl.
*/
typedef struct ov_genai_generation_handle ov_genai_generation_handle_t;


OPENVINO_C_API(void)
ov_genai_generation_handle_free(
	ov_genai_generation_handle_t* generation_handle);

OPENVINO_C_API(ov_status_e)
ov_genai_generation_handle_get_status(
	ov_genai_generation_handle_t* generation_handle,
	int* status);

OPENVINO_C_API(ov_status_e)
ov_genai_generation_handle_can_read(
	ov_genai_generation_handle_t* generation_handle,
	int* can_read);


OPENVINO_C_API(ov_status_e)
ov_genai_generation_handle_back(
	ov_genai_generation_handle_t* generation_handle,
	ov_genai_generation_outputs_t** generation_outputs);

OPENVINO_C_API(ov_status_e)
ov_genai_generation_handle_read(
	ov_genai_generation_handle_t* generation_handle,
	ov_genai_generation_outputs_t** generation_outputs);

OPENVINO_C_API(ov_status_e)
ov_genai_generation_handle_read_all(
	ov_genai_generation_handle_t* generation_handle,
	ov_genai_generation_output_t** generation_output,
	size_t* size);