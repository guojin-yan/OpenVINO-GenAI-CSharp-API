// Copyright (C) 2024 Yan Guojin
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_generation_outputs.cpp
* @brief This is a header file for the ov_genai_generation_output and ov_genai_generation_outputs C API,
* which is a C wrapper for ov::genai::GenerationOutput and ov::genai::GenerationOutputs.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/9/17
*/


#include "ov_genai_generation_outputs.h"


#include "genai_common.h"


void
ov_genai_generation_output_free(
	ov_genai_generation_output_t* generation_output) {
	if (generation_output)
		delete generation_output;
}

OPENVINO_C_API(ov_status_e)
ov_genai_generation_output_get_generated_token_ids(
	ov_genai_generation_output_t* generation_output,
	int64_t* generated_token_ids,
	size_t* size) {

	if (!generation_output || !generated_token_ids || !size) {
		return ov_status_e::INVALID_C_PARAM;
	}
	try {
		auto tmp = generation_output->object->generated_token_ids;
		*size = tmp.size();
		std::copy(tmp.begin(), tmp.end(), generated_token_ids);
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

OPENVINO_C_API(ov_status_e)
ov_genai_generation_output_get_score(
	ov_genai_generation_output_t* generation_output,
	float* score) {

	if (!generation_output || !score) {
		return ov_status_e::INVALID_C_PARAM;
	}
	try {
		*score = generation_output->object->score;
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

OPENVINO_C_API(void)
ov_genai_generation_outputs_free(
	ov_genai_generation_outputs_t* generation_outputs) {
	if (generation_outputs)
		delete generation_outputs;
}

OPENVINO_C_API(ov_status_e)
ov_genai_generation_outputs_at(
	ov_genai_generation_outputs_t* generation_outputs,
	uint64_t key,
	ov_genai_generation_output_t** generation_output) {
	if (!generation_outputs || !generation_output) {
		return ov_status_e::INVALID_C_PARAM;
	}
	try {
		auto tmp = generation_outputs->object->at(key);
		std::unique_ptr<ov_genai_generation_output_t> _generation_output(new ov_genai_generation_output_t);
		_generation_output->object = std::make_shared<ov::genai::GenerationOutput>(std::move(tmp));
		*generation_output = _generation_output.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}