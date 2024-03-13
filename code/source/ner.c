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
#include "fossil/xfish/ner.h"

jellyfish_model *fscl_ner_create_model(int input_size, int output_size, const char *model_name) {
    // Create an NER model using the jellyfish library
    return fscl_jellyfish_create_model(input_size, output_size, model_name);
}

void fscl_ner_train(jellyfish_model *ner_model, float **input_data, float **target_data, int num_samples, int epochs, int batch_size) {
    // Train the NER model using the jellyfish library
    fscl_jellyfish_train(ner_model, input_data, target_data, num_samples, epochs, batch_size);
}

float *fscl_ner_predict(jellyfish_model *ner_model, float *input) {
    // Perform NER prediction using the jellyfish library
    return fscl_jellyfish_predict(ner_model, input);
}

void fscl_ner_save_model(jellyfish_model *ner_model) {
    // Save the NER model to a file using the jellyfish library
    fscl_jellyfish_save_model(ner_model);
}

jellyfish_model *fscl_ner_load_model(const char *model_name) {
    // Load the NER model from a file using the jellyfish library
    return fscl_jellyfish_load_model(model_name);
}
