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
#ifndef FSCL_JELLYFISH_NLU_H
#define FSCL_JELLYFISH_NLU_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xfish/jellyfish.h"

// Define the JellyfishNLU structure
typedef struct {
    jellyfish_model *model;
} JellyfishNLU;

// ========================================================================
// create and erase functions
// ========================================================================

// Function to initialize JellyfishNLU
JellyfishNLU* fscl_jellyfish_nlu_create(int input_size, int output_size, const char *model_name);

// Function to process natural language input
float* fscl_jellyfish_nlu_process_input(JellyfishNLU *nlu, const char *input_text);

// Function to train the NLU model
void fscl_jellyfish_nlu_train(JellyfishNLU *nlu, const char **input_data, float **target_data, int num_samples, int epochs, int batch_size);

// Function to save the NLU model to a file
void fscl_jellyfish_nlu_save_model(JellyfishNLU *nlu);

// Function to load the NLU model from a file
JellyfishNLU* fscl_jellyfish_nlu_load_model(const char *model_name);

// Function to free memory allocated for JellyfishNLU
void fscl_jellyfish_nlu_erase(JellyfishNLU *nlu);

#ifdef __cplusplus
}
#endif

#endif
