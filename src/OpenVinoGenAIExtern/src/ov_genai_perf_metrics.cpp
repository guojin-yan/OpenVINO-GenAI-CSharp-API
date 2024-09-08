// Copyright (C) 2024 Yan Guojin
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_raw_perf_metrics.cpp
* @brief This is a header file for the ov_genai_perf_metrics C API, which is a C wrapper for ov::genai::PerfMetrics.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/9/8
*/

#include "ov_genai_perf_metrics.h"

#include "genai_common.h"
#include <cstdarg>

ov_status_e ov_genai_perf_metrics_create(
    ov_genai_perf_metrics_t** perf_metrics) {
    if (!perf_metrics) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        std::unique_ptr<ov_genai_perf_metrics_t> _perf_metrics(new ov_genai_perf_metrics_t);
        _perf_metrics->object = std::make_shared<ov::genai::PerfMetrics>();
        *perf_metrics = _perf_metrics.release();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

void ov_genai_perf_metrics_free(
    ov_genai_perf_metrics_t* perf_metrics) {
    if (perf_metrics)
        delete perf_metrics;
}

ov_status_e
ov_genai_get_load_time(
	ov_genai_perf_metrics_t* perf_metrics,
	float* load_time) {

	if (!perf_metrics || !load_time) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		auto tmp = perf_metrics->object->get_load_time();
		*load_time = tmp;
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e
ov_genai_get_num_generated_tokens(
	ov_genai_perf_metrics_t* perf_metrics,
	size_t* num_generated_tokens) {

	if (!perf_metrics || !num_generated_tokens) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		auto tmp = perf_metrics->object->get_num_generated_tokens();
		*num_generated_tokens = tmp;
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e
ov_genai_get_num_input_tokens(
	ov_genai_perf_metrics_t* perf_metrics,
	size_t* num_input_tokens) {

	if (!perf_metrics || !num_input_tokens) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		auto tmp = perf_metrics->object->get_num_input_tokens();
		*num_input_tokens = tmp;
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}



ov_status_e
ov_genai_get_ttft(
	ov_genai_perf_metrics_t* perf_metrics,
	ov_genai_mean_std_pair_t* ttft) {

	if (!perf_metrics || !ttft) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		std::unique_ptr<ov_genai_mean_std_pair_t> mean_std_pair(new ov_genai_mean_std_pair_t);
		auto tmp = perf_metrics->object->get_ttft();
		mean_std_pair->mean = tmp.mean;
		mean_std_pair->std = tmp.std;
		ttft = mean_std_pair.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e
ov_genai_get_tpot(
	ov_genai_perf_metrics_t* perf_metrics,
	ov_genai_mean_std_pair_t* tpot) {

	if (!perf_metrics || !tpot) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		std::unique_ptr<ov_genai_mean_std_pair_t> mean_std_pair(new ov_genai_mean_std_pair_t);
		auto tmp = perf_metrics->object->get_tpot();
		mean_std_pair->mean = tmp.mean;
		mean_std_pair->std = tmp.std;
		tpot = mean_std_pair.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

ov_status_e
ov_genai_get_throughput(
	ov_genai_perf_metrics_t* perf_metrics,
	ov_genai_mean_std_pair_t* throughput) {

	if (!perf_metrics || !throughput) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		std::unique_ptr<ov_genai_mean_std_pair_t> mean_std_pair(new ov_genai_mean_std_pair_t);
		auto tmp = perf_metrics->object->get_throughput();
		mean_std_pair->mean = tmp.mean;
		mean_std_pair->std = tmp.std;
		throughput = mean_std_pair.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e
ov_genai_get_generate_duration(
	ov_genai_perf_metrics_t* perf_metrics,
	ov_genai_mean_std_pair_t* generate_duration) {

	if (!perf_metrics || !generate_duration) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		std::unique_ptr<ov_genai_mean_std_pair_t> mean_std_pair(new ov_genai_mean_std_pair_t);
		auto tmp = perf_metrics->object->get_generate_duration();
		mean_std_pair->mean = tmp.mean;
		mean_std_pair->std = tmp.std;
		generate_duration = mean_std_pair.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

ov_status_e
ov_genai_get_tokenization_duration(
	ov_genai_perf_metrics_t* perf_metrics,
	ov_genai_mean_std_pair_t* tokenization_duration) {

	if (!perf_metrics || !tokenization_duration) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		std::unique_ptr<ov_genai_mean_std_pair_t> mean_std_pair(new ov_genai_mean_std_pair_t);
		auto tmp = perf_metrics->object->get_tokenization_duration();
		mean_std_pair->mean = tmp.mean;
		mean_std_pair->std = tmp.std;
		tokenization_duration = mean_std_pair.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

ov_status_e
ov_genai_get_detokenization_duration(
	ov_genai_perf_metrics_t* perf_metrics,
	ov_genai_mean_std_pair_t* detokenization_duration) {

	if (!perf_metrics || !detokenization_duration) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		std::unique_ptr<ov_genai_mean_std_pair_t> mean_std_pair(new ov_genai_mean_std_pair_t);
		auto tmp = perf_metrics->object->get_detokenization_duration();
		mean_std_pair->mean = tmp.mean;
		mean_std_pair->std = tmp.std;
		detokenization_duration = mean_std_pair.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e
ov_genai_get_evaluated_flag(
	ov_genai_perf_metrics_t* perf_metrics,
	int* evaluated_flag) {

	if (!perf_metrics || !evaluated_flag) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		auto tmp = perf_metrics->object->m_evaluated;
		*evaluated_flag = tmp;
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e
ov_genai_set_evaluated_flag(
	ov_genai_perf_metrics_t* perf_metrics,
	int evaluated_flag) {

	if (!perf_metrics || !evaluated_flag) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		perf_metrics->object->m_evaluated = evaluated_flag;
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

ov_status_e
ov_genai_evaluate_statistics(
	ov_genai_perf_metrics_t* perf_metrics) {

	if (!perf_metrics) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		perf_metrics->object->evaluate_statistics();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}




ov_status_e
ov_genai_operator_add(
	ov_genai_perf_metrics_t* perf_metrics,
	ov_genai_perf_metrics_t* other_perf_metrics,
	ov_genai_perf_metrics_t** new_perf_metrics) {

	if (!perf_metrics || !other_perf_metrics || !new_perf_metrics) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		std::unique_ptr<ov_genai_perf_metrics_t> perf_metrics(new ov_genai_perf_metrics_t);

		*perf_metrics->object = *perf_metrics->object + *other_perf_metrics->object;
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}