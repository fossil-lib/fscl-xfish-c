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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *weights;
    double bias;
    double (*activation_function)(double);
    double strength;  // New attribute to represent neuron strength
} JellyfishNeuron;

typedef struct {
    JellyfishNeuron *neurons;
    int num_neurons;
} JellyfishNeuralNetwork;

typedef struct {
    JellyfishNeuralNetwork *layers;
    int num_layers;
} JellyfishNeuralModel;

// Create a neural model with specified layer architecture
void fscl_jellyfish_create_neural_model(JellyfishNeuralModel *model, int num_inputs, int *num_neurons_per_layer, int num_layers, double (*activation_function)(double));

// Erase memory allocated for the neural model
void fscl_jellyfish_erase_neural_model(JellyfishNeuralModel *model);

// Display a summary of the neural model architecture
void fscl_jellyfish_print_neural_model_summary(const JellyfishNeuralModel *model, int num_inputs);

// Create a neuron with random weights and a specified activation function
void fscl_jellyfish_create_neuron(JellyfishNeuron *neuron, int num_inputs, double (*activation_function)(double), double strength);

// Erase memory allocated for a neuron
void fscl_jellyfish_erase_neuron(JellyfishNeuron *neuron);

// Activation function for a neuron
double fscl_jellyfish_activate(const JellyfishNeuron *neuron, const double *inputs, int num_inputs);

// Create a neural network with random weights and a specified activation function
void fscl_jellyfish_create_neural_network(JellyfishNeuralNetwork *network, int num_inputs, int num_neurons, double (*activation_function)(double));

// Erase memory allocated for the neural network
void fscl_jellyfish_erase_neural_network(JellyfishNeuralNetwork *network);

// Forward pass through the network
void fscl_jellyfish_predict(const JellyfishNeuralNetwork *network, const double *inputs, double *outputs);

// Print the weights and bias of a neuron
void fscl_jellyfish_print_neuron(const JellyfishNeuron *neuron, int num_inputs);

// Print the neural network architecture
void fscl_jellyfish_print_neural_network(const JellyfishNeuralNetwork *network, int num_inputs);

#ifdef __cplusplus
}
#endif

#endif