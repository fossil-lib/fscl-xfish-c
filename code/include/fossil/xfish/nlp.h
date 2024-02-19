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

// Define the JellyfishNLP structure
enum {
    MAX_STOP_WORDS = 1000,
    MAX_WORD_LENGTH = 50
};

typedef struct {
    char stop_words[MAX_STOP_WORDS][MAX_WORD_LENGTH];
    int num_stop_words;
} StopWordsList;

typedef struct {
    jellyfish_model *model;
    StopWordsList stop_words_list;
} JellyfishNLP;

// ========================================================================
// create and erase functions
// ========================================================================

// Function to initialize a JellyfishNLP object
JellyfishNLP *fscl_jellyfish_nlp_create(const char *model_file, const char *stop_words_file);

// Function to perform NLP processing with stop words filtering
float *fscl_jellyfish_nlp_process(JellyfishNLP *nlp, float *input, const char *language, const char *tone);

// Function to deallocate memory for JellyfishNLP object
void fscl_jellyfish_nlp_erase(JellyfishNLP *nlp);

#ifdef __cplusplus
}
#endif

#endif
