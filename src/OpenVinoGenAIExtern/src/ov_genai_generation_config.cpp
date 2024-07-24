// Copyright (C) 2024 Yan Guojin
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_generation_config.cpp
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


ov_status_e ov_genai_generation_config_get_max_new_tokens_with_prompt(
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


// Generic
ov_status_e ov_genai_generation_config_get_max_new_tokens(const ov_genai_generation_config_t* generation_config,
    size_t* max_new_tokens) {
    if (!generation_config || !max_new_tokens) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        *max_new_tokens = generation_config->object->max_new_tokens;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_set_max_new_tokens(const ov_genai_generation_config_t* generation_config,
    size_t max_new_tokens) {
    if (!generation_config) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        generation_config->object->max_new_tokens = max_new_tokens;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e ov_genai_generation_config_get_max_length(const ov_genai_generation_config_t* generation_config,
    size_t* max_length) {
    if (!generation_config || !max_length) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        *max_length = generation_config->object->max_length;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e ov_genai_generation_config_set_max_length(const ov_genai_generation_config_t* generation_config,
    size_t max_length) {
    if (!generation_config) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        generation_config->object->max_length = max_length;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_get_ignore_eos(const ov_genai_generation_config_t* generation_config,
    bool* ignore_eos) {
    if (!ignore_eos || !ignore_eos) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        *ignore_eos = generation_config->object->ignore_eos;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_set_ignore_eos(const ov_genai_generation_config_t* generation_config,
    bool ignore_eos) {
    if (!generation_config) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        generation_config->object->ignore_eos = ignore_eos;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

// Beam search specific

ov_status_e ov_genai_generation_config_get_num_beam_groups(const ov_genai_generation_config_t* generation_config,
    size_t* num_beam_groups) {
    if (!generation_config || !num_beam_groups) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        *num_beam_groups = generation_config->object->num_beam_groups;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_set_num_beam_groups(const ov_genai_generation_config_t* generation_config,
    size_t num_beam_groups) {
    if (!generation_config) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        generation_config->object->num_beam_groups = num_beam_groups;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}



ov_status_e ov_genai_generation_config_get_num_beams(const ov_genai_generation_config_t* generation_config,
    size_t* num_beams) {
    if (!generation_config || !num_beams) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        *num_beams = generation_config->object->num_beams;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_set_num_beams(const ov_genai_generation_config_t* generation_config,
    size_t num_beams) {
    if (!generation_config) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        generation_config->object->num_beams = num_beams;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_get_diversity_penalty(const ov_genai_generation_config_t* generation_config,
    float* diversity_penalty) {
    if (!generation_config || !diversity_penalty) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        *diversity_penalty = generation_config->object->diversity_penalty;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_set_diversity_penalty(const ov_genai_generation_config_t* generation_config,
    float diversity_penalty) {
    if (!generation_config) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        generation_config->object->diversity_penalty = diversity_penalty;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_get_length_penalty(const ov_genai_generation_config_t* generation_config,
    float* length_penalty) {
    if (!generation_config || !length_penalty) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        *length_penalty = generation_config->object->length_penalty;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e ov_genai_generation_config_set_length_penalty(const ov_genai_generation_config_t* generation_config,
    float length_penalty) {
    if (!generation_config) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        generation_config->object->length_penalty = length_penalty;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_get_num_return_sequences(const ov_genai_generation_config_t* generation_config,
    size_t* num_return_sequences) {
    if (!generation_config || !num_return_sequences) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        *num_return_sequences = generation_config->object->num_return_sequences;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_set_num_return_sequences(const ov_genai_generation_config_t* generation_config,
    size_t num_return_sequences) {
    if (!generation_config) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        generation_config->object->num_return_sequences = num_return_sequences;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_get_no_repeat_ngram_size(const ov_genai_generation_config_t* generation_config,
    size_t* no_repeat_ngram_size) {
    if (!generation_config || !no_repeat_ngram_size) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        *no_repeat_ngram_size = generation_config->object->no_repeat_ngram_size;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_set_no_repeat_ngram_size(const ov_genai_generation_config_t* generation_config,
    size_t no_repeat_ngram_size) {
    if (!generation_config) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        generation_config->object->no_repeat_ngram_size = no_repeat_ngram_size;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_get_stop_criteria(const ov_genai_generation_config_t* generation_config,
    ov::genai::StopCriteria* stop_criteria) {
    if (!generation_config || !stop_criteria) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        *stop_criteria = generation_config->object->stop_criteria;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e ov_genai_generation_config_set_stop_criteria(const ov_genai_generation_config_t* generation_config,
    ov::genai::StopCriteria stop_criteria) {
    if (!generation_config) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        generation_config->object->stop_criteria = stop_criteria;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

// Multinomial

ov_status_e ov_genai_generation_config_get_temperature(const ov_genai_generation_config_t* generation_config,
    float* temperature) {
    if (!generation_config || !temperature) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        *temperature = generation_config->object->temperature;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_set_temperature(const ov_genai_generation_config_t* generation_config,
    float temperature) {
    if (!generation_config) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        generation_config->object->temperature = temperature;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_get_top_p(const ov_genai_generation_config_t* generation_config,
    float* top_p) {
    if (!generation_config || !top_p) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        *top_p = generation_config->object->top_p;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_set_top_p(const ov_genai_generation_config_t* generation_config,
    float top_p) {
    if (!generation_config) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        generation_config->object->top_p = top_p;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_get_top_k(const ov_genai_generation_config_t* generation_config,
    size_t* top_k) {
    if (!generation_config || !top_k) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        *top_k = generation_config->object->top_k;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_set_top_k(const ov_genai_generation_config_t* generation_config,
    size_t top_k) {
    if (!generation_config) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        generation_config->object->top_k = top_k;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_get_do_sample(const ov_genai_generation_config_t* generation_config,
    bool* do_sample) {
    if (!generation_config || !do_sample) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        *do_sample = generation_config->object->do_sample;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_set_do_sample(const ov_genai_generation_config_t* generation_config,
    bool do_sample) {
    if (!generation_config) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        generation_config->object->do_sample = do_sample;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_get_repetition_penalty(const ov_genai_generation_config_t* generation_config,
    float* repetition_penalty) {
    if (!generation_config || !repetition_penalty) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        *repetition_penalty = generation_config->object->repetition_penalty;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e ov_genai_generation_config_set_repetition_penalty(const ov_genai_generation_config_t* generation_config,
    float repetition_penalty) {
    if (!generation_config) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        generation_config->object->repetition_penalty = repetition_penalty;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


// EOS special token

ov_status_e ov_genai_generation_config_get_eos_token_id(const ov_genai_generation_config_t* generation_config,
    int64_t* eos_token_id) {
    if (!generation_config || !eos_token_id) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        *eos_token_id = generation_config->object->eos_token_id;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e ov_genai_generation_config_set_eos_token_id(const ov_genai_generation_config_t* generation_config,
    int64_t eos_token_id) {
    if (!generation_config) {
        return ov_status_e::INVALID_C_PARAM;
    }
    try {
        generation_config->object->eos_token_id = eos_token_id;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

void ov_genai_generation_config_free(const ov_genai_generation_config_t* generation_config) {
    if (generation_config)
        delete generation_config;
}