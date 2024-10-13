// Copyright (C) 2024 Yan Guojin. All rights reserved.
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_tokenizer.cpp
* @brief This is a header file for the ov_genai_tokenizer C API, which is a C wrapper for ov::genai::Tokenizer.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/8/1
*/

#include "ov_genai_tokenizer.h"



ov_status_e ov_genai_tokenizer_create(ov_genai_tokenizer_t** tokenizer){
	if (!tokenizer) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		std::unique_ptr<ov_genai_tokenizer_t> _tokenizer(new ov_genai_tokenizer_t);
		_tokenizer ->object = std::make_shared<ov::genai::Tokenizer>();
		*tokenizer = _tokenizer.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e ov_genai_tokenizer_create_with_path(const char* tokenizer_path,
	ov_genai_tokenizer_t** tokenizer){

	if (!tokenizer_path || !tokenizer) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		std::unique_ptr<ov_genai_tokenizer_t> _tokenizer(new ov_genai_tokenizer_t);
		_tokenizer->object = std::make_shared<ov::genai::Tokenizer>(tokenizer_path);
		*tokenizer = _tokenizer.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

void ov_genai_tokenizer_free(ov_genai_tokenizer_t* tokenizer){
	if (tokenizer)
		delete tokenizer;
}


ov_status_e ov_genai_tokenizer_encode_string(ov_genai_tokenizer_t* tokenizer,
	const char* prompt,
	ov_genai_tokenized_inputs_t** tokenized_inputs){

	if (!tokenizer || !prompt || !tokenized_inputs) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::TokenizedInputs object;
		object = tokenizer->object->encode(prompt);
		std::unique_ptr<ov_genai_tokenized_inputs_t> _tokenized_inputs(new ov_genai_tokenized_inputs_t);
		_tokenized_inputs->object = std::make_shared<ov::genai::TokenizedInputs>(std::move(object));
		*tokenized_inputs = _tokenized_inputs.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e ov_genai_tokenizer_encode_strings(ov_genai_tokenizer_t* tokenizer,
	const ov_genai_char_arrays_t* prompt,
	ov_genai_tokenized_inputs_t** tokenized_inputs){
	if (!tokenizer || !tokenized_inputs) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		ov::genai::TokenizedInputs object;
		object = tokenizer->object->encode(char_arrays_to_str_array(*prompt));
		std::unique_ptr<ov_genai_tokenized_inputs_t> _tokenized_inputs(new ov_genai_tokenized_inputs_t);
		_tokenized_inputs->object = std::make_shared<ov::genai::TokenizedInputs>(std::move(object));
		*tokenized_inputs = _tokenized_inputs.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e ov_genai_tokenizer_decode_string_tokens(ov_genai_tokenizer_t* tokenizer,
	int64_t* tokens,
	int64_t tokens_len,
	char** decode_result){

	if (!tokenizer || !tokens || !decode_result) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		std::string object;
		object = tokenizer->object->decode(std::vector<int64_t>(tokens, tokens + tokens_len));
		*decode_result = str_to_char_array(object);
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}


ov_status_e ov_genai_tokenizer_decode_tensor(ov_genai_tokenizer_t* tokenizer,
	ov_tensor_t* tokens,
	ov_genai_char_arrays_t* decode_results){

	if (!tokenizer || !decode_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		std::vector<std::string> object;
		object = tokenizer->object->decode(*tokens->object);
		decode_results->size = object.size();
		std::unique_ptr<char* []> tmp_devices(new char* [object.size()]);
		for (size_t i = 0; i < object.size(); i++) {
			tmp_devices[i] = str_to_char_array(object[i]);
		}
		decode_results->string_array = tmp_devices.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}



ov_status_e ov_genai_tokenizer_decode_tokens_array(ov_genai_tokenizer_t* tokenizer,
	int64_t* tokens,
	int64_t* rows,
	int64_t col,
	ov_genai_char_arrays_t* decode_results){

	if (!tokenizer || !tokens || !rows || !decode_results) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		std::vector<std::vector<int64_t>> tmp_tokens;
		int64_t sum = 0;
		for (int i = 0; i < col; ++i) {
			std::vector<int64_t> tmp(tokens + sum, tokens + sum + rows[i]);
			tmp_tokens.push_back(tmp);
			sum += rows[i];
		}
		std::vector<std::string> object;
		object = tokenizer->object->decode(tmp_tokens);
		decode_results->size = object.size();
		std::unique_ptr<char* []> tmp_devices(new char* [object.size()]);
		for (size_t i = 0; i < object.size(); i++) {
			tmp_devices[i] = str_to_char_array(object[i]);
		}
		decode_results->string_array = tmp_devices.release();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;

}


ov_status_e ov_genai_tokenizer_get_bos_token_id(ov_genai_tokenizer_t* tokenizer,
	int64_t* bos_token_id){
	if (!tokenizer || !bos_token_id) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		*bos_token_id = tokenizer->object->get_bos_token_id();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

ov_status_e ov_genai_tokenizer_get_eos_token_id(ov_genai_tokenizer_t* tokenizer,
	int64_t* eos_token_id){

	if (!tokenizer || !eos_token_id) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		*eos_token_id = tokenizer->object->get_bos_token_id();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

ov_status_e ov_genai_tokenizer_get_pad_token_id(ov_genai_tokenizer_t* tokenizer,
	int64_t* pad_token_id){

	if (!tokenizer || !pad_token_id) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		*pad_token_id = tokenizer->object->get_bos_token_id();
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

ov_status_e ov_genai_tokenizer_get_bos_token(ov_genai_tokenizer_t* tokenizer,
	char** bos_token){

	if (!tokenizer || !bos_token) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		std::string tmp = tokenizer->object->get_bos_token();
		*bos_token = str_to_char_array(tmp);
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

ov_status_e ov_genai_tokenizer_get_eos_token(ov_genai_tokenizer_t* tokenizer,
	char** eos_token){
	if (!tokenizer || !eos_token) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		std::string tmp = tokenizer->object->get_bos_token();
		*eos_token = str_to_char_array(tmp);
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}

ov_status_e ov_genai_tokenizer_get_pad_token(ov_genai_tokenizer_t* tokenizer,
	char** pad_token){
	if (!tokenizer || !pad_token) {
		return ov_status_e::INVALID_C_PARAM;
	}

	try {
		std::string tmp = tokenizer->object->get_bos_token();
		*pad_token = str_to_char_array(tmp);
	}
	CATCH_OV_GENAI_EXCEPTIONS
		return ov_status_e::OK;
}