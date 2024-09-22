// Copyright (C) 2024 Yan Guojin
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_raw_perf_metrics.h
* @brief This is a header file for the ov_genai_decoded_results C API, which is a C wrapper for ov::genai::RawPerfMetrics.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/7/24
*/


#pragma once
#include "openvino/genai/generation_config.hpp"
#include "openvino/genai/llm_pipeline.hpp"
#include "openvino/genai/perf_metrics.hpp"
#include "openvino/genai/streamer_base.hpp"
#include "openvino/genai/tokenizer.hpp"
#include "openvino/genai/visibility.hpp"

#include "ov_genai_common.h"


using TimePoint = std::chrono::steady_clock::time_point;
using MicroSeconds = std::chrono::duration<float, std::ratio<1, 1000000>>;

/**
 * @struct ov_genai_raw_perf_metrics_t
 * @ingroup ov_genai_raw_perf_metrics_c_api
 * @brief type define ov_genai_decoded_results_t from ov_genai_raw_perf_metrics
 */
typedef struct ov_genai_raw_perf_metrics ov_genai_raw_perf_metrics_t;

/**
 * @brief Constructs OpenVINO RawPerfMetrics instance by default.
 * @ingroup ov_genai_raw_perf_metrics_c_api
 * @param generation_config A pointer to the newly created ov_genai_raw_perf_metrics_t.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_raw_perf_metrics_create(
	ov_genai_raw_perf_metrics_t** raw_perf_metrics);

/**
 * @brief Releases an OpenVINO RawPerfMetrics instance.
 * @ingroup ov_genai_raw_perf_metrics_c_api
 * @param raw_perf_metrics A pointer to the ov_genai_raw_perf_metrics_t instance to be freed.
 */
OPENVINO_C_API(void)
ov_genai_raw_perf_metrics_free(
	ov_genai_raw_perf_metrics_t* raw_perf_metrics);

