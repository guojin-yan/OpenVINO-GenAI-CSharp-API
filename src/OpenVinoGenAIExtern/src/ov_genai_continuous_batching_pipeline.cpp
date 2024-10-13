// Copyright (C) 2024 Yan Guojin
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_continuous_batching_pipeline.cpp
* @brief This is a header file for the ov_genai_continuous_batching_pipeline C API,
* which is a C wrapper for ov::genai::ContinuousBatchingPipeline.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/9/22
*/

#include "ov_genai_continuous_batching_pipeline.h"
#include <memory>

#include "genai_common.h"
#include <cstdarg>


ov_status_e
ov_genai_continuous_batching_pipeline_create_with_scheduler(
    ov_genai_continuous_batching_pipeline_t** continuous_batching_pipeline,
    const char* model_path,
    ov_genai_scheduler_config_t* scheduler_config) {

    if (!continuous_batching_pipeline || !model_path || !scheduler_config) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        std::unique_ptr<ov_genai_continuous_batching_pipeline_t> 
            _continuous_batching_pipeline(new ov_genai_continuous_batching_pipeline_t);
        _continuous_batching_pipeline->object 
            = std::make_shared<ov::genai::ContinuousBatchingPipeline>(model_path, *scheduler_config);
        *continuous_batching_pipeline = _continuous_batching_pipeline.release();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_continuous_batching_pipeline_create_with_scheduler_device(
    ov_genai_continuous_batching_pipeline_t** continuous_batching_pipeline,
    const char* model_path,
    ov_genai_scheduler_config_t* scheduler_config,
    const char* device_name) {

    if (!continuous_batching_pipeline || !model_path || !scheduler_config || !device_name) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        std::unique_ptr<ov_genai_continuous_batching_pipeline_t>
            _continuous_batching_pipeline(new ov_genai_continuous_batching_pipeline_t);
        _continuous_batching_pipeline->object
            = std::make_shared<ov::genai::ContinuousBatchingPipeline>(model_path, *scheduler_config, device_name);
        *continuous_batching_pipeline = _continuous_batching_pipeline.release();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_continuous_batching_pipeline_create_with_scheduler_device_plugin(
    ov_genai_continuous_batching_pipeline_t** continuous_batching_pipeline,
    const char* model_path,
    ov_genai_scheduler_config_t* scheduler_config,
    const char* device_name,
    size_t llm_plugin_config_args_size,
    size_t tokenizer_plugin_config_args_size,
    ...) {

    if (!continuous_batching_pipeline || !model_path || !scheduler_config || !device_name) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {

        ov::AnyMap llm_plugin_config_args = {};
        ov::AnyMap tokenizer_plugin_config_args = {};
        size_t property_size = llm_plugin_config_args_size / 2;
        va_list args_ptr;
        va_start(args_ptr, tokenizer_plugin_config_args_size);
        for (size_t i = 0; i < property_size; i++) {
            std::string property_key = va_arg(args_ptr, char*); 
                std::string _value = va_arg(args_ptr, char*);      
                ov::Any value = _value;                            
                llm_plugin_config_args[property_key] = value;
        }
        property_size = tokenizer_plugin_config_args_size / 2;
        for (size_t i = 0; i < property_size; i++) {
            std::string property_key = va_arg(args_ptr, char*);
            std::string _value = va_arg(args_ptr, char*);
            ov::Any value = _value;
            tokenizer_plugin_config_args[property_key] = value;
        }
        va_end(args_ptr);


        std::unique_ptr<ov_genai_continuous_batching_pipeline_t>
            _continuous_batching_pipeline(new ov_genai_continuous_batching_pipeline_t);
        _continuous_batching_pipeline->object
            = std::make_shared<ov::genai::ContinuousBatchingPipeline>(model_path, *scheduler_config,
                device_name, llm_plugin_config_args, tokenizer_plugin_config_args);
        *continuous_batching_pipeline = _continuous_batching_pipeline.release();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_continuous_batching_pipeline_create_with_scheduler_tokenizer(
    ov_genai_continuous_batching_pipeline_t** continuous_batching_pipeline,
    const char* model_path,
    ov_genai_tokenizer_t* tokenizer,
    ov_genai_scheduler_config_t* scheduler_config) {

    if (!continuous_batching_pipeline || !model_path || !scheduler_config || !tokenizer) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {


        std::unique_ptr<ov_genai_continuous_batching_pipeline_t>
            _continuous_batching_pipeline(new ov_genai_continuous_batching_pipeline_t);
        _continuous_batching_pipeline->object
            = std::make_shared<ov::genai::ContinuousBatchingPipeline>(model_path, *tokenizer->object, *scheduler_config);
        *continuous_batching_pipeline = _continuous_batching_pipeline.release();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_continuous_batching_pipeline_create_with_scheduler_tokenizer_device(
    ov_genai_continuous_batching_pipeline_t** continuous_batching_pipeline,
    const char* model_path,
    ov_genai_tokenizer_t* tokenizer,
    ov_genai_scheduler_config_t* scheduler_config,
    const char* device_name) {


    if (!continuous_batching_pipeline || !model_path || !scheduler_config || !tokenizer || !device_name) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {


        std::unique_ptr<ov_genai_continuous_batching_pipeline_t>
            _continuous_batching_pipeline(new ov_genai_continuous_batching_pipeline_t);
        _continuous_batching_pipeline->object
            = std::make_shared<ov::genai::ContinuousBatchingPipeline>(model_path, *tokenizer->object, *scheduler_config, device_name);
        *continuous_batching_pipeline = _continuous_batching_pipeline.release();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_continuous_batching_pipeline_create_with_scheduler_tokenizer_device_plugin(
    ov_genai_continuous_batching_pipeline_t** continuous_batching_pipeline,
    const char* model_path,
    ov_genai_tokenizer_t* tokenizer,
    ov_genai_scheduler_config_t* scheduler_config,
    const char* device_name,
    size_t plugin_config_args_size,
    ...) {

    if (!continuous_batching_pipeline || !model_path || !scheduler_config || !device_name) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {

        ov::AnyMap plugin_config_args = {};

        size_t property_size = plugin_config_args_size / 2;
        va_list args_ptr;
        va_start(args_ptr, plugin_config_args_size);
        for (size_t i = 0; i < property_size; i++) {
            std::string property_key = va_arg(args_ptr, char*);
            std::string _value = va_arg(args_ptr, char*);
            ov::Any value = _value;
            plugin_config_args[property_key] = value;
        }
        va_end(args_ptr);



        std::unique_ptr<ov_genai_continuous_batching_pipeline_t>
            _continuous_batching_pipeline(new ov_genai_continuous_batching_pipeline_t);
        _continuous_batching_pipeline->object
            = std::make_shared<ov::genai::ContinuousBatchingPipeline>(model_path, *tokenizer->object, 
                *scheduler_config, device_name, plugin_config_args);
        *continuous_batching_pipeline = _continuous_batching_pipeline.release();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e
ov_genai_continuous_batching_pipeline_get_tokenizer(
    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
    ov_genai_tokenizer_t** tokenizer) {


    if (!continuous_batching_pipeline || !tokenizer) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        ov::genai::Tokenizer object;
        object = continuous_batching_pipeline->object->get_tokenizer();
        std::unique_ptr<ov_genai_tokenizer_t> _tokenizer(new ov_genai_tokenizer_t);
        _tokenizer->object = std::make_shared<ov::genai::Tokenizer>(std::move(object));
        *tokenizer = _tokenizer.release();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_continuous_batching_pipeline_get_config(
    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
    ov_genai_generation_config_t** generation_config) {

    if (!continuous_batching_pipeline || !generation_config) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        ov::genai::GenerationConfig object;
        object = continuous_batching_pipeline->object->get_config();
        std::unique_ptr<ov_genai_generation_config_t> _generation_config(new ov_genai_generation_config_t);
        _generation_config->object = std::make_shared<ov::genai::GenerationConfig>(std::move(object));
        *generation_config = _generation_config.release();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_continuous_batching_pipeline_get_metrics(
    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
    ov_genai_pipeline_metrics_t* pipeline_metrics) {


    if (!continuous_batching_pipeline || !pipeline_metrics) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        ov::genai::PipelineMetrics object;
        object = continuous_batching_pipeline->object->get_metrics();

        pipeline_metrics->requests = object.requests;
        pipeline_metrics->scheduled_requests = object.scheduled_requests;
        pipeline_metrics->cache_usage = object.cache_usage;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e
ov_genai_continuous_batching_pipeline_get_metrics_add_request_with_input_ids(
    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
    uint64_t request_id,
    ov_tensor_t* input_ids,
    ov_genai_generation_config_t* sampling_params,
    ov_genai_generation_handle_t** generation_handle) {

    if (!continuous_batching_pipeline || !request_id || !input_ids || !sampling_params || !generation_handle) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        ov::genai::GenerationHandle object;
        object = continuous_batching_pipeline->object->add_request(request_id, *input_ids->object, *sampling_params->object);

        std::unique_ptr<ov_genai_generation_handle_t> _generation_handle(new ov_genai_generation_handle_t);
        _generation_handle->object = std::move(object);
        *generation_handle = _generation_handle.release();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_continuous_batching_pipeline_get_metrics_add_request_with_prompt(
    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
    uint64_t request_id,
    const char* prompt,
    ov_genai_generation_config_t* sampling_params,
    ov_genai_generation_handle_t** generation_handle) {

    if (!continuous_batching_pipeline || !request_id || !prompt || !sampling_params || !generation_handle) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        ov::genai::GenerationHandle object;
        object = continuous_batching_pipeline->object->add_request(request_id, prompt, *sampling_params->object);
        std::unique_ptr<ov_genai_generation_handle_t> _generation_handle(new ov_genai_generation_handle_t);
        _generation_handle->object = std::move(object);
        *generation_handle = _generation_handle.release();
    
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

OPENVINO_C_API(ov_status_e)
ov_genai_continuous_batching_pipeline_step(
    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline) {
    if (!continuous_batching_pipeline) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        continuous_batching_pipeline->object->step();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

OPENVINO_C_API(ov_status_e)
ov_genai_continuous_batching_pipeline_has_non_finished_requests(
    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
    int* flag) {

    if (!continuous_batching_pipeline || !flag) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        *flag = static_cast<int>(continuous_batching_pipeline->object->has_non_finished_requests());
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_continuous_batching_pipeline_generate_with_input_ids(
    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
    const ov_tensor_t* input_ids,
    size_t input_ids_size,
    const ov_genai_generation_config_t* sampling_params,
    size_t sampling_params_size,
    ov_genai_encoded_generation_result_t** encoded_generation_results,
    size_t* encoded_generation_results_size) {

    if (!continuous_batching_pipeline || !input_ids || !sampling_params || !encoded_generation_results || !encoded_generation_results_size) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        std::vector<ov::Tensor> v_input_ids;
        for (int i = 0; i < input_ids_size; ++i) {
            v_input_ids.push_back(*input_ids[i].object);
        }
        std::vector<ov::genai::GenerationConfig> v_sampling_params;
        for (int i = 0; i < input_ids_size; ++i) {
            v_sampling_params.push_back(*sampling_params[i].object);
        }
        auto v_encoded_generation_results = continuous_batching_pipeline->object->generate(v_input_ids, v_sampling_params);

        *encoded_generation_results_size = v_encoded_generation_results.size();
        encoded_generation_results =
            (ov_genai_encoded_generation_result_t**)malloc(v_encoded_generation_results.size() * sizeof(ov_genai_encoded_generation_result_t*));
        for (int i = 0; i < v_encoded_generation_results.size(); ++i) {
            std::unique_ptr<ov_genai_encoded_generation_result_t> _generation_output(new ov_genai_encoded_generation_result_t);
            _generation_output->object = std::make_shared<ov::genai::EncodedGenerationResult>(std::move(v_encoded_generation_results[i]));
            encoded_generation_results[i] = _generation_output.release();
        }
       
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_continuous_batching_pipeline_generate_with_input_ids_and_streamer(
    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
    const ov_tensor_t* input_ids,
    size_t input_ids_size,
    const ov_genai_generation_config_t* sampling_params,
    size_t sampling_params_size,
    ov_genai_streamer_callback_t* callback,
    ov_genai_encoded_generation_result_t** encoded_generation_results,
    size_t* encoded_generation_results_size) {

    if (!continuous_batching_pipeline || !input_ids || !sampling_params || !callback || !encoded_generation_results 
        || !encoded_generation_results_size) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        std::vector<ov::Tensor> v_input_ids;
        for (int i = 0; i < input_ids_size; ++i) {
            v_input_ids.push_back(*input_ids[i].object);
        }
        std::vector<ov::genai::GenerationConfig> v_sampling_params;
        for (int i = 0; i < input_ids_size; ++i) {
            v_sampling_params.push_back(*sampling_params[i].object);
        }
        auto v_encoded_generation_results = continuous_batching_pipeline->object->generate(v_input_ids, v_sampling_params,*callback);

        *encoded_generation_results_size = v_encoded_generation_results.size();
        encoded_generation_results =
            (ov_genai_encoded_generation_result_t**)malloc(v_encoded_generation_results.size() * sizeof(ov_genai_encoded_generation_result_t*));
        for (int i = 0; i < v_encoded_generation_results.size(); ++i) {
            std::unique_ptr<ov_genai_encoded_generation_result_t> _generation_output(new ov_genai_encoded_generation_result_t);
            _generation_output->object = std::make_shared<ov::genai::EncodedGenerationResult>(std::move(v_encoded_generation_results[i]));
            encoded_generation_results[i] = _generation_output.release();
        }

    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


ov_status_e
ov_genai_continuous_batching_pipeline_generate_with_prompts(
    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
    const ov_genai_char_arrays_t* inputs_array,
    const  ov_genai_generation_config_t* sampling_params,
    size_t sampling_params_size,
    ov_genai_generation_result_t** generation_results,
    size_t* generation_results_size) {

    if (!continuous_batching_pipeline || !sampling_params || !generation_results
        || !generation_results_size) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {

        std::vector<std::string> prompts = char_arrays_to_str_array(*inputs_array);
        std::vector<ov::genai::GenerationConfig> v_sampling_params;
        for (int i = 0; i < sampling_params_size; ++i) {
            v_sampling_params.push_back(*sampling_params[i].object);
        }
        auto v_generation_results = continuous_batching_pipeline->object->generate(prompts, v_sampling_params);

        *generation_results_size = v_generation_results.size();
        generation_results =
            (ov_genai_generation_result_t**)malloc(v_generation_results.size() * sizeof(ov_genai_generation_result_t*));
        for (int i = 0; i < v_generation_results.size(); ++i) {
            std::unique_ptr<ov_genai_generation_result_t> _generation_output(new ov_genai_generation_result_t);
            _generation_output->object = std::make_shared<ov::genai::GenerationResult>(std::move(v_generation_results[i]));
            generation_results[i] = _generation_output.release();
        }

    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_continuous_batching_pipeline_generate_with_prompts_and_streamer(
    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
    const ov_genai_char_arrays_t* inputs_array,
    const ov_genai_generation_config_t* sampling_params,
    size_t sampling_params_size,
    ov_genai_streamer_callback_t* callback,
    ov_genai_generation_result_t** generation_results,
    size_t* generation_results_size){

    if (!continuous_batching_pipeline || !sampling_params || !generation_results || !callback
        || !generation_results_size) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {

        std::vector<std::string> prompts = char_arrays_to_str_array(*inputs_array);
        std::vector<ov::genai::GenerationConfig> v_sampling_params;
        for (int i = 0; i < sampling_params_size; ++i) {
            v_sampling_params.push_back(*sampling_params[i].object);
        }
        auto v_generation_results = continuous_batching_pipeline->object->generate(prompts, v_sampling_params, *callback);

        *generation_results_size = v_generation_results.size();
        generation_results =
            (ov_genai_generation_result_t**)malloc(v_generation_results.size() * sizeof(ov_genai_generation_result_t*));
        for (int i = 0; i < v_generation_results.size(); ++i) {
            std::unique_ptr<ov_genai_generation_result_t> _generation_output(new ov_genai_generation_result_t);
            _generation_output->object = std::make_shared<ov::genai::GenerationResult>(std::move(v_generation_results[i]));
            generation_results[i] = _generation_output.release();
        }

    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}


OPENVINO_C_API(ov_status_e)
ov_genai_continuous_batching_pipeline_start_chat(
    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline,
    const char* system_message) {

    if (!continuous_batching_pipeline || !system_message) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        continuous_batching_pipeline->object->start_chat(system_message);
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

OPENVINO_C_API(ov_status_e)
ov_genai_continuous_batching_pipeline_finish_chat(
    ov_genai_continuous_batching_pipeline_t* continuous_batching_pipeline) {

    if (!continuous_batching_pipeline) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        continuous_batching_pipeline->object->finish_chat();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}