// Copyright (C) 2024 Yan Guojin. All rights reserved.
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_llm_pipeline.h
* @brief This is a header file for the ov_genai_llm_pipeline C API, which is a C wrapper for ov::genai::LLMPipeline.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/7/24
*/

#pragma once
#include "openvino/genai/generation_config.hpp"
#include "openvino/genai/llm_pipeline.hpp"
#include "openvino/genai/streamer_base.hpp"
#include "openvino/genai/tokenizer.hpp"
#include "openvino/genai/visibility.hpp"

#include "ov_genai_common.h"
#include "ov_infer_request.h"
#include "ov_tensor.h"
#include "ov_genai_decoded_results.h"
#include "ov_genai_generation_config.h"
#include "ov_genai_tokenizer.h"


/**
 * @struct ov_genai_llm_pipeline_t
 * @ingroup ov_genai_llm_pipeline_c_api
 * @brief type define ov_genai_llm_pipeline_t from ov_genai_llm_pipeline
 */
typedef struct ov_genai_llm_pipeline ov_genai_llm_pipeline_t;

/**
 * @struct ov_string_array
 * @ingroup ov_genai_llm_pipeline_c_api
 * @brief String array structure.
 */
typedef struct ov_genai_char_arrays ov_genai_char_arrays_t;

typedef bool(__stdcall* ov_genai_streamer_callback_t)(std::string str);



/**
 * @brief Constructs an LLMPipeline from xml/bin files, tokenizers and configuration in the same dir.
 * @ingroup ov_genai_llm_pipeline_c_api
 * @param model_path Path to the dir model xml/bin files, tokenizers and generation_configs.json
 * @param device_name optional device
 * @param plugin_config optional plugin_config
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_create_with_model_path(
	const char* model_path, 
	const char* device_name, 
	ov_genai_llm_pipeline_t** llm_pipeline, ...);


/**
 * @brief Constructs an LLMPipeline from already existing infer InferRequest and Tokenizer.
 * @ingroup ov_genai_llm_pipeline_c_api
 * @param request infer request of the model
 * @param tokenizer initialized Tokenizer 
 * @param generation_config optional generation_config, be default will be initialized for greedy decoding
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_create_with_request(
	const ov_infer_request_t* request,
	const ov_genai_tokenizer_t* tokenizer,
	const ov_genai_generation_config_t* generation_config,
	ov_genai_llm_pipeline_t** llm_pipeline);


/**
 * @brief Constructs a LLMPipeline when ov::Tokenizer is initialized manually using file from the different dirs.
 * @ingroup ov_genai_llm_pipeline_c_api
 * @param model_path Path to the dir with model, tokenizer .xml/.bin files, and generation_configs.json
 * @param tokenizer manually initialized ov::Tokenizer 
 * @param device_name optional device
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_create_with_model_path_tokenizer(
	const char* model_path,
	const ov_genai_tokenizer_t* tokenizer,
	const char* device_name, 
	ov_genai_llm_pipeline_t** llm_pipeline, ...);


/**
 * @brief Release the memory allocated by ov_genai_llm_pipeline_t.
 * @ingroup ov_genai_llm_pipeline_c_api
 * @param llm_pipeline A pointer to the ov_genai_llm_pipeline_t to free memory.
 */
OPENVINO_C_API(void)
ov_genai_llm_pipeline_free(
	ov_genai_llm_pipeline_t* llm_pipeline);



