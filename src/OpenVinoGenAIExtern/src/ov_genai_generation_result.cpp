// Copyright (C) 2024 Yan Guojin
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_perf_metrics.h
* @brief This is a header file for the ov_genai_generation_result C API, which is a C wrapper for ov::genai::EncodedGenerationResult.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/9/17
*/

#include "ov_genai_generation_result.h"


#include "genai_common.h"


void
ov_genai_generation_result_free(
	ov_genai_generation_result_t* generation_result) {
	if (generation_result)
		delete generation_result;
}

ov_status_e
ov_genai_generation_result_get_request_id(
	ov_genai_generation_result_t* generation_result,
	uint64_t* request_id) {

	if (!generation_result || !request_id) {
		return ov_status_e::INVALID_C_PARAM;
	}
	try {
		*request_id = generation_result->object->m_request_id;
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

OPENVINO_C_API(ov_status_e)
ov_genai_generation_result_get_generation_ids(
	ov_genai_generation_result_t* generation_result,
	ov_genai_char_arrays_t* generation_ids) {

	if (!generation_result || !generation_ids) {
		return ov_status_e::INVALID_C_PARAM;
	}
	try {
		auto tmp = generation_result->object->m_generation_ids;
		generation_ids->size = tmp.size();
		std::unique_ptr<char* []> tmp_str(new char* [tmp.size()]);
		for (size_t i = 0; i < tmp.size(); i++) {
			tmp_str[i] = str_to_char_array(tmp[i]);
		}
		generation_ids->string_array = tmp_str.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e
ov_genai_generation_result_get_scores(
	ov_genai_generation_result_t* generation_result,
	float* request_id,
	size_t* scores) {

	if (!generation_result || !request_id || !scores) {
		return ov_status_e::INVALID_C_PARAM;
	}
	try {
		auto tmp = generation_result->object->m_scores;
		*scores = tmp.size();
		std::copy(tmp.begin(), tmp.end(), request_id);
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e
ov_genai_generation_result_get_status(
	ov_genai_generation_result_t* generation_result,
	int* status) {

	if (!generation_result || !status) {
		return ov_status_e::INVALID_C_PARAM;
	}
	try {
		auto tmp = generation_result->object->m_status;
		*status = static_cast<int>(tmp);
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}