// Copyright (C) 2024 Yan Guojin. All rights reserved.
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_tokenized_inputs.cpp
* @brief This is a header file for the ov_genai_tokenized_inputs C API, which is a C wrapper for ov::genai::TokenizedInputs.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/8/1
*/

#include "ov_genai_tokenized_inputs.h"


ov_status_e ov_genai_tokenized_inputs_create(
	ov_genai_tokenized_inputs_t** tokenized_inputs) {

    if (!tokenized_inputs) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        std::unique_ptr<ov_genai_tokenized_inputs_t> _tokenized_inputs(new ov_genai_tokenized_inputs_t);
        _tokenized_inputs->object = std::make_shared<ov::genai::TokenizedInputs>();
        *tokenized_inputs = _tokenized_inputs.release();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

void ov_genai_tokenized_inputs_free(
    ov_genai_tokenized_inputs_t* tokenized_inputs) {
    if (tokenized_inputs)
        delete tokenized_inputs;
}

ov_status_e ov_genai_tokenized_inputs_get_input_ids(
    ov_genai_tokenized_inputs_t* tokenized_inputs,
    ov_tensor_t** tensor) {

    if (!tokenized_inputs || !tensor) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        ov::Tensor object;
        object = tokenized_inputs->object->input_ids;
        std::unique_ptr<ov_tensor_t> _tensor(new ov_tensor_t);
        _tensor->object = std::make_shared<ov::Tensor>(std::move(object));
        *tensor = _tensor.release();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_tokenized_inputs_get_attention_mask(
    ov_genai_tokenized_inputs_t* tokenized_inputs,
    ov_tensor_t** tensor) {

    if (!tokenized_inputs || !tensor) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        ov::Tensor object;
        object = tokenized_inputs->object->attention_mask;
        std::unique_ptr<ov_tensor_t> _tensor(new ov_tensor_t);
        _tensor->object = std::make_shared<ov::Tensor>(std::move(object));
        *tensor = _tensor.release();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_tokenized_inputs_set_input_ids(
    ov_genai_tokenized_inputs_t* tokenized_inputs,
    ov_tensor_t* tensor) {

    if (!tokenized_inputs || !tensor) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        tokenized_inputs->object->input_ids = *tensor->object;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_tokenized_inputs_set_attention_mask(
    ov_genai_tokenized_inputs_t* tokenized_inputs, 
    ov_tensor_t* tensor) {

    if (!tokenized_inputs || !tensor) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        tokenized_inputs->object->attention_mask = *tensor->object;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}