/**
 * @brief Retrieves the generate durations from the RawPerfMetrics instance.
 * @ingroup ov_genai_raw_perf_metrics_c_api
 * @param raw_perf_metrics A pointer to the ov_genai_raw_perf_metrics_t instance.
 * @param micro_seconds A pointer to a buffer that will hold the microsecond durations.
 * @param length A pointer to the length of the microsecond durations array.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_raw_perf_metrics_get_generate_durations(
	ov_genai_raw_perf_metrics_t* raw_perf_metrics,
	float** micro_seconds,
	size_t* length);

/**
 * @brief Sets the generate durations in the RawPerfMetrics instance.
 * @ingroup ov_genai_raw_perf_metrics_c_api
 * @param raw_perf_metrics A pointer to the ov_genai_raw_perf_metrics_t instance.
 * @param micro_seconds A pointer to the array of microsecond durations to set.
 * @param length The length of the microsecond durations array.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_raw_perf_metrics_set_generate_durations(
	ov_genai_raw_perf_metrics_t* raw_perf_metrics,
	float* micro_seconds,
	size_t length);

/**
 * @brief Retrieves the tokenization durations from the RawPerfMetrics instance.
 * @ingroup ov_genai_raw_perf_metrics_c_api
 * @param raw_perf_metrics A pointer to the ov_genai_raw_perf_metrics_t instance.
 * @param tokenization_durations A pointer to a buffer that will hold the tokenization durations.
 * @param length A pointer to the length of the tokenization durations array.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_raw_perf_metrics_get_tokenization_durations(
	ov_genai_raw_perf_metrics_t* raw_perf_metrics_t,
	float** tokenization_durations,
	size_t* length);

/**
 * @brief Sets the tokenization durations in the RawPerfMetrics instance.
 * @ingroup ov_genai_raw_perf_metrics_c_api
 * @param raw_perf_metrics A pointer to the ov_genai_raw_perf_metrics_t instance.
 * @param tokenization_durations A pointer to the array of tokenization durations to set.
 * @param length The length of the tokenization durations array.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_raw_perf_metrics_set_tokenization_durations(
	ov_genai_raw_perf_metrics_t* raw_perf_metrics_t,
	float* tokenization_durations,
	size_t length);

/**
 * @brief Retrieves the detokenization durations from the RawPerfMetrics instance.
 * @ingroup ov_genai_raw_perf_metrics_c_api
 * @param raw_perf_metrics A pointer to the ov_genai_raw_perf_metrics_t instance.
 * @param detokenization_durations A pointer to a buffer that will hold the detokenization durations.
 * @param length A pointer to the length of the detokenization durations array.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_raw_perf_metrics_get_detokenization_durations(
	ov_genai_raw_perf_metrics_t* raw_perf_metrics,
	float** detokenization_durations,
	size_t* length);

/**
 * @brief Sets the detokenization durations in the RawPerfMetrics instance.
 * @ingroup ov_genai_raw_perf_metrics_c_api
 * @param raw_perf_metrics A pointer to the ov_genai_raw_perf_metrics_t instance.
 * @param detokenization_durations A pointer to the array of detokenization durations to set.
 * @param length The length of the detokenization durations array.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_raw_perf_metrics_set_detokenization_durations(
	ov_genai_raw_perf_metrics_t* raw_perf_metrics,
	float* detokenization_durations,
	size_t length);

/**
 * @brief Retrieves the times to the first token from the RawPerfMetrics instance.
 * @ingroup ov_genai_raw_perf_metrics_c_api
 * @param raw_perf_metrics A pointer to the ov_genai_raw_perf_metrics_t instance.
 * @param m_times_to_first_token A pointer to a buffer that will hold the times to first token.
 * @param length A pointer to the length of the times to first token array.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_raw_perf_metrics_get_m_times_to_first_token(
	ov_genai_raw_perf_metrics_t* raw_perf_metrics,
	float** m_times_to_first_token,
	size_t* length);

/**
 * @brief Sets the times to the first token in the RawPerfMetrics instance.
 * @ingroup ov_genai_raw_perf_metrics_c_api
 * @param raw_perf_metrics A pointer to the ov_genai_raw_perf_metrics_t instance.
 * @param m_times_to_first_token A pointer to the array of times to first token to set.
 * @param length The length of the times to first token array.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_raw_perf_metrics_set_m_times_to_first_token(
	ov_genai_raw_perf_metrics_t* raw_perf_metrics,
	float* m_times_to_first_token,
	size_t length);

/**
 * @brief Retrieves the new token times from the RawPerfMetrics instance.
 * @ingroup ov_genai_raw_perf_metrics_c_api
 * @param raw_perf_metrics A pointer to the ov_genai_raw_perf_metrics_t instance.
 * @param m_new_token_times A pointer to a buffer that will hold the new token times.
 * @param length A pointer to the length of the new token times array.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_raw_perf_metrics_get_m_new_token_times(
	ov_genai_raw_perf_metrics_t* raw_perf_metrics,
	size_t** m_new_token_times,
	size_t* length);

/**
 * @brief Sets the new token times in the RawPerfMetrics instance.
 * @ingroup ov_genai_raw_perf_metrics_c_api
 * @param raw_perf_metrics A pointer to the ov_genai_raw_perf_metrics_t instance.
 * @param m_new_token_times A pointer to the array of new token times to set.
 * @param length The length of the new token times array.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_raw_perf_metrics_set_m_new_token_times(
	ov_genai_raw_perf_metrics_t* raw_perf_metrics,
	size_t* m_new_token_times,
	size_t length);

/**
 * @brief Retrieves the batch sizes from the RawPerfMetrics instance.
 * @ingroup ov_genai_raw_perf_metrics_c_api
 * @param raw_perf_metrics A pointer to the ov_genai_raw_perf_metrics_t instance.
 * @param m_batch_sizes A pointer to a buffer that will hold the batch sizes.
 * @param length A pointer to the length of the batch sizes array.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_raw_perf_metrics_get_m_batch_sizes(
	ov_genai_raw_perf_metrics_t* raw_perf_metrics,
	size_t** m_batch_sizes,
	size_t* length);

/**
 * @brief Sets the batch sizes in the RawPerfMetrics instance.
 * @ingroup ov_genai_raw_perf_metrics_c_api
 * @param raw_perf_metrics A pointer to the ov_genai_raw_perf_metrics_t instance.
 * @param m_batch_sizes A pointer to the array of batch sizes to set.
 * @param length The length of the batch sizes array.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_raw_perf_metrics_set_m_batch_sizes(
	ov_genai_raw_perf_metrics_t* raw_perf_metrics,
	size_t* m_batch_sizes,
	size_t length);

/**
 * @brief Retrieves the durations from the RawPerfMetrics instance.
 * @ingroup ov_genai_raw_perf_metrics_c_api
 * @param raw_perf_metrics A pointer to the ov_genai_raw_perf_metrics_t instance.
 * @param m_durations A pointer to a buffer that will hold the durations.
 * @param length A pointer to the length of the durations array.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_raw_perf_metrics_get_m_durations(
	ov_genai_raw_perf_metrics_t* raw_perf_metrics,
	float** m_durations,
	size_t* length);

/**
 * @brief Sets the durations in the RawPerfMetrics instance.
 * @ingroup ov_genai_raw_perf_metrics_c_api
 * @param raw_perf_metrics A pointer to the ov_genai_raw_perf_metrics_t instance.
 * @param m_durations A pointer to the array of durations to set.
 * @param length The length of the durations array.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_raw_perf_metrics_set_m_durations(
	ov_genai_raw_perf_metrics_t* raw_perf_metrics,
	float* m_durations,
	size_t length);