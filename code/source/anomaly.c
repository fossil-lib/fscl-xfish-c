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
#include "fossil/xfish/anomaly.h"

// Function to initialize an anomaly detection model
jellyfish_model *fscl_anomaly_create_model(int input_size, int output_size, const char *model_name) {
    return fscl_jellyfish_create_model(input_size, output_size, model_name);
}

// Function to train the anomaly detection model
void fscl_anomaly_train(jellyfish_model *model, float **input_data, int num_samples, int epochs, int batch_size) {
    // Training logic using jellyfish library
    // You might need to adapt this based on your anomaly detection requirements
    fscl_jellyfish_train(model, input_data, input_data, num_samples, epochs, batch_size);
}

// Function to detect anomalies using the trained model
float fscl_anomaly_detect(jellyfish_model *model, float *input) {
    // Get the prediction from the model
    float *prediction = fscl_jellyfish_predict(model, input);

    // Calculate the squared error between the input and the prediction
    float squared_error = 0.0;
    int output_size = fscl_jellyfish_get_model_output_size(model);
    for (int i = 0; i < output_size; ++i) {
        squared_error += (prediction[i] - input[i]) * (prediction[i] - input[i]);
    }

    // Normalize the squared error to obtain the anomaly score
    float anomaly_score = squared_error / output_size;

    // Free the memory allocated for the prediction
    fscl_jellyfish_erase_prediction(prediction);

    return anomaly_score;
}

// Function to save the anomaly detection model to a file
void fscl_anomaly_save_model(jellyfish_model *model) {
    fscl_jellyfish_save_model(model);
}

// Function to load the anomaly detection model from a file
jellyfish_model *fscl_anomaly_load_model(const char *model_name) {
    return fscl_jellyfish_load_model(model_name);
}
