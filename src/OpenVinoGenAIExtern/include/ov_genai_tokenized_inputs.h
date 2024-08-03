// Copyright (C) 2024 Yan Guojin. All rights reserved.
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_tokenized_inputs.h
* @brief This is a header file for the ov_genai_tokenized_inputs C API, which is a C wrapper for ov::genai::TokenizedInputs.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/8/1
*/

#pragma once

#include "genai_common.h"
#include "ov_genai_common.h"
#include "ov_genai_tokenizer.h"
#include "ov_tensor.h"



typedef struct ov_genai_tokenized_inputs ov_genai_tokenized_inputs_t;

OPENVINO_C_API(ov_status_e)
ov_genai_tokenized_inputs_create(ov_genai_tokenized_inputs_t** tokenized_inputs);

OPENVINO_C_API(void)
ov_genai_tokenized_inputs_free(ov_genai_tokenized_inputs_t* tokenized_inputs);

OPENVINO_C_API(ov_status_e)
ov_genai_tokenized_inputs_get_input_ids(ov_genai_tokenized_inputs_t* tokenized_inputs, ov_tensor_t** tensor);


OPENVINO_C_API(ov_status_e)
ov_genai_tokenized_inputs_get_attention_mask(ov_genai_tokenized_inputs_t* tokenized_inputs, ov_tensor_t** tensor);


OPENVINO_C_API(ov_status_e)
ov_genai_tokenized_inputs_set_input_ids(ov_genai_tokenized_inputs_t* tokenized_inputs, ov_tensor_t* tensor);


OPENVINO_C_API(ov_status_e)
ov_genai_tokenized_inputs_set_attention_mask(ov_genai_tokenized_inputs_t* tokenized_inputs, ov_tensor_t* tensor);