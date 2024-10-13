// Copyright (C) 2024 Yan Guojin. All rights reserved.
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_llm_pipeline.cpp
* @brief This is a header file for the ov_genai_llm_pipeline C API, which is a C wrapper for ov::genai::LLMPipeline.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/7/24
*/

#include "ov_genai_llm_pipeline.h"

#include <cstdarg>
#include <memory>

#include "genai_common.h"



int ov_genai_llm_sizeof()
{
	return sizeof(ov::genai::LLMPipeline);
}


ov_status_e ov_genai_llm_pipeline_create_with_model_path(
	const char* model_path,
	const char* device_name,
	ov_genai_llm_pipeline_t** llm_pipeline, ...){

	if (!model_path || !device_name || !llm_pipeline) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::AnyMap property = {};
		va_list args_ptr;
		va_start(args_ptr, device_name);
		GET_PROPERTY_FROM_ARGS_LIST;
		va_end(args_ptr);

		std::unique_ptr<ov_genai_llm_pipeline_t> _llm_pipeline(new ov_genai_llm_pipeline_t);
		_llm_pipeline->object = std::make_shared<ov::genai::LLMPipeline>(model_path, device_name, property);
		*llm_pipeline = _llm_pipeline.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e ov_genai_llm_pipeline_create_with_request(
	const ov_infer_request_t* request,
	const ov_genai_tokenizer_t* tokenizer,
	ov_genai_llm_pipeline_t** llm_pipeline) {

	if (!request || !tokenizer || !llm_pipeline) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		std::unique_ptr<ov_genai_llm_pipeline_t> _llm_pipeline(new ov_genai_llm_pipeline_t);
		_llm_pipeline->object = std::make_shared<ov::genai::LLMPipeline>(*request->object, *tokenizer->object, std::nullopt);
		*llm_pipeline = _llm_pipeline.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e ov_genai_llm_pipeline_create_with_request_config(
	const ov_infer_request_t* request,
	const ov_genai_tokenizer_t* tokenizer,
	const ov_genai_generation_config_t* generation_config,
	ov_genai_llm_pipeline_t** llm_pipeline){

	if (!request || !tokenizer || !generation_config || !llm_pipeline) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		std::unique_ptr<ov_genai_llm_pipeline_t> _llm_pipeline(new ov_genai_llm_pipeline_t);
		_llm_pipeline->object = std::make_shared<ov::genai::LLMPipeline>(*request->object, *tokenizer->object, *generation_config->object);
		*llm_pipeline = _llm_pipeline.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}



ov_status_e ov_genai_llm_pipeline_create_with_model_path_tokenizer(
	const char* model_path,
	const ov_genai_tokenizer_t* tokenizer,
	const char* device_name,
	ov_genai_llm_pipeline_t** llm_pipeline, ...){

	if (!model_path || !tokenizer || !device_name || !llm_pipeline) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::AnyMap property = {};
		va_list args_ptr;
		va_start(args_ptr, device_name);
		GET_PROPERTY_FROM_ARGS_LIST;
		va_end(args_ptr);

		std::unique_ptr<ov_genai_llm_pipeline_t> _llm_pipeline(new ov_genai_llm_pipeline_t);
		_llm_pipeline->object = std::make_shared<ov::genai::LLMPipeline>(model_path, *tokenizer->object, device_name, property);
		*llm_pipeline = _llm_pipeline.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}



void ov_genai_llm_pipeline_free(
	ov_genai_llm_pipeline_t* llm_pipeline) {
	if (llm_pipeline)
		delete llm_pipeline;
}




ov_status_e ov_genai_llm_pipeline_generate_string(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const char* inputs,
	ov_genai_decoded_results_t** decoded_results){


	if (!llm_pipeline || !inputs || !decoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::DecodedResults object;
		object = llm_pipeline->object->generate(inputs);
		std::unique_ptr<ov_genai_decoded_results_t> _decoded_results(new ov_genai_decoded_results_t);
		_decoded_results->object = std::make_shared<ov::genai::DecodedResults>(std::move(object));
		*decoded_results = _decoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}



ov_status_e ov_genai_llm_pipeline_generate_strings(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_char_arrays_t* inputs_array,
	ov_genai_decoded_results_t** decoded_results){

	if (!llm_pipeline || !decoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::DecodedResults object;
		object = llm_pipeline->object->generate(char_arrays_to_str_array(*inputs_array));
		std::unique_ptr<ov_genai_decoded_results_t> _decoded_results(new ov_genai_decoded_results_t);
		_decoded_results->object = std::make_shared<ov::genai::DecodedResults>(std::move(object));
		*decoded_results = _decoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}



ov_status_e ov_genai_llm_pipeline_generate_string_with_config(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const char* inputs,
	const ov_genai_generation_config_t* generation_config,
	ov_genai_decoded_results_t** decoded_results){

	if (!llm_pipeline || !generation_config || !decoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::DecodedResults object;
		object = llm_pipeline->object->generate(inputs, *generation_config->object);
		std::unique_ptr<ov_genai_decoded_results_t> _decoded_results(new ov_genai_decoded_results_t);
		_decoded_results->object = std::make_shared<ov::genai::DecodedResults>(std::move(object));
		*decoded_results = _decoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}



ov_status_e ov_genai_llm_pipeline_generate_strings_with_config(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_char_arrays_t* inputs_array,
	const ov_genai_generation_config_t* generation_config,
	ov_genai_decoded_results_t** decoded_results){

	if (!llm_pipeline || !generation_config || !decoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::DecodedResults object;
		object = llm_pipeline->object->generate(char_arrays_to_str_array(*inputs_array), *generation_config->object);
		std::unique_ptr<ov_genai_decoded_results_t> _decoded_results(new ov_genai_decoded_results_t);
		_decoded_results->object = std::make_shared<ov::genai::DecodedResults>(std::move(object));
		*decoded_results = _decoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}



ov_status_e ov_genai_llm_pipeline_generate_string_with_function(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const char* inputs,
	ov_genai_streamer_callback_t* callback,
	ov_genai_decoded_results_t** decoded_results){

	if (!llm_pipeline || !callback || !decoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::DecodedResults object;
		object = llm_pipeline->object->generate(inputs, std::nullopt,*callback);
		std::unique_ptr<ov_genai_decoded_results_t> _decoded_results(new ov_genai_decoded_results_t);
		_decoded_results->object = std::make_shared<ov::genai::DecodedResults>(std::move(object));
		*decoded_results = _decoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}



ov_status_e ov_genai_llm_pipeline_generate_strings_with_function(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_char_arrays_t* inputs_array,
	ov_genai_streamer_callback_t* callback,
	ov_genai_decoded_results_t** decoded_results){

	if (!llm_pipeline || !callback || !decoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::DecodedResults object;
		object = llm_pipeline->object->generate(char_arrays_to_str_array(*inputs_array), std::nullopt, *callback);
		std::unique_ptr<ov_genai_decoded_results_t> _decoded_results(new ov_genai_decoded_results_t);
		_decoded_results->object = std::make_shared<ov::genai::DecodedResults>(std::move(object));
		*decoded_results = _decoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}



ov_status_e ov_genai_llm_pipeline_generate_string_with_config_function(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const char* inputs,
	const ov_genai_generation_config_t* generation_config,
	ov_genai_streamer_callback_t* callback,
	ov_genai_decoded_results_t** decoded_results){

	if (!llm_pipeline || !generation_config || !callback || !decoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::DecodedResults object;
		object = llm_pipeline->object->generate(inputs, *generation_config->object, *callback);
		std::unique_ptr<ov_genai_decoded_results_t> _decoded_results(new ov_genai_decoded_results_t);
		_decoded_results->object = std::make_shared<ov::genai::DecodedResults>(std::move(object));
		*decoded_results = _decoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}



ov_status_e ov_genai_llm_pipeline_generate_strings_with_config_function(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_char_arrays_t* inputs_array,
	const ov_genai_generation_config_t* generation_config,
	ov_genai_streamer_callback_t* callback,
	ov_genai_decoded_results_t** decoded_results){

	if (!llm_pipeline || !generation_config || !callback || !decoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::DecodedResults object;
		object = llm_pipeline->object->generate(char_arrays_to_str_array(*inputs_array), *generation_config->object, *callback);
		std::unique_ptr<ov_genai_decoded_results_t> _decoded_results(new ov_genai_decoded_results_t);
		_decoded_results->object = std::make_shared<ov::genai::DecodedResults>(std::move(object));
		*decoded_results = _decoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}



ov_status_e ov_genai_llm_pipeline_generate_string_with_config_map(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const char* inputs,
	const generation_config_param_t config_param,
	ov_genai_decoded_results_t** decoded_results){

	if (!llm_pipeline || !decoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::DecodedResults object;
		object = llm_pipeline->object->generate(inputs, generation_config_param_to_anymap(config_param));
		std::unique_ptr<ov_genai_decoded_results_t> _decoded_results(new ov_genai_decoded_results_t);
		_decoded_results->object = std::make_shared<ov::genai::DecodedResults>(std::move(object));
		*decoded_results = _decoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}



ov_status_e ov_genai_llm_pipeline_generate_strings_with_config_map(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_char_arrays_t* inputs_array,
	const generation_config_param_t config_param,
	ov_genai_decoded_results_t** decoded_results){

	if (!llm_pipeline || !decoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::DecodedResults object;
		object = llm_pipeline->object->generate(char_arrays_to_str_array(*inputs_array), generation_config_param_to_anymap(config_param));
		std::unique_ptr<ov_genai_decoded_results_t> _decoded_results(new ov_genai_decoded_results_t);
		_decoded_results->object = std::make_shared<ov::genai::DecodedResults>(std::move(object));
		*decoded_results = _decoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}



ov_status_e ov_genai_llm_pipeline_generate_tensor(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_tensor_t* tensor,
	ov_genai_encoded_results_t** encoded_results){

	if (!llm_pipeline || !tensor || !encoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::EncodedResults object;
		object = llm_pipeline->object->generate(*tensor->object);
		std::unique_ptr<ov_genai_encoded_results_t> _encoded_results(new ov_genai_encoded_results_t);
		_encoded_results->object = std::make_shared<ov::genai::EncodedResults>(std::move(object));
		*encoded_results = _encoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e ov_genai_llm_pipeline_generate_tokenized_inputs(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_tokenized_inputs_t* tokenized_inputs,
	ov_genai_encoded_results_t** encoded_results){

	if (!llm_pipeline || !tokenized_inputs || !encoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::EncodedResults object;
		object = llm_pipeline->object->generate(*tokenized_inputs->object);
		std::unique_ptr<ov_genai_encoded_results_t> _encoded_results(new ov_genai_encoded_results_t);
		_encoded_results->object = std::make_shared<ov::genai::EncodedResults>(std::move(object));
		*encoded_results = _encoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}



ov_status_e ov_genai_llm_pipeline_generate_tensor_with_config(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_tensor_t* tensor,
	const ov_genai_generation_config_t* generation_config,
	ov_genai_encoded_results_t** encoded_results){

	if (!llm_pipeline || !tensor || !generation_config || !encoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::EncodedResults object;
		object = llm_pipeline->object->generate(*tensor->object, *generation_config->object);
		std::unique_ptr<ov_genai_encoded_results_t> _encoded_results(new ov_genai_encoded_results_t);
		_encoded_results->object = std::make_shared<ov::genai::EncodedResults>(std::move(object));
		*encoded_results = _encoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e ov_genai_llm_pipeline_generate_tokenized_inputs_with_config(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_tokenized_inputs_t* tokenized_inputs,
	const ov_genai_generation_config_t* generation_config,
	ov_genai_encoded_results_t** encoded_results){

	if (!llm_pipeline || !tokenized_inputs || !generation_config || !encoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::EncodedResults object;
		object = llm_pipeline->object->generate(*tokenized_inputs->object, *generation_config->object);
		std::unique_ptr<ov_genai_encoded_results_t> _encoded_results(new ov_genai_encoded_results_t);
		_encoded_results->object = std::make_shared<ov::genai::EncodedResults>(std::move(object));
		*encoded_results = _encoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e ov_genai_llm_pipeline_generate_tensor_with_function(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_tensor_t* tensor,
	ov_genai_streamer_callback_t* callback,
	ov_genai_encoded_results_t** encoded_results) {

	if (!llm_pipeline || !tensor || !callback || !encoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::EncodedResults object;
		object = llm_pipeline->object->generate(*tensor->object, std::nullopt, *callback);
		std::unique_ptr<ov_genai_encoded_results_t> _encoded_results(new ov_genai_encoded_results_t);
		_encoded_results->object = std::make_shared<ov::genai::EncodedResults>(std::move(object));
		*encoded_results = _encoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e ov_genai_llm_pipeline_generate_tokenized_inputs_with_function(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_tokenized_inputs_t* tokenized_inputs,
	ov_genai_streamer_callback_t* callback,
	ov_genai_encoded_results_t** encoded_results){

	if (!llm_pipeline || !tokenized_inputs || !callback || !encoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::EncodedResults object;
		object = llm_pipeline->object->generate(*tokenized_inputs->object, std::nullopt, *callback);
		std::unique_ptr<ov_genai_encoded_results_t> _encoded_results(new ov_genai_encoded_results_t);
		_encoded_results->object = std::make_shared<ov::genai::EncodedResults>(std::move(object));
		*encoded_results = _encoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}



ov_status_e ov_genai_llm_pipeline_generate_tensor_with_config_function(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_tensor_t* tensor,
	const ov_genai_generation_config_t* generation_config,
	ov_genai_streamer_callback_t* callback,
	ov_genai_encoded_results_t** encoded_results){

	if (!llm_pipeline || !tensor || !generation_config || !callback || !encoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::EncodedResults object;
		object = llm_pipeline->object->generate(*tensor->object, *generation_config->object, *callback);
		std::unique_ptr<ov_genai_encoded_results_t> _encoded_results(new ov_genai_encoded_results_t);
		_encoded_results->object = std::make_shared<ov::genai::EncodedResults>(std::move(object));
		*encoded_results = _encoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e ov_genai_llm_pipeline_generate_tokenized_inputs_with_config_function(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_tokenized_inputs_t* tokenized_inputs,
	const ov_genai_generation_config_t* generation_config,
	ov_genai_streamer_callback_t* callback,
	ov_genai_encoded_results_t** encoded_results){

	if (!llm_pipeline || !tokenized_inputs || !generation_config || !callback || !encoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::EncodedResults object;
		object = llm_pipeline->object->generate(*tokenized_inputs->object, *generation_config->object, *callback);
		std::unique_ptr<ov_genai_encoded_results_t> _encoded_results(new ov_genai_encoded_results_t);
		_encoded_results->object = std::make_shared<ov::genai::EncodedResults>(std::move(object));
		*encoded_results = _encoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}



ov_status_e ov_genai_llm_pipeline_generate_tensor_with_config_map(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_tensor_t* tensor,
	const generation_config_param_t config_param,
	ov_genai_encoded_results_t** encoded_results){

	if (!llm_pipeline || !tensor || !encoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::EncodedResults object;
		object = llm_pipeline->object->generate(*tensor->object, generation_config_param_to_anymap(config_param));
		std::unique_ptr<ov_genai_encoded_results_t> _encoded_results(new ov_genai_encoded_results_t);
		_encoded_results->object = std::make_shared<ov::genai::EncodedResults>(std::move(object));
		*encoded_results = _encoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e ov_genai_llm_pipeline_generate_tokenized_inputs_with_config_map(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_tokenized_inputs_t* tokenized_inputs,
	const generation_config_param_t config_param,
	ov_genai_encoded_results_t** encoded_results){

	if (!llm_pipeline || !tokenized_inputs || !encoded_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::EncodedResults object;
		object = llm_pipeline->object->generate(*tokenized_inputs->object, generation_config_param_to_anymap(config_param));
		std::unique_ptr<ov_genai_encoded_results_t> _encoded_results(new ov_genai_encoded_results_t);
		_encoded_results->object = std::make_shared<ov::genai::EncodedResults>(std::move(object));
		*encoded_results = _encoded_results.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}



ov_status_e ov_genai_llm_pipeline_generate_get_tokenizer(
	ov_genai_llm_pipeline_t* llm_pipeline,
	ov_genai_tokenizer_t** tokenizer){

	if (!llm_pipeline || !tokenizer) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::Tokenizer object;
		object = llm_pipeline->object->get_tokenizer();
		std::unique_ptr<ov_genai_tokenizer_t> _tokenizer(new ov_genai_tokenizer_t);
		_tokenizer->object = std::make_shared<ov::genai::Tokenizer>(std::move(object));
		*tokenizer = _tokenizer.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

ov_status_e ov_genai_llm_pipeline_generate_get_generation_config(
	ov_genai_llm_pipeline_t* llm_pipeline,
	ov_genai_generation_config_t** generation_config){

	if (!llm_pipeline || !generation_config) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::GenerationConfig object;
		object = llm_pipeline->object->get_generation_config();
		std::unique_ptr<ov_genai_generation_config_t> _generation_config(new ov_genai_generation_config_t);
		_generation_config->object = std::make_shared<ov::genai::GenerationConfig>(std::move(object));
		*generation_config = _generation_config.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

ov_status_e ov_genai_llm_pipeline_generate_set_generation_config(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_generation_config_t* generation_config){

	if (!llm_pipeline || !generation_config) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		llm_pipeline->object->set_generation_config(*generation_config->object);
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

ov_status_e ov_genai_llm_pipeline_generate_start_chat(
	ov_genai_llm_pipeline_t* llm_pipeline){

	if (!llm_pipeline) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		llm_pipeline->object->start_chat();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

ov_status_e ov_genai_llm_pipeline_generate_finish_chat(
	ov_genai_llm_pipeline_t* llm_pipeline){


	if (!llm_pipeline) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		llm_pipeline->object->finish_chat();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}