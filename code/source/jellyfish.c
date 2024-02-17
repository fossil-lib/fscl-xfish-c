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
#include "fossil/xfish/nlp.h"

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double relu(double x) {
    return (x > 0) ? x : 0;
}

// Create a neural model with specified layer architecture
void fscl_jellyfish_create_neural_model(JellyfishNeuralModel *model, int num_inputs, int *num_neurons_per_layer, int num_layers, double (*activation_function)(double)) {
    model->num_layers = num_layers;
    model->layers = (JellyfishNeuralNetwork *)malloc(num_layers * sizeof(JellyfishNeuralNetwork));

    for (int i = 0; i < num_layers; ++i) {
        int num_neurons = num_neurons_per_layer[i];
        int num_prev_neurons = (i == 0) ? num_inputs : num_neurons_per_layer[i - 1];
        fscl_jellyfish_create_neural_network(&(model->layers[i]), num_prev_neurons, num_neurons, activation_function);
    }
}

// Erase memory allocated for the neural model
void fscl_jellyfish_erase_neural_model(JellyfishNeuralModel *model) {
    for (int i = 0; i < model->num_layers; ++i) {
        fscl_jellyfish_erase_neural_network(&(model->layers[i]));
    }
    free(model->layers);
}

// Display a summary of the neural model architecture
void fscl_jellyfish_print_neural_model_summary(const JellyfishNeuralModel *model, int num_inputs) {
    printf("Neural Model Summary:\n");
    for (int i = 0; i < model->num_layers; ++i) {
        int num_neurons = model->layers[i].num_neurons;
        printf("Layer %d:\n", i + 1);
        for (int j = 0; j < num_neurons; ++j) {
            printf("  Neuron %d - Strength: %lf\n", j + 1, model->layers[i].neurons[j].strength);
        }
    }
    printf("Total Parameters: %d\n", num_inputs * model->layers[0].num_neurons + model->layers[0].num_neurons);  // Assuming a fully connected first layer
}

// Create a neuron with random weights and a specified activation function
void fscl_jellyfish_create_neuron(JellyfishNeuron *neuron, int num_inputs, double (*activation_function)(double), double strength) {
    neuron->weights = (double *)malloc(num_inputs * sizeof(double));
    for (int i = 0; i < num_inputs; ++i) {
        neuron->weights[i] = ((double)rand() / RAND_MAX) - 0.5;  // Random weight between -0.5 and 0.5
    }
    neuron->bias = 0.0;
    neuron->activation_function = activation_function;
    neuron->strength = strength;
}

// Erase memory allocated for a neuron
void fscl_jellyfish_erase_neuron(JellyfishNeuron *neuron) {
    free(neuron->weights);
}

// Activation function for a neuron
double fscl_jellyfish_activate(const JellyfishNeuron *neuron, const double *inputs, int num_inputs) {
    double activation = neuron->bias;
    for (int i = 0; i < num_inputs; ++i) {
        activation += inputs[i] * neuron->weights[i];
    }
    return neuron->activation_function(activation);
}

// Create a neural network with random weights and a specified activation function
void fscl_jellyfish_create_neural_network(JellyfishNeuralNetwork *network, int num_inputs, int num_neurons, double (*activation_function)(double)) {
    network->num_neurons = num_neurons;
    network->neurons = (JellyfishNeuron *)malloc(num_neurons * sizeof(JellyfishNeuron));

    for (int i = 0; i < num_neurons; ++i) {
        fscl_jellyfish_create_neuron(&(network->neurons[i]), num_inputs, activation_function);
    }
}

// Erase memory allocated for the neural network
void fscl_jellyfish_erase_neural_network(JellyfishNeuralNetwork *network) {
    for (int i = 0; i < network->num_neurons; ++i) {
        fscl_jellyfish_erase_neuron(&(network->neurons[i]));
    }
    free(network->neurons);
}

// Forward pass through the network
void fscl_jellyfish_predict(const JellyfishNeuralNetwork *network, const double *inputs, double *outputs) {
    for (int i = 0; i < network->num_neurons; ++i) {
        outputs[i] = fscl_jellyfish_activate(&(network->neurons[i]), inputs, i);
    }
}

// Print the weights and bias of a neuron
void fscl_jellyfish_print_neuron(const JellyfishNeuron *neuron, int num_inputs) {
    printf("Neuron Weights: ");
    for (int i = 0; i < num_inputs; ++i) {
        printf("%lf ", neuron->weights[i]);
    }
    printf("\nNeuron Bias: %lf\n", neuron->bias);
}

// Print the neural network architecture
void fscl_jellyfish_print_neural_network(const JellyfishNeuralNetwork *network, int num_inputs) {
    printf("Neural Network Architecture:\n");
    for (int i = 0; i < network->num_neurons; ++i) {
        printf("Layer %d: ", i + 1);
        fscl_jellyfish_print_neuron(&(network->neurons[i]), num_inputs);
    }
}