/**
 * @brief High level generate that receives prompts as a string  and returns decoded output.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param inputs The input text.
 * @param decoded_results A point to decodedResults decoded resulting text.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_string(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const char* inputs,
	ov_genai_decoded_results_t** decoded_results
);


/**
 * @brief High level generate that receives prompts as a string array and returns decoded output.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param inputs_array The input text aray.
 * @param decoded_results A point to decodedResults decoded resulting text.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_strings(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_char_arrays_t* inputs_array,
	ov_genai_decoded_results_t** decoded_results
);


/**
 * @brief High level generate that receives prompts as a string and returns decoded output.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param inputs The input text.
 * @param generation_config Class to keep generation config parameters.
 * @param decoded_results A point to decodedResults decoded resulting text.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_string_with_config(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const char* inputs,
	const ov_genai_generation_config_t* generation_config,
	ov_genai_decoded_results_t** decoded_results
);


/**
 * @brief High level generate that receives prompts as a string array and returns decoded output.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param inputs_array The input text aray.
 * @param generation_config Class to keep generation config parameters.
 * @param decoded_results A point to decodedResults decoded resulting text.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_strings_with_config(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_char_arrays_t* inputs_array,
	const ov_genai_generation_config_t* generation_config,
	ov_genai_decoded_results_t** decoded_results
);


/**
 * @brief High level generate that receives prompts as a string and returns decoded output.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param inputs The input text.
 * @param callback Delegate function pointer.
 * @param decoded_results A point to decodedResults decoded resulting text.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_string_with_function(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const char* inputs,
	ov_genai_streamer_callback_t* callback,
	ov_genai_decoded_results_t** decoded_results
);


/**
 * @brief High level generate that receives prompts as a string array and returns decoded output.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param inputs_array The input text aray.
 * @param callback Delegate function pointer.
 * @param decoded_results A point to decodedResults decoded resulting text.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_strings_with_function(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_char_arrays_t* inputs_array,
	ov_genai_streamer_callback_t* callback,
	ov_genai_decoded_results_t** decoded_results
);


/**
 * @brief High level generate that receives prompts as a string and returns decoded output.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param inputs The input text.
 * @param generation_config Class to keep generation config parameters.
 * @param callback Delegate function pointer.
 * @param decoded_results A point to decodedResults decoded resulting text.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_string_with_config_function(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const char* inputs,
	const ov_genai_generation_config_t* generation_config,
	ov_genai_streamer_callback_t* callback,
	ov_genai_decoded_results_t** decoded_results
);


/**
 * @brief High level generate that receives prompts as a string array and returns decoded output.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param inputs_array The input text aray.
 * @param generation_config Class to keep generation config parameters.
 * @param callback Delegate function pointer.
 * @param decoded_results A point to decodedResults decoded resulting text.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_strings_with_config_function(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_char_arrays_t* inputs_array,
	const ov_genai_generation_config_t* generation_config,
	ov_genai_streamer_callback_t* callback,
	ov_genai_decoded_results_t** decoded_results
);


/**
 * @brief High level generate that receives prompts as a string and returns decoded output.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param inputs The input text.
 * @param config_param Structure to keep generation config parameters.
 * @param decoded_results A point to decodedResults decoded resulting text.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_string_with_config_map(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const char* inputs,
	const generation_config_param_t* config_param,
	ov_genai_decoded_results_t** decoded_results
);


/**
 * @brief High level generate that receives prompts as a string array and returns decoded output.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param inputs_array The input text aray.
 * @param config_param Structure to keep generation config parameters.
 * @param decoded_results A point to decodedResults decoded resulting text.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_strings_with_config_map(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_char_arrays_t* inputs_array,
	const generation_config_param_t* config_param,
	ov_genai_decoded_results_t** decoded_results
);


/**
 * @brief Low level generate to be called with already encoded input_ids tokens.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param tensor The input_ids encoded input prompt tokens.
 * @param decoded_results EncodedResults a structure with resulting tokens and scores
 * @return Status code of the operation: OK(0) for success.
*/
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_tensor(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_tensor_t* tensor,
	ov_genai_decoded_results_t** decoded_results
);

/**
 * @brief Low level generate to be called with already encoded input_ids tokens.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param tokenized_inputs The pair of (input_ids, attentino_mask) encoded input prompt tokens.
 * @param decoded_results EncodedResults a structure with resulting tokens and scores
 * @return Status code of the operation: OK(0) for success.
*/
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_tokenized_inputs(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_tokenized_inputs_t* tokenized_inputs,
	ov_genai_decoded_results_t** decoded_results
);


/**
 * @brief Low level generate to be called with already encoded input_ids tokens.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param tensor The input_ids encoded input prompt tokens.
 * @param generation_config Class to keep generation config parameters.
 * @param decoded_results EncodedResults a structure with resulting tokens and scores
 * @return Status code of the operation: OK(0) for success.
*/
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_tensor_with_config(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_tensor_t* tensor,
	const ov_genai_generation_config_t* generation_config,
	ov_genai_decoded_results_t** decoded_results
);

/**
 * @brief Low level generate to be called with already encoded input_ids tokens.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param tokenized_inputs The pair of (input_ids, attentino_mask) encoded input prompt tokens.
 * @param generation_config Class to keep generation config parameters.
 * @param decoded_results EncodedResults a structure with resulting tokens and scores
 * @return Status code of the operation: OK(0) for success.
*/
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_tokenized_inputs_with_config(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_tokenized_inputs_t* tokenized_inputs,
	const ov_genai_generation_config_t* generation_config,
	ov_genai_decoded_results_t** decoded_results
);


/**
 * @brief Low level generate to be called with already encoded input_ids tokens.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param tensor The input_ids encoded input prompt tokens.
 * @param callback Delegate function pointer.
 * @param decoded_results EncodedResults a structure with resulting tokens and scores
 * @return Status code of the operation: OK(0) for success.
*/
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_tensor_with_function(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_tensor_t* tensor,
	ov_genai_streamer_callback_t* callback,
	ov_genai_decoded_results_t** decoded_results
);

/**
 * @brief Low level generate to be called with already encoded input_ids tokens.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param tokenized_inputs The pair of (input_ids, attentino_mask) encoded input prompt tokens.
 * @param callback Delegate function pointer.
 * @param decoded_results EncodedResults a structure with resulting tokens and scores
 * @return Status code of the operation: OK(0) for success.
*/
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_tokenized_inputs_with_function(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_tokenized_inputs_t* tokenized_inputs,
	ov_genai_streamer_callback_t* callback,
	ov_genai_decoded_results_t** decoded_results
);


/**
 * @brief Low level generate to be called with already encoded input_ids tokens.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param tensor The input_ids encoded input prompt tokens.
 * @param generation_config Class to keep generation config parameters.
 * @param callback Delegate function pointer.
 * @param decoded_results EncodedResults a structure with resulting tokens and scores
 * @return Status code of the operation: OK(0) for success.
*/
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_tensor_with_config_function(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_tensor_t* tensor,
	const ov_genai_generation_config_t* generation_config,
	ov_genai_streamer_callback_t* callback,
	ov_genai_decoded_results_t** decoded_results
);

/**
 * @brief Low level generate to be called with already encoded input_ids tokens.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param tokenized_inputs The pair of (input_ids, attentino_mask) encoded input prompt tokens.
 * @param generation_config Class to keep generation config parameters.
 * @param callback Delegate function pointer.
 * @param decoded_results EncodedResults a structure with resulting tokens and scores
 * @return Status code of the operation: OK(0) for success.
*/
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_tokenized_inputs_with_config_function(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_tokenized_inputs_t* tokenized_inputs,
	const ov_genai_generation_config_t* generation_config,
	ov_genai_streamer_callback_t* callback,
	ov_genai_decoded_results_t** decoded_results
);


/**
 * @brief Low level generate to be called with already encoded input_ids tokens.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param tensor The input_ids encoded input prompt tokens.
 * @param config_param Structure to keep generation config parameters.
 * @param decoded_results EncodedResults a structure with resulting tokens and scores
 * @return Status code of the operation: OK(0) for success.
*/
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_tensor_with_config_map(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_tensor_t* tensor,
	const generation_config_param_t* config_param,
	ov_genai_decoded_results_t** decoded_results
);

/**
 * @brief Low level generate to be called with already encoded input_ids tokens.
 * @param llm_pipeline A point to ov_genai_llm_pipeline_t.
 * @param tokenized_inputs The pair of (input_ids, attentino_mask) encoded input prompt tokens.
 * @param config_param Structure to keep generation config parameters.
 * @param decoded_results EncodedResults a structure with resulting tokens and scores
 * @return Status code of the operation: OK(0) for success.
*/
OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_tokenized_inputs_with_config_map(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_tokenized_inputs_t* tokenized_inputs,
	const generation_config_param_t* config_param,
	ov_genai_decoded_results_t** decoded_results
);



OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_get_tokenizer(
	ov_genai_llm_pipeline_t* llm_pipeline,
	ov_genai_tokenizer_t** tokenizer);

OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_get_generation_config(
	ov_genai_llm_pipeline_t* llm_pipeline,
	ov_genai_generation_config_t** generation_config);

OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_set_generation_config(
	ov_genai_llm_pipeline_t* llm_pipeline,
	const ov_genai_generation_config_t* generation_config);

OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_start_chat(
	ov_genai_llm_pipeline_t* llm_pipeline);

OPENVINO_C_API(ov_status_e)
ov_genai_llm_pipeline_generate_finish_chat(
	ov_genai_llm_pipeline_t* llm_pipeline);