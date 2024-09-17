// Copyright (C) 2024 Yan Guojin
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_perf_metrics.h
* @brief This is a header file for the ov_genai_encoded_generation_result C API, which is a C wrapper for ov::genai::EncodedGenerationResult.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/9/17
*/

#include "ov_genai_encoded_generation_result.h"


#include "genai_common.h"


void
ov_genai_encoded_generation_result_free(
	ov_genai_encoded_generation_result_t* encoded_generation_result) {
	if (encoded_generation_result)
		delete encoded_generation_result;
}

ov_status_e
ov_genai_encoded_generation_result_get_request_id(
	ov_genai_encoded_generation_result_t* encoded_generation_result,
	uint64_t* request_id) {

	if (!encoded_generation_result || !request_id) {
		return ov_status_e::INVALID_C_PARAM;
	}
	try {
		*request_id = encoded_generation_result->object->m_request_id;
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

OPENVINO_C_API(ov_status_e)
ov_genai_encoded_generation_result_get_generation_ids(
	ov_genai_encoded_generation_result_t* encoded_generation_result,
	ov_genai_double_int_arrays_t* generation_ids) {

	if (!encoded_generation_result || !generation_ids) {
		return ov_status_e::INVALID_C_PARAM;
	}
	try {
		auto tmp = encoded_generation_result->object->m_generation_ids;
		*generation_ids = int_vectors_to__double_int_arrays(tmp);
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e
ov_genai_encoded_generation_result_get_scores(
	ov_genai_encoded_generation_result_t* encoded_generation_result,
	float* scores,
	size_t* size) {

	if (!encoded_generation_result || !scores || !size) {
		return ov_status_e::INVALID_C_PARAM;
	}
	try {
		auto tmp = encoded_generation_result->object->m_scores;
		*size = tmp.size();
		std::copy(tmp.begin(), tmp.end(), scores);
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e
ov_genai_encoded_generation_result_get_status(
	ov_genai_encoded_generation_result_t* encoded_generation_result,
	int* status) {

	if (!encoded_generation_result || !status) {
		return ov_status_e::INVALID_C_PARAM;
	}
	try {
		auto tmp = encoded_generation_result->object->m_status;
		*status = static_cast<int>(tmp);
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}