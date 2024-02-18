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
#include "fossil/xfish/jellyfish.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Custom strdup function
static char *fscl_jellyfish_strdup(const char *str) {
    size_t len = strlen(str) + 1;  // Including the null terminator
    char *duplicate = (char *)malloc(len);
    if (duplicate != NULL) {
        strcpy(duplicate, str);
    }
    return duplicate;
}

// Function to initialize a jellyfish neural network
jellyfish_network *fscl_jellyfish_create_network(int input_size, int output_size) {
    jellyfish_network *network = (jellyfish_network *)malloc(sizeof(jellyfish_network));
    network->num_layers = 0;
    network->layers = NULL;
    network->loss_function = MeanSquaredError;  // Default loss function
    network->optimizer = SGD;  // Default optimizer
    network->learning_rate = 0.01;  // Default learning rate
    return network;
}

// Function to create a jellyfish model
jellyfish_model *fscl_jellyfish_create_model(int input_size, int output_size, const char *model_name) {
    jellyfish_model *model = (jellyfish_model *)malloc(sizeof(jellyfish_model));
    model->network = fscl_jellyfish_create_network(input_size, output_size);
    model->model_name = fscl_jellyfish_strdup(model_name);
    return model;
}

// Function to add a layer to the jellyfish neural network
void fscl_jellyfish_add_layer(jellyfish_network *network, int layer_input_size, int layer_output_size, ActivationFunction activation_function) {
    jellyfish_layer *layer = (jellyfish_layer *)malloc(sizeof(jellyfish_layer));
    layer->input_size = layer_input_size;
    layer->output_size = layer_output_size;
    layer->weights = (float **)malloc(sizeof(float *) * layer_input_size);
    for (int i = 0; i < layer_input_size; ++i) {
        layer->weights[i] = (float *)malloc(sizeof(float) * layer_output_size);
        for (int j = 0; j < layer_output_size; ++j) {
            layer->weights[i][j] = 0.0f;
        }
    }
    layer->biases = (float *)malloc(sizeof(float) * layer_output_size);
    for (int i = 0; i < layer_output_size; ++i) {
        layer->biases[i] = 0.0f;
    }
    layer->activation_function = activation_function;

    network->layers = (jellyfish_layer **)realloc(network->layers, sizeof(jellyfish_layer *) * (network->num_layers + 1));
    network->layers[network->num_layers++] = layer;
}

// Function to configure training hyperparameters
void fscl_jellyfish_configure_training(jellyfish_model *model, LossFunction loss_function, OptimizationAlgorithm optimizer, float learning_rate) {
    model->network->loss_function = loss_function;
    model->network->optimizer = optimizer;
    model->network->learning_rate = learning_rate;
}

// Function to train the jellyfish neural network
void fscl_jellyfish_train(jellyfish_model *model, float **input_data, float **target_data, int num_samples, int epochs, int batch_size) {
    for (int epoch = 0; epoch < epochs; ++epoch) {
        for (int sample = 0; sample < num_samples; sample += batch_size) {
            int batch_end = (sample + batch_size < num_samples) ? (sample + batch_size) : num_samples;

            for (int i = sample; i < batch_end; ++i) {
                // Forward pass (simplified for illustration)
                float *input = input_data[i];
                float *target = target_data[i];
                float *output = fscl_jellyfish_predict(model, input);

                // Backward pass (simplified for illustration)
                for (int layer_idx = model->network->num_layers - 1; layer_idx >= 0; --layer_idx) {
                    jellyfish_layer *layer = model->network->layers[layer_idx];

                    // Update weights and biases based on the error gradient
                    // You should replace this with your actual training algorithm
                    for (int j = 0; j < layer->output_size; ++j) {
                        for (int k = 0; k < layer->input_size; ++k) {
                            layer->weights[k][j] += model->network->learning_rate * (target[j] - output[j]) * input[k];
                        }
                        layer->biases[j] += model->network->learning_rate * (target[j] - output[j]);
                    }

                    // Backpropagation: Compute error gradient for the next layer
                    // You should replace this with your actual backpropagation logic
                    float *new_output = fscl_jellyfish_predict(model, input);
                    for (int j = 0; j < layer->input_size; ++j) {
                        input[j] = 0.0f;
                        for (int k = 0; k < layer->output_size; ++k) {
                            input[j] += new_output[k] * layer->weights[j][k];
                        }
                        input[j] += layer->biases[j];
                    }
                    free(new_output);
                }
            }
        }
    }
}

// Function to make predictions using the jellyfish neural network
float *fscl_jellyfish_predict(jellyfish_model *model, float *input) {
    float *output = input;

    for (int layer_idx = 0; layer_idx < model->network->num_layers; ++layer_idx) {
        jellyfish_layer *layer = model->network->layers[layer_idx];
        float *new_output = (float *)malloc(sizeof(float) * layer->output_size);

        for (int i = 0; i < layer->output_size; ++i) {
            new_output[i] = 0.0f;
            for (int j = 0; j < layer->input_size; ++j) {
                new_output[i] += output[j] * layer->weights[j][i];
            }
            new_output[i] += layer->biases[i];

            // Apply activation function (simplified, you might want to use a separate function)
            switch (layer->activation_function) {
                case Sigmoid:
                    new_output[i] = 1.0 / (1.0 + exp(-new_output[i]));
                    break;
                case Tanh:
                    new_output[i] = tanh(new_output[i]);
                    break;
                case ReLU:
                    new_output[i] = (new_output[i] > 0.0) ? new_output[i] : 0.0;
                    break;
                // Add more activation functions as needed
            }
        }

        free(output);
        output = new_output;
    }

    return output;
}

