// Copyright (C) 2024 Yan Guojin
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_raw_perf_metrics.h
* @brief This is a header file for the ov_genai_perf_metrics C API, which is a C wrapper for ov::genai::PerfMetrics.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/9/8
*/


#pragma once
#include "openvino/genai/generation_config.hpp"
#include "openvino/genai/llm_pipeline.hpp"
#include "openvino/genai/perf_metrics.hpp"
#include "openvino/genai/streamer_base.hpp"
#include "openvino/genai/tokenizer.hpp"
#include "openvino/genai/visibility.hpp"

#include "ov_genai_common.h"

/**
 * @struct ov_genai_mean_std_pair_t
 * @ingroup ov_genai_perf_metrics_c_api
 * @brief Structure to store mean and standart deviation values.
 */
typedef struct {
    float mean;
    float std;
} ov_genai_mean_std_pair_t;

/**
* @struct ov_genai_perf_metrics_t
* @brief This is an interface of ov::genai::PerfMetrics.
* Structure to store performance metric for each generation.
*/
typedef struct ov_genai_perf_metrics ov_genai_perf_metrics_t;

/**
 * @brief Constructs OpenVINO PerfMetrics instance by default.
 * @ingroup ov_genai_perf_metrics_c_api
 * @param generation_config A pointer to the newly created ov_genai_perf_metrics_t.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_perf_metrics_create(
	ov_genai_perf_metrics_t** perf_metrics);

/**
 * @brief Releases an OpenVINO PerfMetrics instance.
 * @ingroup ov_genai_perf_metrics_c_api
 * @param perf_metrics A pointer to the ov_genai_perf_metrics_t instance to be freed.
 */
OPENVINO_C_API(void)
ov_genai_perf_metrics_free(
	ov_genai_perf_metrics_t* perf_metrics);


OPENVINO_C_API(ov_status_e)
ov_genai_get_load_time(
	ov_genai_perf_metrics_t* perf_metrics,
	float* load_time);


OPENVINO_C_API(ov_status_e)
ov_genai_get_num_generated_tokens(ov_genai_perf_metrics_t* perf_metrics,
	size_t* num_generated_tokens);


OPENVINO_C_API(ov_status_e)
ov_genai_get_num_input_tokens(
	ov_genai_perf_metrics_t* perf_metrics,
	size_t* num_input_tokens);



OPENVINO_C_API(ov_status_e)
ov_genai_get_ttft(
	ov_genai_perf_metrics_t* perf_metrics,
	ov_genai_mean_std_pair_t* ttft);


OPENVINO_C_API(ov_status_e)
ov_genai_get_tpot(
	ov_genai_perf_metrics_t* perf_metrics,
	ov_genai_mean_std_pair_t* tpot);

OPENVINO_C_API(ov_status_e)
ov_genai_get_throughput(
	ov_genai_perf_metrics_t* perf_metrics,
	ov_genai_mean_std_pair_t* throughput);


OPENVINO_C_API(ov_status_e)
ov_genai_get_generate_duration(
	ov_genai_perf_metrics_t* perf_metrics,
	ov_genai_mean_std_pair_t* generate_duration);

OPENVINO_C_API(ov_status_e)
ov_genai_get_tokenization_duration(
	ov_genai_perf_metrics_t* perf_metrics,
	ov_genai_mean_std_pair_t* tokenization_duration);

OPENVINO_C_API(ov_status_e)
ov_genai_get_detokenization_duration(
	ov_genai_perf_metrics_t* perf_metrics,
	ov_genai_mean_std_pair_t* detokenization_duration);


OPENVINO_C_API(ov_status_e)
ov_genai_get_evaluated_flag(
	ov_genai_perf_metrics_t* perf_metrics,
	int* evaluated_flag);


OPENVINO_C_API(ov_status_e)
ov_genai_set_evaluated_flag(
	ov_genai_perf_metrics_t* perf_metrics,
	int evaluated_flag);

OPENVINO_C_API(ov_status_e)
ov_genai_evaluate_statistics(ov_genai_perf_metrics_t* perf_metrics);




OPENVINO_C_API(ov_status_e)
ov_genai_operator_add(
	ov_genai_perf_metrics_t* perf_metrics,
	ov_genai_perf_metrics_t** new_perf_metrics);
