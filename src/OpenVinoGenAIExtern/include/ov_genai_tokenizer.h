// Copyright (C) 2024 Yan Guojin. All rights reserved.
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_tokenizer.h
* @brief This is a header file for the ov_genai_tokenizer C API, which is a C wrapper for ov::genai::Tokenizer.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/7/24
*/

#pragma once
#include "genai_common.h"
#include "ov_genai_common.h"
#include "ov_genai_tokenized_inputs.h"
#include "ov_tensor.h"

typedef struct ov_genai_tokenizer ov_genai_tokenizer_t;



/**
 * @brief Constructs an Tokenizer.
 * @ingroup ov_genai_tokenizer_c_api
 * @param tokenizer A point to ov_genai_tokenized_inputs_t.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_tokenizer_create(ov_genai_tokenizer_t** tokenizer);


/**
 * @brief Constructs an Tokenizer from xml/bin files.
 * @ingroup ov_genai_tokenizer_c_api
 * @param tokenizer_path openvino_tokenizer.xml and openvino_detokenizer.xml should be located in the tokenizer_path
 * @param tokenizer A point to ov_genai_tokenized_inputs_t.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_tokenizer_create_with_path(const char* tokenizer_path, 
	ov_genai_tokenizer_t** tokenizer);

/**
 * @brief Delete an Tokenizer.
 * @ingroup ov_genai_tokenizer_c_api
 * @param tokenizer A point to ov_genai_tokenized_inputs_t.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(void)
ov_genai_tokenizer_free(ov_genai_tokenizer_t* tokenizer);




/**
 * @brief Encode a single prompt.
 * @ingroup ov_genai_tokenizer_c_api
 * @param tokenizer A point to ov_genai_tokenized_inputs_t.
 * @param prompt A single prompt.
 * @param tokenized_inputs The pair of [input_ids, attention_mask].
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_tokenizer_encode_string(ov_genai_tokenizer_t* tokenizer,
	const char* prompt, 
	ov_genai_tokenized_inputs_t** tokenized_inputs);



/**
 * @brief Encode batch of prompts. Left padding will be applied by default.
 * @ingroup ov_genai_tokenizer_c_api
 * @param tokenizer A point to ov_genai_tokenized_inputs_t.
 * @param prompt A batch of prompts.
 * @param tokenized_inputs The pair of [input_ids, attention_mask].
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_tokenizer_encode_strings(ov_genai_tokenizer_t* tokenizer,
	const ov_genai_char_arrays_t prompt, 
	ov_genai_tokenized_inputs_t** tokenized_inputs);

/**
 * @brief Decode sequence of tokens.
 * @ingroup ov_genai_tokenizer_c_api
 * @param tokenizer A point to ov_genai_tokenized_inputs_t.
 * @param tokens The array of storing tokens.
 * @param tokens_len The array length.
 * @param decode_result The sequence string.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_tokenizer_decode_string_tokens(ov_genai_tokenizer_t* tokenizer,
	int64_t* tokens, 
	int64_t tokens_len, 
	char** decode_result);


/**
 * @brief Decode sequence of tokens.
 * @ingroup ov_genai_tokenizer_c_api
 * @param tokenizer A point to ov_genai_tokenized_inputs_t.
 * @param tokens ov::Tensor with tokens with shape [batch_size, seq_len].
 * @param decode_result The vector of std::string, with size = batch_size.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_tokenizer_decode_tensor(ov_genai_tokenizer_t* tokenizer,
	ov_tensor_t* tokens, 
	ov_genai_char_arrays_t* decode_results);


/**
 * @brief Decode batched decoding of tokens.
 * @ingroup ov_genai_tokenizer_c_api
 * @param tokenizer A point to ov_genai_tokenized_inputs_t.
 * @param tokens The vector of vectors with tokens, tokens.size() is equal to batch_size.
 * @param rows The vector of rows array.
 * @param col The vector of col.
 * @param decode_result The vector of std::string, with size equal to batch_size.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_tokenizer_decode_tokens_array(ov_genai_tokenizer_t* tokenizer,
	int64_t* tokens, 
	int64_t* rows, 
	int64_t col, 
	ov_genai_char_arrays_t* decode_results);



OPENVINO_C_API(ov_status_e)
ov_genai_tokenizer_get_bos_token_id(ov_genai_tokenizer_t* tokenizer,
	int64_t* bos_token_id);

OPENVINO_C_API(ov_status_e)
ov_genai_tokenizer_get_eos_token_id(ov_genai_tokenizer_t* tokenizer,
	int64_t* eos_token_id);

OPENVINO_C_API(ov_status_e)
ov_genai_tokenizer_get_pad_token_id(ov_genai_tokenizer_t* tokenizer,
	int64_t* pad_token_id);

OPENVINO_C_API(ov_status_e)
ov_genai_tokenizer_get_bos_token(ov_genai_tokenizer_t* tokenizer, 
	char** bos_token);

OPENVINO_C_API(ov_status_e)
ov_genai_tokenizer_get_eos_token(ov_genai_tokenizer_t* tokenizer, 
	char** eos_token);

OPENVINO_C_API(ov_status_e)
ov_genai_tokenizer_get_pad_token(ov_genai_tokenizer_t* tokenizer, 
	char** pad_token);