// Copyright (C) 2024 Yan Guojin
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_generation_outputs.cpp
* @brief This is a header file for the ov_genai_generation_handle C API,
* which is a C wrapper for ov::genai::GenerationHandleImpl.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/9/17
*/



#include "ov_genai_generation_handle.h"


#include "genai_common.h"

void
ov_genai_generation_handle_free(
	ov_genai_generation_handle_t* generation_handle) {
	if (generation_handle)
		delete generation_handle;
}

ov_status_e
ov_genai_generation_handle_get_status(
	ov_genai_generation_handle_t* generation_handle,
	int* status) {

	if (!generation_handle || !status) {
		return ov_status_e::INVALID_C_PARAM;
	}
	try {
		auto tmp = generation_handle->object->get_status();
		*status = static_cast<int>(tmp);
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

ov_status_e
ov_genai_generation_handle_can_read(
	ov_genai_generation_handle_t* generation_handle,
	int* can_read) {

	if (!generation_handle || !can_read) {
		return ov_status_e::INVALID_C_PARAM;
	}
	try {
		auto tmp = generation_handle->object->can_read();
		*can_read = static_cast<int>(tmp);
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

OPENVINO_C_API(ov_status_e)
ov_genai_generation_handle_drop(
	ov_genai_generation_handle_t* generation_handle) {

	if (!generation_handle) {
		return ov_status_e::INVALID_C_PARAM;
	}
	try {
		generation_handle->object->drop();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

ov_status_e
ov_genai_generation_handle_back(
	ov_genai_generation_handle_t* generation_handle,
	ov_genai_generation_outputs_t** generation_outputs) {

	if (!generation_handle || !generation_outputs) {
		return ov_status_e::INVALID_C_PARAM;
	}
	try {
		auto tmp = generation_handle->object->back();
		
		std::unique_ptr<ov_genai_generation_outputs_t> _generation_outputs(new ov_genai_generation_outputs_t);
		_generation_outputs->object = std::make_shared<ov::genai::GenerationOutputs>(std::move(tmp));
		*generation_outputs = _generation_outputs.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

ov_status_e
ov_genai_generation_handle_read(
	ov_genai_generation_handle_t* generation_handle,
	ov_genai_generation_outputs_t** generation_outputs) {

	if (!generation_handle || !generation_outputs) {
		return ov_status_e::INVALID_C_PARAM;
	}
	try {
		auto tmp = generation_handle->object->read();

		std::unique_ptr<ov_genai_generation_outputs_t> _generation_outputs(new ov_genai_generation_outputs_t);
		_generation_outputs->object = std::make_shared<ov::genai::GenerationOutputs>(std::move(tmp));
		*generation_outputs = _generation_outputs.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

ov_status_e
ov_genai_generation_handle_read_all(
	ov_genai_generation_handle_t* generation_handle,
	ov_genai_generation_output_t** generation_output,
	size_t* size) {

	if (!generation_handle || !generation_output || !size) {
		return ov_status_e::INVALID_C_PARAM;
	}
	try {
		auto tmp = generation_handle->object->read_all();
		*size = tmp.size();
		generation_output =
			(ov_genai_generation_output_t**)malloc(tmp.size() * sizeof(ov_genai_generation_output_t*));
		for (int i = 0; i < tmp.size(); ++i) {
			std::unique_ptr<ov_genai_generation_output_t> _generation_output(new ov_genai_generation_output_t);
			_generation_output->object = std::make_shared<ov::genai::GenerationOutput>(std::move(tmp[i]));
			generation_output[i] = _generation_output.release();
		}

	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}