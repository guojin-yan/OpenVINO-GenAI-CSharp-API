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


typedef struct {
    // All requests as viewed by the pipeline
    size_t requests;
    // Requests scheduled for processing
    size_t scheduled_requests;
    // Percentage of KV cache usage
    float cache_usage;
}ov_genai_pipeline_metrics_t;

/**
* @struct ov_genai_continuous_batching_pipeline_t
* @brief This is an interface of ov::genai::ContinuousBatchingPipeline.
*/
typedef struct ov_genai_continuous_batching_pipeline ov_genai_continuous_batching_pipeline_t;

//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_create_with_scheduler(
//    ov_genai_continuous_batching_pipeline_t** perf_metrics,
//    const char* model_path);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_create_with_scheduler_device(
//    ov_genai_continuous_batching_pipeline_t** perf_metrics,
//    const char* model_path,
//    const char* device_name);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_create_with_scheduler_device_plugin(
//    ov_genai_continuous_batching_pipeline_t** perf_metrics,
//    const char* model_path,
//    const char* device_name,
//    size_t llm_plugin_config_args_size,
//    size_t tokenizer_plugin_config_args_size,
//    ...);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_create_with_scheduler_scheduler_tokenizer(
//    ov_genai_continuous_batching_pipeline_t** perf_metrics,
//    const char* model_path,
//    ov_genai_tokenizer_t* tokenizer,
//    ov_genai_scheduler_config_t* scheduler_config);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_create_with_scheduler_scheduler_tokenizer_device(
//    ov_genai_continuous_batching_pipeline_t** perf_metrics,
//    const char* model_path,
//    ov_genai_tokenizer_t* tokenizer,
//    ov_genai_scheduler_config_t* scheduler_config,
//    const char* device_name);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_create_with_scheduler_scheduler_tokenizer_device_plugin(
//    ov_genai_continuous_batching_pipeline_t** perf_metrics,
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
//    ov_genai_continuous_batching_pipeline_t* perf_metrics,
//    ov_genai_tokenizer_t** tokenizer);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_get_config(
//    ov_genai_continuous_batching_pipeline_t* perf_metrics,
//    ov_genai_generation_config_t** generation_config);
//
//OPENVINO_C_API(ov_status_e)
//ov_genai_continuous_batching_pipeline_get_metrics(
//    ov_genai_continuous_batching_pipeline_t* perf_metrics,
//    ov_genai_pipeline_metrics_t** pipeline_metrics);