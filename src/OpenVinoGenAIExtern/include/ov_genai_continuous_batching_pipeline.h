// Copyright (C) 2024 Yan Guojin
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_continuous_batching_pipeline.h
* @brief This is a header file for the ov_genai_continuous_batching_pipeline C API, 
* which is a C wrapper for ov::genai::ContinuousBatchingPipeline.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/9/9
*/


#pragma once
#include "genai_common.h"
#include "ov_genai_common.h"
#include "ov_genai_tokenizer.h"
#include "ov_genai_scheduler_config.h"
#include "ov_genai_generation_config.h"
#include <ov_genai_generation_handle.h>
#include <ov_genai_encoded_generation_result.h>
#include <ov_genai_generation_result.h>


typedef struct {
    // All requests as viewed by the pipeline
    size_t requests;
    // Requests scheduled for processing
    size_t scheduled_requests;
    // Percentage of KV cache usage
    float cache_usage;
} ov_genai_pipeline_metrics_t;

/**
* @struct ov_genai_continuous_batching_pipeline_t
* @brief This is an interface of ov::genai::ContinuousBatchingPipeline.
*/
typedef struct ov_genai_continuous_batching_pipeline ov_genai_continuous_batching_pipeline_t;

OPENVINO_C_API(ov_status_e)
ov_genai_continuous_batching_pipeline_create_with_scheduler(
    ov_genai_continuous_batching_pipeline_t** continuous_batching_pipeline,
    const char* model_path,
    ov_genai_scheduler_config_t* scheduler_config);

//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_create_with_scheduler_device(
//    ov_genai_continuous_batching_pipeline_t** continuous_batching_pipeline,
//    const char* model_path,
//    ov_genai_scheduler_config_t* scheduler_config,
//    const char* device_name);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_create_with_scheduler_device_plugin(
//    ov_genai_continuous_batching_pipeline_t** continuous_batching_pipeline,
//    const char* model_path,
//    ov_genai_scheduler_config_t* scheduler_config,
//    const char* device_name,
//    size_t llm_plugin_config_args_size,
//    size_t tokenizer_plugin_config_args_size,
//    ...);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_create_with_scheduler_tokenizer(
//    ov_genai_continuous_batching_pipeline_t** continuous_batching_pipeline,
//    const char* model_path,
//    ov_genai_tokenizer_t* tokenizer,
//    ov_genai_scheduler_config_t* scheduler_config);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_create_with_scheduler_tokenizer_device(
//    ov_genai_continuous_batching_pipeline_t** continuous_batching_pipeline,
//    const char* model_path,
//    ov_genai_tokenizer_t* tokenizer,
//    ov_genai_scheduler_config_t* scheduler_config,
//    const char* device_name);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_create_with_scheduler_tokenizer_device_plugin(
//    ov_genai_continuous_batching_pipeline_t** continuous_batching_pipeline,
//    const char* model_path,
//    ov_genai_tokenizer_t* tokenizer,
//    ov_genai_scheduler_config_t* scheduler_config,
//    const char* device_name,
//    size_t plugin_config_args_size,
//    ...);
//
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_get_tokenizer(
//    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
//    ov_genai_tokenizer_t** tokenizer);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_get_config(
//    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
//    ov_genai_generation_config_t** generation_config);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_get_metrics(
//    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
//    ov_genai_pipeline_metrics_t* pipeline_metrics);
//
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_get_metrics_add_request_with_input_ids(
//    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
//    uint64_t request_id,
//    ov_tensor_t* input_ids,
//    ov_genai_generation_config_t* sampling_params,
//    ov_genai_generation_handle_t** generation_handle);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_get_metrics_add_request_with_prompt(
//    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
//    uint64_t request_id,
//    const char* prompt,
//    ov_genai_generation_config_t* sampling_params,
//    ov_genai_generation_handle_t** generation_handle);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_step(
//    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_has_non_finished_requests(
//    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
//    int* flag);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_generate_with_input_ids(
//    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline, 
//    const ov_tensor_t* input_ids,
//    size_t input_ids_size,
//    const ov_genai_generation_config_t* sampling_params,
//    size_t sampling_params_size,
//    ov_genai_encoded_generation_result_t** encoded_generation_results,
//    size_t* encoded_generation_results_size);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_generate_with_input_ids_and_streamer(
//    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
//    const ov_tensor_t* input_ids,
//    size_t input_ids_size,
//    const ov_genai_generation_config_t* sampling_params,
//    size_t sampling_params_size,
//    ov_genai_streamer_callback_t* callback, 
//    ov_genai_encoded_generation_result_t** encoded_generation_results,
//    size_t* encoded_generation_results_size);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_generate_with_prompts(
//    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
//    const ov_genai_char_arrays_t inputs_array,
//    const  ov_genai_generation_config_t* sampling_params,
//    size_t sampling_params_size,
//    ov_genai_generation_result_t** generation_results,
//    size_t* generation_results_size);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_generate_with_prompts_and_streamer(
//    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
//    const ov_genai_char_arrays_t inputs_array,
//    const ov_genai_generation_config_t* sampling_params,
//    size_t sampling_params_size,
//    ov_genai_streamer_callback_t* callback,
//    ov_genai_generation_result_t** generation_results,
//    size_t* generation_results_size);
//
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_start_chat(
//    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
//    const char* system_message);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_finish_chat(
//    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline);