// Copyright (C) 2024 Yan Guojin
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_scheduler_config.h
* @brief This is a header file for the ov_genai_scheduler_config C API, which is a C wrapper for ov::genai::SchedulerConfig.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/9/9
*/


#pragma once
#include "openvino/genai/generation_config.hpp"
#include "openvino/genai/llm_pipeline.hpp"
#include "openvino/genai/perf_metrics.hpp"
#include "openvino/genai/streamer_base.hpp"
#include "openvino/genai/tokenizer.hpp"
#include "openvino/genai/visibility.hpp"

#include "ov_genai_common.h"


typedef struct {
    std::size_t max_num_batched_tokens;
    std::size_t num_kv_blocks;
    std::size_t cache_size;
    std::size_t block_size;
    bool dynamic_split_fuse;
    std::size_t max_num_seqs;
    bool enable_prefix_caching;
}ov_genai_scheduler_config_struct_t;

/**
* @struct ov_genai_scheduler_config_t
* @brief This is an interface of ov::genai::SchedulerConfig.
*/
typedef struct ov_genai_scheduler_config ov_genai_scheduler_config_t;

OPENVINO_C_API(ov_status_e)
ov_genai_scheduler_config_create(ov_genai_scheduler_config_t** scheduler_config);

OPENVINO_C_API(ov_status_e)
ov_genai_scheduler_config_create_with_param(
    ov_genai_scheduler_config_t** scheduler_config,
    ov_genai_scheduler_config_struct_t* scheduler_config_struct);

OPENVINO_C_API(void)
ov_genai_scheduler_config_free(ov_genai_scheduler_config_t* scheduler_config);


OPENVINO_C_API(ov_status_e)
ov_genai_scheduler_set_max_num_batched_tokens(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t max_num_batched_tokens);

OPENVINO_C_API(ov_status_e)
ov_genai_scheduler_get_max_num_batched_tokens(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t* max_num_batched_tokens);

OPENVINO_C_API(ov_status_e)
ov_genai_scheduler_set_num_kv_blocks(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t num_kv_blocks);

OPENVINO_C_API(ov_status_e)
ov_genai_scheduler_get_num_kv_blocks(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t* num_kv_blocks);

OPENVINO_C_API(ov_status_e)
ov_genai_scheduler_set_cache_size(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t cache_size);

OPENVINO_C_API(ov_status_e)
ov_genai_scheduler_get_cache_size(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t* cache_size);

OPENVINO_C_API(ov_status_e)
ov_genai_scheduler_set_block_size(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t block_size);

OPENVINO_C_API(ov_status_e)
ov_genai_scheduler_get_block_size(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t* block_size);

OPENVINO_C_API(ov_status_e)
ov_genai_scheduler_set_dynamic_split_fuse(
    ov_genai_scheduler_config_t* scheduler_config,
    int dynamic_split_fuse);

OPENVINO_C_API(ov_status_e)
ov_genai_scheduler_get_dynamic_split_fuse(
    ov_genai_scheduler_config_t* scheduler_config,
    int* dynamic_split_fuse);

OPENVINO_C_API(ov_status_e)
ov_genai_scheduler_set_max_num_seqs(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t max_num_seqs);

OPENVINO_C_API(ov_status_e)
ov_genai_scheduler_get_max_num_seqs(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t* max_num_seqs);

OPENVINO_C_API(ov_status_e)
ov_genai_scheduler_set_enable_prefix_caching(
    ov_genai_scheduler_config_t* scheduler_config,
    int enable_prefix_caching);

OPENVINO_C_API(ov_status_e)
ov_genai_scheduler_get_enable_prefix_caching(
    ov_genai_scheduler_config_t* scheduler_config,
    int* enable_prefix_caching);