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
	ov_genai_raw_perf_metrics_t** perf_metrics) {}

ov_status_e
ov_genai_raw_perf_metrics_free(
    ov_genai_raw_perf_metrics_t* perf_metrics){}

ov_status_e
ov_genai_raw_perf_metrics_get_generate_durations(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t** micro_seconds,
    size_t* length){}

ov_status_e
ov_genai_raw_perf_metrics_set_generate_durations(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t* micro_seconds,
    size_t* length){}

ov_status_e
ov_genai_raw_perf_metrics_get_tokenization_durations(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t** tokenization_durations,
    size_t* length){}

ov_status_e
ov_genai_raw_perf_metrics_set_tokenization_durations(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t* tokenization_durations,
    size_t* length){}

ov_status_e
ov_genai_raw_perf_metrics_get_detokenization_durations(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t** detokenization_durations,
    size_t* length){}

ov_status_e
ov_genai_raw_perf_metrics_set_detokenization_durations(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t* detokenization_durations,
    size_t* length){}

ov_status_e
ov_genai_raw_perf_metrics_get_m_times_to_first_token(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t** m_times_to_first_token,
    size_t* length){}

ov_status_e
ov_genai_raw_perf_metrics_set_m_times_to_first_token(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t* m_times_to_first_token,
    size_t* length){}

ov_status_e
ov_genai_raw_perf_metrics_get_m_new_token_times(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t** m_new_token_times,
    size_t* length){}

ov_status_e
ov_genai_raw_perf_metrics_set_m_new_token_times(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t* m_new_token_times,
    size_t* length){}

ov_status_e
ov_genai_raw_perf_metrics_get_m_batch_sizes(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t** m_batch_sizes,
    size_t* length){}

ov_status_e
ov_genai_raw_perf_metrics_set_m_batch_sizes(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t* m_batch_sizes,
    size_t* length){}

ov_status_e
ov_genai_raw_perf_metrics_get_m_durations(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t** m_durations,
    size_t* length){}

ov_status_e
ov_genai_raw_perf_metrics_set_m_durations(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t* m_durations,
    size_t* length){}

ov_status_e
ov_genai_raw_perf_metrics_get_num_generated_tokens(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t* num_generated_tokens){}

ov_status_e
ov_genai_raw_perf_metrics_set_num_generated_tokens(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t* num_generated_tokens){}

ov_status_e
ov_genai_raw_perf_metrics_get_num_input_tokens(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t* num_input_tokens){}

ov_status_e
ov_genai_raw_perf_metrics_set_num_input_tokens(
    ov_genai_raw_perf_metrics_t* perf_metrics,
    size_t* num_input_tokens){}