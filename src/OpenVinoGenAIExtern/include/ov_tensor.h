// Copyright (C) 2024 Yan Guojin. All rights reserved.
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_tensor.h
* @brief This is a header file for the ov_tensor C API, which is a C wrapper for ov::Tensor.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/7/27
*/
#pragma once
#include "openvino/openvino.hpp"
#include "ov_genai_common.h"

typedef struct ov_tensor ov_tensor_t;