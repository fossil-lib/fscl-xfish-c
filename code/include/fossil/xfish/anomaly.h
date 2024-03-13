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
#ifndef FSCL_JELLYFISH_ANOMALY_H
#define FSCL_JELLYFISH_ANOMALY_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xfish/jellyfish.h"

// ========================================================================
// create and erase functions
// ========================================================================

// Function to initialize an anomaly detection model
jellyfish_model *fscl_anomaly_create_model(int input_size, int output_size, const char *model_name);

// Function to train the anomaly detection model
void fscl_anomaly_train(jellyfish_model *model, float **input_data, int num_samples, int epochs, int batch_size);

// Function to detect anomalies using the trained model
float fscl_anomaly_detect(jellyfish_model *model, float *input);

// Function to save the anomaly detection model to a file
void fscl_anomaly_save_model(jellyfish_model *model);

// Function to load the anomaly detection model from a file
jellyfish_model *fscl_anomaly_load_model(const char *model_name);

#ifdef __cplusplus
}
#endif

#endif