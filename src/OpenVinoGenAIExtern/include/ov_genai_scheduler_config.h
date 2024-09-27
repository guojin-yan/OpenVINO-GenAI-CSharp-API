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



/**
* @struct ov_genai_scheduler_config_t
* @brief This is an interface of ov::genai::SchedulerConfig.
*/
typedef ov::genai::SchedulerConfig ov_genai_scheduler_config_t;
