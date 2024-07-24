// Copyright (C) 2024 Yan Guojin
// SPDX-License-Identifier: Apache-2.0
//

/**
* @file ov_genai_encoded_results.cpp
* @brief This is a header file for the ov_genai_generation_config C API, which is a C wrapper for ov::genai::EncodedResults.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/7/24
*/

#include "ov_genai_encoded_results.h"
#include <memory>

#include "genai_common.h"
#include <cstdarg>

ov_status_e ov_genai_encoded_results_create(ov_genai_encoded_results_t** encoded_results) {
    if (!encoded_results) {
        return ov_status_e::INVALID_C_PARAM;
    }

    try {
        std::unique_ptr<ov_genai_encoded_results_t> _encoded_results(new ov_genai_encoded_results_t);
        _encoded_results->object = std::make_shared<ov::genai::EncodedResults>();
        *encoded_results = _encoded_results.release();
    }
    CATCH_OV_GENAI_EXCEPTIONS
        return ov_status_e::OK;
}

void ov_genai_encoded_results_free(ov_genai_encoded_results_t* encoded_results) {
    if (encoded_results)
        delete encoded_results;
}