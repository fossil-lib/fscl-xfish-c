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
#include "fossil/xfish/nlg.h"

#include <stdio.h>
#include <stdlib.h>

// Function to find the index of the maximum value in an array
int find_max_index(float *array, int size) {
    int max_index = 0;
    float max_value = array[0];

    for (int i = 1; i < size; ++i) {
        if (array[i] > max_value) {
            max_value = array[i];
            max_index = i;
        }
    }

    return max_index;
}

// Function to create a JellyfishNLG instance
JellyfishNLG *fscl_jellyfish_nlg_create(const char *model_name, int input_size, int output_size) {
    JellyfishNLG *nlg = (JellyfishNLG *)malloc(sizeof(JellyfishNLG));
    if (nlg == NULL) {
        // Handle memory allocation error
        return NULL;
    }

    nlg->model = fscl_jellyfish_create_model(input_size, output_size, model_name);
    if (nlg->model == NULL) {
        // Handle model creation error
        free(nlg);
        return NULL;
    }

    // Add layers to the model (customize as needed)
    fscl_jellyfish_add_layer(nlg->model->network, input_size, 128, ReLU);
    fscl_jellyfish_add_layer(nlg->model->network, 128, 256, ReLU);
    fscl_jellyfish_add_layer(nlg->model->network, 256, output_size, Tanh);

    // Configure training parameters (customize as needed)
    fscl_jellyfish_configure_training(nlg->model, MeanSquaredError, Adam, 0.001f);

    return nlg;
}

// Function to generate text using the NLG model
char *fscl_jellyfish_nlg_generate_text(JellyfishNLG *nlg, float *input_data) {
    // Make predictions using the model
    float *output = fscl_jellyfish_predict(nlg->model, input_data);
    if (output == NULL) {
        // Handle prediction error
        return NULL;
    }

    // Find the index with the highest probability
    int max_index = find_max_index(output, fscl_jellyfish_get_model_output_size(nlg->model));

    // Allocate memory for text (assuming a simple word index-based representation)
    char *text = (char *)malloc(sizeof(char) * (max_index + 1));
    if (text == NULL) {
        // Handle memory allocation error
        fscl_jellyfish_erase_prediction(output);
        return NULL;
    }

    // Convert the index to text (customize based on your vocabulary)
    sprintf(text, "%d", max_index);

    // Free prediction output
    fscl_jellyfish_erase_prediction(output);

    return text;
}

// Function to free memory allocated for JellyfishNLG instance
void fscl_jellyfish_nlg_destroy(JellyfishNLG *nlg) {
    if (nlg != NULL) {
        // Erase the model
        fscl_jellyfish_erase_model(nlg->model);

        // Free NLG instance memory
        free(nlg);
    }
}
