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
#ifndef FSCL_JELLYFISH_NLG_H
#define FSCL_JELLYFISH_NLG_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xfish/jellyfish.h"

// Define the JellyfishNLG structure
typedef struct {
    jellyfish_model *model;
} JellyfishNLG;

// ========================================================================
// create and erase functions
// ========================================================================

// Function to create a JellyfishNLG instance
JellyfishNLG *fscl_jellyfish_nlg_create(const char *model_name, int input_size, int output_size);

// Function to generate text using the NLG model
char *fscl_jellyfish_nlg_generate_text(JellyfishNLG *nlg, float *input_data);

// Function to free memory allocated for JellyfishNLG instance
void fscl_jellyfish_nlg_destroy(JellyfishNLG *nlg);

#ifdef __cplusplus
}
#endif

#endif
