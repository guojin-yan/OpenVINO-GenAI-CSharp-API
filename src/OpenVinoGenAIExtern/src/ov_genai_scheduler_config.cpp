// Copyright (C) 2024 Yan Guojin
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_scheduler_config.cpp
* @brief This is a header file for the ov_genai_scheduler_config C API, which is a C wrapper for ov::genai::SchedulerConfig.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/9/9
*/

#include "ov_genai_scheduler_config.h"
#include "genai_common.h"

ov_status_e ov_genai_scheduler_config_create(
    ov_genai_scheduler_config_t** scheduler_config) {

    if (!scheduler_config) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        std::unique_ptr<ov_genai_scheduler_config_t> _scheduler_config(new ov_genai_scheduler_config_t);
        _scheduler_config->object = std::make_shared<ov::genai::SchedulerConfig>();
        *scheduler_config = _scheduler_config.release();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e ov_genai_scheduler_config_create_with_param(
    ov_genai_scheduler_config_t** scheduler_config,
    ov_genai_scheduler_config_struct_t* scheduler_config_struct) {

    if (!scheduler_config || !scheduler_config_struct) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        std::unique_ptr<ov_genai_scheduler_config_t> _scheduler_config(new ov_genai_scheduler_config_t);
        _scheduler_config->object = std::make_shared<ov::genai::SchedulerConfig>();

        _scheduler_config->object->max_num_batched_tokens = scheduler_config_struct->max_num_batched_tokens;
        _scheduler_config->object->num_kv_blocks = scheduler_config_struct->num_kv_blocks;
        _scheduler_config->object->cache_size = scheduler_config_struct->cache_size;
        _scheduler_config->object->block_size = scheduler_config_struct->block_size;
        _scheduler_config->object->dynamic_split_fuse = scheduler_config_struct->dynamic_split_fuse;
        _scheduler_config->object->max_num_seqs = scheduler_config_struct->max_num_seqs;
        _scheduler_config->object->enable_prefix_caching = scheduler_config_struct->enable_prefix_caching;

        *scheduler_config = _scheduler_config.release();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

void ov_genai_scheduler_config_free(
    ov_genai_scheduler_config_t* scheduler_config) {
    if (scheduler_config)
        delete scheduler_config;
}


ov_status_e ov_genai_scheduler_set_max_num_batched_tokens(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t max_num_batched_tokens) {

    if (!scheduler_config) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        scheduler_config->object->max_num_batched_tokens = max_num_batched_tokens;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_scheduler_get_max_num_batched_tokens(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t* max_num_batched_tokens) {

    if (!scheduler_config || !max_num_batched_tokens) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        auto tmp = scheduler_config->object->max_num_batched_tokens;
        *max_num_batched_tokens = tmp;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_scheduler_set_num_kv_blocks(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t num_kv_blocks) {

    if (!scheduler_config) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        scheduler_config->object->num_kv_blocks = num_kv_blocks;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_scheduler_get_num_kv_blocks(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t* num_kv_blocks) {

    if (!scheduler_config || !num_kv_blocks) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        auto tmp = scheduler_config->object->num_kv_blocks;
        *num_kv_blocks = tmp;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_scheduler_set_cache_size(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t cache_size) {

    if (!scheduler_config) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        scheduler_config->object->cache_size = cache_size;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_scheduler_get_cache_size(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t* cache_size) {

    if (!scheduler_config || !cache_size) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        auto tmp = scheduler_config->object->cache_size;
        *cache_size = tmp;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_scheduler_set_block_size(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t block_size) {

    if (!scheduler_config ) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        scheduler_config->object->block_size = block_size;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_scheduler_get_block_size(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t* block_size) {

    if (!scheduler_config || !block_size) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        auto tmp = scheduler_config->object->block_size;
        *block_size = tmp;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_scheduler_set_dynamic_split_fuse(
    ov_genai_scheduler_config_t* scheduler_config,
    int dynamic_split_fuse) {

    if (!scheduler_config ) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        scheduler_config->object->dynamic_split_fuse = dynamic_split_fuse;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_scheduler_get_dynamic_split_fuse(
    ov_genai_scheduler_config_t* scheduler_config,
    int* dynamic_split_fuse) {

    if (!scheduler_config || !dynamic_split_fuse) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        auto tmp = scheduler_config->object->dynamic_split_fuse;
        *dynamic_split_fuse = tmp;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_scheduler_set_max_num_seqs(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t max_num_seqs) {

    if (!scheduler_config ) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        scheduler_config->object->max_num_seqs = max_num_seqs;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_scheduler_get_max_num_seqs(
    ov_genai_scheduler_config_t* scheduler_config,
    size_t* max_num_seqs) {

    if (!scheduler_config || !max_num_seqs) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        auto tmp = scheduler_config->object->max_num_seqs;
        *max_num_seqs = tmp;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_scheduler_set_enable_prefix_caching(
    ov_genai_scheduler_config_t* scheduler_config,
    int enable_prefix_caching) {

    if (!scheduler_config) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        scheduler_config->object->enable_prefix_caching = enable_prefix_caching;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

ov_status_e
ov_genai_scheduler_get_enable_prefix_caching(
    ov_genai_scheduler_config_t* scheduler_config,
    int* enable_prefix_caching) {

    if (!scheduler_config || !enable_prefix_caching) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        auto tmp = scheduler_config->object->enable_prefix_caching;
        *enable_prefix_caching = tmp;
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}