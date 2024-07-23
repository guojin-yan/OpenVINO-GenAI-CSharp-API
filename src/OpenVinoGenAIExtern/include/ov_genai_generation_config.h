// Copyright (C) 2024 Yan Guojin. All rights reserved.
// SPDX-License-Identifier: Apache-2.0
//


/**
* @file ov_genai_generation_config.h
* @brief This is a header file for the ov_genai_generation_config C API, which is a C wrapper for ov::genai::GenerationConfig.
* @version 1.0
* @author Yan Guojin guojin_yjs@cumt.edu.cn
* @date 2024/7/21
*/

#pragma once
#include "openvino/genai/generation_config.hpp"
#include "openvino/genai/llm_pipeline.hpp"
#include "openvino/genai/streamer_base.hpp"
#include "openvino/genai/tokenizer.hpp"
#include "openvino/genai/visibility.hpp"

#include "ov_genai_common.h"


/**
 * @struct ov_genai_generation_config_t
 * @ingroup ov_genai_generation_config_c_api
 * @brief type define ov_genai_generation_config_t from ov_genai_generation_config
 */
typedef struct ov_genai_generation_config ov_genai_generation_config_t;


/**
 * @brief Constructs OpenVINO GenAI GenerationConfig instance by default.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the newly created ov_genai_generation_config_t.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_create(ov_genai_generation_config_t** generation_config);

/**
 * @brief Constructs OpenVINO GenAI GenerationConfig instance by default.
 * @ingroup ov_genai_generation_config_c_api
 * @param json_path 
 * @param generation_config A pointer to the newly created ov_genai_generation_config_t.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_create_with_json(const char* json_path,
    ov_genai_generation_config_t** generation_config);


OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_get_max_new_tokens_with_prompt(const ov_genai_generation_config_t* generation_config,
    size_t prompt_length, size_t* max_new_tokens);


OPENVINO_C_API(bool)
ov_genai_generation_config_is_greedy_decoding(const ov_genai_generation_config_t* generation_config);


OPENVINO_C_API(bool)
ov_genai_generation_config_is_beam_search(const ov_genai_generation_config_t* generation_config);


OPENVINO_C_API(bool)
ov_genai_generation_config_is_multinomial(const ov_genai_generation_config_t* generation_config);

OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_update_generation_config(const ov_genai_generation_config_t* generation_config, 
    const size_t property_args_size, ...);

/**
 * @brief Checks that are no conflicting parameters, e.g. do_sample=true and num_beams > 1.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
validate(const ov_genai_generation_config_t* generation_config);



// Generic
/**
 * @brief Get the the maximum numbers of tokens to generate, excluding the number of tokens in the prompt. 
 * max_new_tokens has priority over max_length.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param max_new_tokens A pointer to the value of max_new_tokens.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_get_max_new_tokens(const ov_genai_generation_config_t* generation_config,
    size_t* max_new_tokens);

/**
 * @brief Set the the maximum numbers of tokens to generate, excluding the number of tokens in the prompt.
 * max_new_tokens has priority over max_length.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param max_new_tokens The value of max_new_tokens.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_set_max_new_tokens(const ov_genai_generation_config_t* generation_config,
    size_t max_new_tokens);
/**
 * @brief Get the the maximum length the generated tokens can have. Corresponds to the length of the input prompt +
 * `max_new_tokens`. Its effect is overridden by `max_new_tokens`, if also set.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param max_length A pointer to the value of max_length.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_get_max_length(const ov_genai_generation_config_t* generation_config,
    size_t* max_length);

/**
 * @brief Set the the maximum length the generated tokens can have. Corresponds to the length of the input prompt +
 * `max_new_tokens`. Its effect is overridden by `max_new_tokens`, if also set.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param max_length The value of max_length.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_set_max_length(const ov_genai_generation_config_t* generation_config,
    size_t max_length);
/**
 * @brief Get the ignore_eos param that if set to true, then generation will not stop even if <eos> token is met.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param ignore_eos A pointer to the value of ignore_eos.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_get_ignore_eos(const ov_genai_generation_config_t* generation_config,
    bool* ignore_eos);

/**
 * @brief Set the ignore_eos param that if set to true, then generation will not stop even if <eos> token is met.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param ignore_eos The value of ignore_eos.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_set_ignore_eos(const ov_genai_generation_config_t* generation_config,
    bool ignore_eos);

// Beam search specific
/**
 * @brief Get the number of groups to divide `num_beams` into in order to ensure diversity among different groups of beams.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param num_beam_groups A pointer to the value of num_beam_groups.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_get_num_beam_groups(const ov_genai_generation_config_t* generation_config,
    size_t* num_beam_groups);

/**
 * @brief Set the number of groups to divide `num_beams` into in order to ensure diversity among different groups of beams.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param num_beam_groups The value of num_beam_groups.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_set_num_beam_groups(const ov_genai_generation_config_t* generation_config,
    size_t num_beam_groups);

/**
 * @brief Get the number of beams for beam search. 1 disables beam search.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param num_beams A pointer to the value of num_beams.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_get_num_beams(const ov_genai_generation_config_t* generation_config,
    size_t* num_beams);

/**
 * @brief Set the number of beams for beam search. 1 disables beam search.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param num_beams The value of num_beams.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_set_num_beams(const ov_genai_generation_config_t* generation_config,
    size_t num_beams);

/**
 * @brief Get the diversity_penalty param that this value is subtracted from a beam's score if it generates 
 * the same token as any beam from other group at a particular time. See https://arxiv.org/pdf/1909.05858.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param diversity_penalty A pointer to the value of diversity_penalty.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_get_diversity_penalty(const ov_genai_generation_config_t* generation_config,
    float* diversity_penalty);

/**
 * @brief Set the diversity_penalty param that this value is subtracted from a beam's score if it generates
 * the same token as any beam from other group at a particular time. See https://arxiv.org/pdf/1909.05858.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param diversity_penalty The value of diversity_penalty.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_set_diversity_penalty(const ov_genai_generation_config_t* generation_config,
    float diversity_penalty);

/**
 * @brief Get the length_penalty param that exponential penalty to the length that is used with beam-based generation. 
 * It is applied as an exponent to the sequence length, which in turn is used to divide the score of the sequence. 
 * Since the score is the log likelihood of the sequence (i.e. negative), `length_penalty` > 0.0 promotes longer sequences, while
 * `length_penalty` < 0.0 encourages shorter sequences.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param length_penalty A pointer to the value of length_penalty.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_get_length_penalty(const ov_genai_generation_config_t* generation_config,
    float* length_penalty);

/**
 * @brief Set the length_penalty param that exponential penalty to the length that is used with beam-based generation.
 * It is applied as an exponent to the sequence length, which in turn is used to divide the score of the sequence.
 * Since the score is the log likelihood of the sequence (i.e. negative), `length_penalty` > 0.0 promotes longer sequences, while
 * `length_penalty` < 0.0 encourages shorter sequences.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param length_penalty The value of length_penalty.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_set_length_penalty(const ov_genai_generation_config_t* generation_config,
    float length_penalty);

/**
 * @brief Get the the number of sequences to return for grouped beam search decoding per batch element.
 * num_return_sequences must be less or equel to num_beams.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param num_return_sequences A pointer to the value of num_return_sequences.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_get_num_return_sequences(const ov_genai_generation_config_t* generation_config,
    size_t* num_return_sequences);

/**
 * @brief Set the the number of sequences to return for grouped beam search decoding per batch element.
 * num_return_sequences must be less or equel to num_beams.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config The ov_genai_generation_config_t.
 * @param num_return_sequences The value of num_return_sequences.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_set_num_return_sequences(const ov_genai_generation_config_t* generation_config,
    size_t num_return_sequences);

/**
 * @brief Get the no_repeat_ngram_size paran that if set to int > 0, all ngrams of that size can only occur once.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param no_repeat_ngram_size A pointer to the value of eos_token_id.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_get_no_repeat_ngram_size(const ov_genai_generation_config_t* generation_config,
    size_t* no_repeat_ngram_size);

/**
 * @brief Set the no_repeat_ngram_size paran that if set to int > 0, all ngrams of that size can only occur once.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param no_repeat_ngram_size The value of eos_token_id.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_set_no_repeat_ngram_size(const ov_genai_generation_config_t* generation_config,
    size_t no_repeat_ngram_size);

/**
 * @brief Get the stop_criteria param that controls the stopping condition for grouped beam search. It accepts the following values: 
 * "EARLY", where the generation stops as soon as there are `num_beams` complete candidates; "HEURISTIC", where an 
 * "HEURISTIC" is applied and the generation stops when is it very unlikely to find better candidates;
 * "NEVER", where the beam search procedure only stops when there cannot be better candidates (canonical beam search algorithm).
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param stop_criteria A pointer to the value of stop_criteria.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_get_stop_criteria(const ov_genai_generation_config_t* generation_config,
    ov::genai::StopCriteria* stop_criteria);

/**
 * @brief Set the stop_criteria param that controls the stopping condition for grouped beam search. It accepts the following values:
 * "EARLY", where the generation stops as soon as there are `num_beams` complete candidates; "HEURISTIC", where an
 * "HEURISTIC" is applied and the generation stops when is it very unlikely to find better candidates;
 * "NEVER", where the beam search procedure only stops when there cannot be better candidates (canonical beam search algorithm).
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config The ov_genai_generation_config_t.
 * @param stop_criteria A pointer to the value of stop_criteria.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_set_stop_criteria(const ov_genai_generation_config_t* generation_config,
    ov::genai::StopCriteria stop_criteria);

// Multinomial
/**
 * @brief Get the the value used to modulate token probabilities for random sampling.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param temperature A pointer to the value of temperature.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_get_temperature(const ov_genai_generation_config_t* generation_config,
    float* temperature);

/**
 * @brief Set the the value used to modulate token probabilities for random sampling.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param temperature The value of temperature.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_set_temperature(const ov_genai_generation_config_t* generation_config,
    float temperature);

/**
 * @brief Get the top_p param that if set to float < 1, only the smallest set of most probable
 * tokens with probabilities that add up to top_p or higher are kept for generation.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param top_p A pointer to the value of top_p.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_get_top_p(const ov_genai_generation_config_t* generation_config,
    float* top_p);

/**
 * @brief Set the top_p param that if set to float < 1, only the smallest set of most probable
 * tokens with probabilities that add up to top_p or higher are kept for generation.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param top_p The value of top_p.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_set_top_p(const ov_genai_generation_config_t* generation_config,
    float top_p);

/**
 * @brief Get the number of highest probability vocabulary tokens to keep for top-k-filtering.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param top_k A pointer to the value of top_k.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_get_top_k(const ov_genai_generation_config_t* generation_config,
    size_t* top_k);

/**
 * @brief Set the number of highest probability vocabulary tokens to keep for top-k-filtering.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param top_k The value of top_k.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_set_top_k(const ov_genai_generation_config_t* generation_config,
    size_t top_k);

/**
 * @brief Get the do_sample param that whether or not to use multinomial random sampling that add up to `top_p` or higher are kept.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param do_sample A pointer to the value of do_sample.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_get_do_sample(const ov_genai_generation_config_t* generation_config,
    bool* do_sample);

/**
 * @brief Set the do_sample param that whether or not to use multinomial random sampling that add up to `top_p` or higher are kept.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param do_sample The value of do_sample.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_set_do_sample(const ov_genai_generation_config_t* generation_config,
    bool do_sample);

/**
 * @brief Get the the parameter for repetition penalty. 1.0 means no penalty.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param repetition_penalty A pointer to the value of repetition_penalty.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_get_repetition_penalty(const ov_genai_generation_config_t* generation_config,
    float* repetition_penalty);

/**
 * @brief Set the the parameter for repetition penalty. 1.0 means no penalty.
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param repetition_penalty The value of repetition_penalty.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_set_repetition_penalty(const ov_genai_generation_config_t* generation_config,
    float repetition_penalty);


// EOS special token
/**
 * @brief Get the token_id of <eos> (end of sentence)
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param eos_token_id A pointer to the value of eos_token_id.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_get_eos_token_id(const ov_genai_generation_config_t* generation_config,
    int64_t* eos_token_id);

/**
 * @brief Set the token_id of <eos> (end of sentence)
 * @ingroup ov_genai_generation_config_c_api
 * @param generation_config A pointer to the ov_genai_generation_config_t.
 * @param eos_token_id The value of eos_token_id.
 * @return Status code of the operation: OK(0) for success.
 */
OPENVINO_C_API(ov_status_e)
ov_genai_generation_config_set_eos_token_id(const ov_genai_generation_config_t* generation_config,
    int64_t eos_token_id);