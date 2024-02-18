/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#ifndef FSCL_JELLYFISH_NLP_H
#define FSCL_JELLYFISH_NLP_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "jellyfish.h"

// Function to tokenize text
char **fscl_jellyfish_nlp_tokenize(const char *text, int *num_tokens);

// Function to preprocess text (e.g., lowercasing, removing punctuation)
char *fscl_jellyfish_nlp_preprocess(const char *text);

// Function to perform sentiment analysis
float fscl_jellyfish_nlp_sentiment_analysis(const char *text, jellyfish_model *sentiment_model);

// Function to perform named entity recognition
char **fscl_jellyfish_nlp_named_entity_recognition(const char *text, jellyfish_model *ner_model, int *num_entities);

// Function to train a sentiment analysis model
jellyfish_model *fscl_jellyfish_nlp_train_sentiment_analysis(const char **training_texts, const float *labels, int num_samples, int input_size, int output_size);

// Function to train a named entity recognition model
jellyfish_model *fscl_jellyfish_nlp_train_named_entity_recognition(const char **training_texts, const char **labels, int num_samples, int input_size, int output_size);

#ifdef __cplusplus
}
#endif

#endif
