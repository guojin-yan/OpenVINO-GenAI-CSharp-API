// Copyright (C) 2018-2024 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//
#pragma once
#include <cassert>
#include <fstream>
#include <iterator>
#include <map>
#include <streambuf>
#include <string>

#include "openvino/core/except.hpp"
#include "openvino/openvino.hpp"
#include "openvino/runtime/exception.hpp"
#include "openvino/genai/continuous_batching_pipeline.hpp"
#include "openvino/genai/generation_config.hpp"
#include "openvino/genai/llm_pipeline.hpp"
#include "openvino/genai/perf_metrics.hpp"
#include "openvino/genai/scheduler_config.hpp"
#include "openvino/genai/streamer_base.hpp"
#include "openvino/genai/tokenizer.hpp"
#include "openvino/genai/visibility.hpp"

#include "ov_genai_common.h"

#define CATCH_OV_GENAI_EXCEPTION(StatusCode, ExceptionType) \
    catch (const ov::ExceptionType& ex) {             \
        dup_last_err_msg(ex.what());                  \
        return ov_status_e::StatusCode;               \
    }

#define CATCH_OV_GENAI_EXCEPTIONS                                \
    CATCH_OV_GENAI_EXCEPTION(REQUEST_BUSY, Busy)                 \
    CATCH_OV_GENAI_EXCEPTION(INFER_CANCELLED, Cancelled)         \
    CATCH_OV_GENAI_EXCEPTION(NOT_IMPLEMENTED, NotImplemented)    \
    CATCH_OV_GENAI_EXCEPTION(GENERAL_ERROR, Exception)           \
    catch (...) {                                          \
        dup_last_err_msg("An unknown exception occurred"); \
        return ov_status_e::UNKNOW_EXCEPTION;              \
    }

#define GET_PROPERTY_FROM_ARGS_LIST                     \
    std::string property_key = va_arg(args_ptr, char*); \
    std::string _value = va_arg(args_ptr, char*);       \
    ov::Any value = _value;                             \
    property[property_key] = value;




struct ov_infer_request {
    std::shared_ptr<ov::InferRequest> object;
};

/**
 * @struct ov_tensor
 * @brief This is an interface of ov_tensor
 */
struct ov_tensor {
    std::shared_ptr<ov::Tensor> object;
};
/**
 * @struct ov_genai_generation_config
 * @brief This is an interface of ov::genai::GenerationConfig.
 * GenerationConfig structure to keep generation config parameters. For a selected method of decoding, only parameters from that group
 * and generic parameters are used. For example, if do_sample is set to true, then only generic parameters and random sampling parameters will 
 * be used while greedy and beam search parameters will not affect decoding at all.
 */
struct ov_genai_generation_config {
    std::shared_ptr<ov::genai::GenerationConfig> object;
};
/**
* @struct ov_genai_encoded_results
* @brief This is an interface of ov::genai::EncodedResults.
* Structure to store resulting batched tokens and scores for each batch sequence.
* The first num_return_sequences elements correspond to the first batch element.
* In the case if results decoded with beam search and random sampling scores contain
* sum of logarithmic probabilities for each token in the sequence. In the case
* of greedy decoding scores are filled with zeros.
*/
struct ov_genai_encoded_results {
    std::shared_ptr<ov::genai::EncodedResults> object;
};
/**
* @struct ov_genai_decoded_results
* @brief  This is an interface of ov::genai::DecodedResults.
* Structure to store resulting batched text outputs and scores for each batch
* The first num_return_sequences elements correspond to the first batch element.
*/
struct ov_genai_decoded_results {
    std::shared_ptr<ov::genai::DecodedResults> object;
};
/**
* @struct ov_genai_llm_pipeline
* @brief  This is an interface of ov::genai::LLMPipeline.
* This class is used for generation with LLMs.
*/
struct ov_genai_llm_pipeline {
    std::shared_ptr<ov::genai::LLMPipeline> object;
};
/**
* @struct ov_genai_tokenizer
* @brief  This is an interface of ov::genai::Tokenizer.
* This class is used to encode prompts and decode resulting tokens.
*/
struct ov_genai_tokenizer {
    std::shared_ptr<ov::genai::Tokenizer> object;
};

/**
* @struct ov_genai_tokenized_inputs
* @brief  This is an interface of ov::genai::TokenizedInputs.
* This class is used to tokenized inputs.
*/
struct ov_genai_tokenized_inputs {
    std::shared_ptr<ov::genai::TokenizedInputs> object;
};

/**
* @struct ov_genai_raw_perf_metrics
* @brief  This is an interface of ov::genai::RawPerfMetrics.
* Structure with raw performance metrics for each generation 
* before any statistics calculated.
*/
struct ov_genai_raw_perf_metrics {
    std::shared_ptr<ov::genai::RawPerfMetrics> object;
};

