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

#include "fossil/xfish/jellyfish.h"

extern const char *CANADIAN_STOP_WORDS[];
extern const char *ENGLISH_STOP_WORDS[];
extern const char *SPANISH_STOP_WORDS[];
extern const char *ITALIAN_STOP_WORDS[];
extern const char *RUSSIAN_STOP_WORDS[];

typedef struct {
    jellyfish_model *model;
    char ***stop_words_list;  // Ensure stop_words_list is declared as char ***
} JellyfishNLP;

// ========================================================================
// create and erase functions
// ========================================================================

// Function to initialize a JellyfishNLP object
JellyfishNLP *fscl_jellyfish_nlp_create(const char *model_file, const char *language);

// Function to perform NLP processing with stop words filtering
float *fscl_jellyfish_nlp_process(JellyfishNLP *nlp, float *input, const char *language, const char *tone);

// Function to deallocate memory for JellyfishNLP object
void fscl_jellyfish_nlp_erase(JellyfishNLP *nlp);

#ifdef __cplusplus
}
#endif

#endif
