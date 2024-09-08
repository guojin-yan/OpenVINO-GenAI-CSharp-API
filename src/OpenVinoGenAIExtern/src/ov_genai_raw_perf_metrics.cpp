// Copyright (C) 2024 Yan Guojin
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_raw_perf_metrics.cpp
* @brief This is a header file for the ov_genai_raw_perf_metrics C API, which is a C wrapper for ov::genai::RawPerfMetrics.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/8/20
*/

#include "ov_genai_raw_perf_metrics.h"
#include <memory>

#include "genai_common.h"
#include <cstdarg>


ov_status_e ov_genai_raw_perf_metrics_create(
	ov_genai_raw_perf_metrics_t** perf_metrics) {
    if (!perf_metrics) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        std::unique_ptr<ov_genai_raw_perf_metrics_t> _perf_metrics(new ov_genai_raw_perf_metrics_t);
        _perf_metrics->object = std::make_shared<ov::genai::RawPerfMetrics>();
        *perf_metrics = _perf_metrics.release();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

void
ov_genai_raw_perf_metrics_free(
    ov_genai_raw_perf_metrics_t* perf_metrics){
    if (perf_metrics)
        delete perf_metrics;
}

ov_status_e
ov_genai_raw_perf_metrics_get_generate_durations(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    float** micro_seconds,
    size_t* length){

    if (!perf_metrics || !micro_seconds || !length) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        auto tmp = perf_metrics->object->generate_durations;
        *length = tmp.size();
        float* array = new float[*length];

        for (int i = 0; i < *length; ++i) {
            array[i] = tmp[i].count();
        }
        *micro_seconds = array;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_raw_perf_metrics_set_generate_durations(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    float* micro_seconds,
    size_t length){

    if (!perf_metrics || !micro_seconds || !length) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        perf_metrics->object->generate_durations.resize(length);
        for (int i = 0; i < length; ++i) {
            perf_metrics->object->generate_durations[i] = MicroSeconds(micro_seconds[i]);
        }
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_raw_perf_metrics_get_tokenization_durations(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    float** tokenization_durations,
    size_t* length){

    if (!perf_metrics || !tokenization_durations || !length) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        auto tmp = perf_metrics->object->tokenization_durations;
        *length = tmp.size();
        float* array = new float[*length];

        for (int i = 0; i < *length; ++i) {
            array[i] = tmp[i].count();
        }
        *tokenization_durations = array;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_raw_perf_metrics_set_tokenization_durations(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    float* tokenization_durations,
    size_t length){
    if (!perf_metrics || !tokenization_durations || !length) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        perf_metrics->object->tokenization_durations.resize(length);
        for (int i = 0; i < length; ++i) {
            perf_metrics->object->tokenization_durations[i] 
                = MicroSeconds(tokenization_durations[i]);
        }
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_raw_perf_metrics_get_detokenization_durations(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    float** detokenization_durations,
    size_t* length){

    if (!perf_metrics || !detokenization_durations || !length) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        auto tmp = perf_metrics->object->detokenization_durations;
        *length = tmp.size();
        float* array = new float[*length];

        for (int i = 0; i < *length; ++i) {
            array[i] = tmp[i].count();
        }
        *detokenization_durations = array;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_raw_perf_metrics_set_detokenization_durations(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    float* detokenization_durations,
    size_t length){

    if (!perf_metrics || !detokenization_durations || !length) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        perf_metrics->object->detokenization_durations.resize(length);
        for (int i = 0; i < length; ++i) {
            perf_metrics->object->detokenization_durations[i] 
                = MicroSeconds(detokenization_durations[i]);
        }
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_raw_perf_metrics_get_m_times_to_first_token(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    float** m_times_to_first_token,
    size_t* length){

    if (!perf_metrics || !m_times_to_first_token || !length) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        auto tmp = perf_metrics->object->m_times_to_first_token;
        *length = tmp.size();
        float* array = new float[*length];

        for (int i = 0; i < *length; ++i) {
            array[i] = tmp[i].count();
        }
        *m_times_to_first_token = array;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_raw_perf_metrics_set_m_times_to_first_token(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    float* m_times_to_first_token,
    size_t length){

    if (!perf_metrics || !m_times_to_first_token || !length) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        perf_metrics->object->m_times_to_first_token.resize(length);
        for (int i = 0; i < length; ++i) {
            perf_metrics->object->m_times_to_first_token[i] 
                = MicroSeconds(m_times_to_first_token[i]);
        }
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_raw_perf_metrics_get_m_new_token_times(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t** m_new_token_times,
    size_t* length){

    if (!perf_metrics || !m_new_token_times || !length) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        auto tmp = perf_metrics->object->m_new_token_times;
        *length = tmp.size();
        size_t* array = new size_t[*length];

        for (int i = 0; i < *length; ++i) {
            array[i] = timepoint_to_nanoseconds(tmp[i]);
        }
        *m_new_token_times = array;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_raw_perf_metrics_set_m_new_token_times(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t* m_new_token_times,
    size_t length){

    if (!perf_metrics || !m_new_token_times || !length) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        perf_metrics->object->m_new_token_times.resize(length);
        for (int i = 0; i < length; ++i) {
            perf_metrics->object->m_new_token_times[i]
                = nanoseconds_to_timepoint(m_new_token_times[i]);
        }
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_raw_perf_metrics_get_m_batch_sizes(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t** m_batch_sizes,
    size_t* length){

    if (!perf_metrics || !m_batch_sizes || !length) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        auto tmp = perf_metrics->object->m_batch_sizes;
        *length = tmp.size();
        size_t* array = new size_t[*length];

        for (int i = 0; i < *length; ++i) {
            array[i] = (tmp[i]);
        }
        *m_batch_sizes = array;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_raw_perf_metrics_set_m_batch_sizes(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t* m_batch_sizes,
    size_t length){

    if (!perf_metrics || !m_batch_sizes || !length) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        perf_metrics->object->m_batch_sizes.resize(length);
        for (int i = 0; i < length; ++i) {
            perf_metrics->object->m_batch_sizes[i]
                = (m_batch_sizes[i]);
        }
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_raw_perf_metrics_get_m_durations(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    float** m_durations,
    size_t* length){

    if (!perf_metrics || !m_durations || !length) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        auto tmp = perf_metrics->object->m_durations;
        *length = tmp.size();
        float* array = new float[*length];

        for (int i = 0; i < *length; ++i) {
            array[i] = tmp[i].count();
        }
        *m_durations = array;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_raw_perf_metrics_set_m_durations(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    float* m_durations,
    size_t length){

    if (!perf_metrics || !m_durations || !length) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        perf_metrics->object->m_durations.resize(length);
        for (int i = 0; i < length; ++i) {
            perf_metrics->object->m_durations[i]
                = MicroSeconds(m_durations[i]);
        }
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_raw_perf_metrics_get_num_generated_tokens(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t* num_generated_tokens){

    if (!perf_metrics || !num_generated_tokens) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        auto tmp = perf_metrics->object->num_generated_tokens;
        *num_generated_tokens = tmp;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_raw_perf_metrics_set_num_generated_tokens(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t num_generated_tokens){

    if (!perf_metrics || !num_generated_tokens) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        perf_metrics->object->num_input_tokens = num_generated_tokens;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_raw_perf_metrics_get_num_input_tokens(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t* num_input_tokens){

    if (!perf_metrics || !num_input_tokens) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        auto tmp = perf_metrics->object->num_input_tokens;
        *num_input_tokens = tmp;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_raw_perf_metrics_set_num_input_tokens(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t num_input_tokens){

    if (!perf_metrics || !num_input_tokens) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        perf_metrics->object->num_input_tokens = num_input_tokens;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}