// Function to save the jellyfish model to a file
void fscl_jellyfish_save_model(jellyfish_model *model) {
    FILE *file = fopen(model->model_name, "wb");
    if (file != NULL) {
        // Save model metadata (simplified for illustration)
        fwrite(&model->network->num_layers, sizeof(int), 1, file);
        fwrite(&model->network->loss_function, sizeof(LossFunction), 1, file);
        fwrite(&model->network->optimizer, sizeof(OptimizationAlgorithm), 1, file);
        fwrite(&model->network->learning_rate, sizeof(float), 1, file);

        // Save each layer
        for (int i = 0; i < model->network->num_layers; ++i) {
            jellyfish_layer *layer = model->network->layers[i];
            fwrite(&layer->input_size, sizeof(int), 1, file);
            fwrite(&layer->output_size, sizeof(int), 1, file);
            fwrite(layer->weights[0], sizeof(float), layer->input_size * layer->output_size, file);
            fwrite(layer->biases, sizeof(float), layer->output_size, file);
            fwrite(&layer->activation_function, sizeof(ActivationFunction), 1, file);
        }

        fclose(file);
    }
}

// Function to load the jellyfish model from a file
jellyfish_model *fscl_jellyfish_load_model(const char *model_name) {
    FILE *file = fopen(model_name, "rb");
    if (file != NULL) {
        jellyfish_model *model = (jellyfish_model *)malloc(sizeof(jellyfish_model));

        // Load model metadata (simplified for illustration)
        model->network = fscl_jellyfish_create_network(0, 0);

        // Use the return values of fread and handle any errors
        if (fread(&model->network->num_layers, sizeof(int), 1, file) != 1) {
            // Handle fread error
            fclose(file);
            free(model->network);  // Free allocated memory before returning
            free(model);
            return NULL;
        }

        if (fread(&model->network->loss_function, sizeof(LossFunction), 1, file) != 1
            || fread(&model->network->optimizer, sizeof(OptimizationAlgorithm), 1, file) != 1
            || fread(&model->network->learning_rate, sizeof(float), 1, file) != 1) {
            // Handle fread error
            fclose(file);
            free(model->network);  // Free allocated memory before returning
            free(model);
            return NULL;
        }

        // Load each layer
        model->network->layers = (jellyfish_layer **)malloc(sizeof(jellyfish_layer *) * model->network->num_layers);
        for (int i = 0; i < model->network->num_layers; ++i) {
            jellyfish_layer *layer = (jellyfish_layer *)malloc(sizeof(jellyfish_layer));

            // Use the return values of fread and handle any errors
            if (fread(&layer->input_size, sizeof(int), 1, file) != 1
                || fread(&layer->output_size, sizeof(int), 1, file) != 1
                || fread(layer->weights[0], sizeof(float), layer->input_size * layer->output_size, file) != 1
                || fread(layer->biases, sizeof(float), layer->output_size, file) != 1
                || fread(&layer->activation_function, sizeof(ActivationFunction), 1, file) != 1) {
                // Handle fread error
                fclose(file);
                fscl_jellyfish_free_model(model);  // Helper function to free allocated memory
                return NULL;
            }

            model->network->layers[i] = layer;
        }

        fclose(file);
        model->model_name = fscl_jellyfish_strdup(model_name);

        return model;
    }

    return NULL;
}

// Function to set the activation function for a layer
void fscl_jellyfish_set_activation(jellyfish_layer *layer, ActivationFunction activation_function) {
    layer->activation_function = activation_function;
}

// Function to get the activation function of a layer
ActivationFunction fscl_jellyfish_get_activation(const jellyfish_layer *layer) {
    return layer->activation_function;
}

// Function to set the loss function for the entire network
void fscl_jellyfish_set_loss(jellyfish_network *network, LossFunction loss_function) {
    network->loss_function = loss_function;
}

// Function to get the loss function of the entire network
LossFunction fscl_jellyfish_get_loss(const jellyfish_network *network) {
    return network->loss_function;
}

// Function to set the optimization algorithm for the entire network
void fscl_jellyfish_set_optimizer(jellyfish_network *network, OptimizationAlgorithm optimizer) {
    network->optimizer = optimizer;
}

// Function to get the optimization algorithm of the entire network
OptimizationAlgorithm fscl_jellyfish_get_optimizer(const jellyfish_network *network) {
    return network->optimizer;
}

// Function to get the input size of a layer
int fscl_jellyfish_get_layer_input_size(const jellyfish_layer *layer) {
    return layer->input_size;
}

// Function to get the output size of a layer
int fscl_jellyfish_get_layer_output_size(const jellyfish_layer *layer) {
    return layer->output_size;
}

// Function to get the input size of the model
int fscl_jellyfish_get_model_input_size(const jellyfish_model *model) {
    return model->network->layers[0]->input_size;
}

// Function to get the output size of the model
int fscl_jellyfish_get_model_output_size(const jellyfish_model *model) {
    return model->network->layers[model->network->num_layers - 1]->output_size;
}

// Function to free the memory allocated for prediction output
void fscl_jellyfish_erase_prediction(float *output) {
    free(output);
}

// Function to erase the jellyfish neural network
void fscl_jellyfish_erase_layer(jellyfish_layer *layer) {
    // Memory cleanup for a layer
    for (int i = 0; i < layer->input_size; ++i) {
        free(layer->weights[i]);
    }
    free(layer->weights);
    free(layer->biases);
    free(layer);
}

// Function to erase the jellyfish model
void fscl_jellyfish_erase_model(jellyfish_model *model) {
    // Memory cleanup for the model
    for (int i = 0; i < model->network->num_layers; ++i) {
        fscl_jellyfish_erase_layer(model->network->layers[i]);
    }
    free(model->network->layers);
    free(model->model_name);
    free(model->network);
}
