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
#ifndef FSCL_JELLYFISH_H
#define FSCL_JELLYFISH_H

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum {
    Sigmoid,
    Tanh,
    ReLU
    // Add more activation functions as needed
} ActivationFunction;

typedef enum {
    MeanSquaredError,
    CrossEntropy
    // Add more loss functions as needed
} LossFunction;

typedef enum {
    SGD,
    Adam
    // Add more optimization algorithms as needed
} OptimizationAlgorithm;

typedef struct {
    int input_size;
    int output_size;
    float **weights;
    float *biases;
    ActivationFunction activation_function;
} jellyfish_layer;

typedef struct {
    int num_layers;
    jellyfish_layer **layers;
    LossFunction loss_function;
    OptimizationAlgorithm optimizer;
    float learning_rate;
} jellyfish_network;

typedef struct {
    jellyfish_network *network;
    char *model_name;
} jellyfish_model;

// ========================================================================
// create and erase functions
// ========================================================================

// Function to initialize a jellyfish neural network
jellyfish_network *fscl_jellyfish_create_network(int input_size, int output_size);

// Function to create a jellyfish model
jellyfish_model *fscl_jellyfish_create_model(int input_size, int output_size, const char *model_name);

// Function to free the memory allocated for prediction output
void fscl_jellyfish_erase_prediction(float *output);

// Function to erase the jellyfish neural network
void fscl_jellyfish_erase_model(jellyfish_model *model);

// ========================================================================
// AIP functions
// ========================================================================

// Function to add a layer to the jellyfish neural network
void fscl_jellyfish_add_layer(jellyfish_network *network, int layer_input_size, int layer_output_size, ActivationFunction activation_function);

// Function to configure training hyperparameters
void fscl_jellyfish_configure_training(jellyfish_model *model, LossFunction loss_function, OptimizationAlgorithm optimizer, float learning_rate);

// Function to train the jellyfish neural network
void fscl_jellyfish_train(jellyfish_model *model, float **input_data, float **target_data, int num_samples, int epochs, int batch_size);

// Function to make predictions using the jellyfish neural network
float *fscl_jellyfish_predict(jellyfish_model *model, float *input);

// Function to create a model
jellyfish_model *fscl_jellyfish_create_model(int input_size, int output_size, const char *model_name);

// Function to save the jellyfish model to a file
void fscl_jellyfish_save_model(jellyfish_model *model);

// Function to load the jellyfish model from a file
jellyfish_model *fscl_jellyfish_load_model(const char *model_name);

// ========================================================================
// getter and setter functions
// ========================================================================

// Function to set the activation function for a layer
void fscl_jellyfish_set_activation(jellyfish_layer *layer, ActivationFunction activation_function);

// Function to set the loss function for the entire network
void fscl_jellyfish_set_loss(jellyfish_network *network, LossFunction loss_function);

// Function to set the optimization algorithm for the entire network
void fscl_jellyfish_set_optimizer(jellyfish_network *network, OptimizationAlgorithm optimizer);

// Function to get the loss function of the entire network
LossFunction fscl_jellyfish_get_loss(const jellyfish_network *network);

// Function to get the optimization algorithm of the entire network
OptimizationAlgorithm fscl_jellyfish_get_optimizer(const jellyfish_network *network);

// Function to get the activation function of a layer
ActivationFunction fscl_jellyfish_get_activation(const jellyfish_layer *layer);

// Function to get the input size of a layer
int fscl_jellyfish_get_layer_input_size(const jellyfish_layer *layer);

// Function to get the output size of a layer
int fscl_jellyfish_get_layer_output_size(const jellyfish_layer *layer);

// Function to get the input size of the model
int fscl_jellyfish_get_model_input_size(const jellyfish_model *model);

// Function to get the output size of the model
int fscl_jellyfish_get_model_output_size(const jellyfish_model *model);


#ifdef __cplusplus
}
#endif

#endif
