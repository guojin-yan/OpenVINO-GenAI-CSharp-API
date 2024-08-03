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
#include "openvino/genai/generation_config.hpp"
#include "openvino/genai/llm_pipeline.hpp"
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

