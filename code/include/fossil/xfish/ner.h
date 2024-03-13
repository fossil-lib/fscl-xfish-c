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
#ifndef FSCL_JELLYFISH_NER_H
#define FSCL_JELLYFISH_NER_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xfish/jellyfish.h"

// ========================================================================
// create and erase functions
// ========================================================================

// Function to create an NER model using the jellyfish library
jellyfish_model *fscl_ner_create_model(int input_size, int output_size, const char *model_name);

// Function to train the NER model
void fscl_ner_train(jellyfish_model *ner_model, float **input_data, float **target_data, int num_samples, int epochs, int batch_size);

// Function to perform NER prediction
float *fscl_ner_predict(jellyfish_model *ner_model, float *input);

// Function to save the NER model to a file
void fscl_ner_save_model(jellyfish_model *ner_model);

// Function to load the NER model from a file
jellyfish_model *fscl_ner_load_model(const char *model_name);

#ifdef __cplusplus
}
#endif

#endif