/**
* @struct ov_genai_perf_metrics
* @brief  This is an interface of ov::genai::PerfMetrics.
* Structure to store performance metric for each generation.
*/
struct ov_genai_perf_metrics {
    std::shared_ptr<ov::genai::PerfMetrics> object;
};

/**
* @struct ov_genai_scheduler_config
* @brief  This is an interface of ov::genai::SchedulerConfig.
*/
struct ov_genai_scheduler_config {
    std::shared_ptr<ov::genai::SchedulerConfig> object;
};


/**
* @struct ov_genai_continuous_batching_pipeline
* @brief  This is an interface of ov::genai::SchedulerConfig.
*/
struct ov_genai_continuous_batching_pipeline {
    std::shared_ptr<ov::genai::ContinuousBatchingPipeline> object;
};


/**
* @struct ov_genai_encoded_generation_result
* @brief  This is an interface of ov::genai::EncodedGenerationResult.
*/
struct ov_genai_encoded_generation_result {
    std::shared_ptr<ov::genai::EncodedGenerationResult> object;
};


/**
* @struct ov_genai_generation_result
* @brief  This is an interface of ov::genai::GenerationResult.
*/
struct ov_genai_generation_result {
    std::shared_ptr<ov::genai::GenerationResult> object;
};

/**
* @struct ov_genai_generation_output
* @brief  This is an interface of ov::genai::GenerationOutput.
*/
struct ov_genai_generation_output {
    std::shared_ptr<ov::genai::GenerationOutput> object;
};

/**
* @struct ov_genai_generation_outputs
* @brief  This is an interface of ov::genai::GenerationOutputs.
*/
struct ov_genai_generation_outputs {
    std::shared_ptr<ov::genai::GenerationOutputs> object;
};


/**
* @struct ov_genai_generation_handle
* @brief  This is an interface of ov::genai::GenerationHandleImpl.
*/
struct ov_genai_generation_handle {
    std::shared_ptr<ov::genai::GenerationHandleImpl> object;
};

typedef bool(__stdcall* ov_genai_streamer_callback_t)(std::string str);

/**
 * @struct ov_string_array
 * @ingroup ov_genai_llm_pipeline_c_api
 * @brief String array structure.
 */
typedef struct {
    char** string_array;
    size_t size;
} ov_genai_char_arrays_t;


/**
 * @brief Convert character array structure to string array.
 * @param char_arrays The character array structure.
 * @return The converted string array.
*/
std::vector<std::string> char_arrays_to_str_array(const ov_genai_char_arrays_t inputs_array);


/**
 * @struct ov_int_arrays
 * @ingroup ov_genai_llm_pipeline_c_api
 * @brief std::vector<std::vector<int64_t>>.
 */
typedef struct {
    int64_t size;
    int64_t* arrays_size;
    int64_t* arrays;
} ov_genai_double_int_arrays_t;

ov_genai_double_int_arrays_t int_vectors_to__double_int_arrays(std::vector<std::vector<int64_t>> data);

/**
 * @brief Convert Time Point to nanosecond representation.
 * @param timepoint The time point.
 * @return The nanoseconds.
*/
size_t timepoint_to_nanoseconds(std::chrono::steady_clock::time_point timepoint);

/**
 * @brief Convert nanosecond to Time Point representation.
 * @param nanoseconds The nanosecond.
 * @return The Time Point.
*/
std::chrono::steady_clock::time_point nanoseconds_to_timepoint(size_t nanoseconds);


/**
 * @struct mem_stringbuf
 * @brief This struct puts memory buffer to stringbuf.
 */
struct mem_stringbuf : std::streambuf {
    mem_stringbuf(const char* buffer, size_t sz) {
        char* bptr(const_cast<char*>(buffer));
        setg(bptr, bptr, bptr + sz);
    }

    pos_type seekoff(off_type off,
        std::ios_base::seekdir dir,
        std::ios_base::openmode which = std::ios_base::in) override {
        switch (dir) {
        case std::ios_base::beg:
            setg(eback(), eback() + off, egptr());
            break;
        case std::ios_base::end:
            setg(eback(), egptr() + off, egptr());
            break;
        case std::ios_base::cur:
            setg(eback(), gptr() + off, egptr());
            break;
        default:
            return pos_type(off_type(-1));
        }
        return (gptr() < eback() || gptr() > egptr()) ? pos_type(off_type(-1)) : pos_type(gptr() - eback());
    }

    pos_type seekpos(pos_type pos, std::ios_base::openmode which) override {
        return seekoff(pos, std::ios_base::beg, which);
    }
};

/**
 * @struct mem_istream
 * @brief This struct puts stringbuf buffer to istream.
 */
struct mem_istream : virtual mem_stringbuf, std::istream {
    mem_istream(const char* buffer, size_t sz)
        : mem_stringbuf(buffer, sz),
        std::istream(static_cast<std::streambuf*>(this)) {}
};

char* str_to_char_array(const std::string& str);
void dup_last_err_msg(const char* msg);

