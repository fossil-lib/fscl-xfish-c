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

// Function to create a neural model with specified layer architecture
void fscl_jellyfish_create_neural_model(JellyfishNeuralModel *model, int num_inputs, int *num_neurons_per_layer, int num_layers, double (*activation_function)(double)) {
    model->num_layers = num_layers;
    model->layers = (JellyfishNeuralNetwork *)malloc(num_layers * sizeof(JellyfishNeuralNetwork));

    for (int i = 0; i < num_layers; ++i) {
        model->layers[i].num_neurons = num_neurons_per_layer[i];
        model->layers[i].neurons = (JellyfishNeuron *)malloc(num_neurons_per_layer[i] * sizeof(JellyfishNeuron));

        for (int j = 0; j < num_neurons_per_layer[i]; ++j) {
            fscl_jellyfish_create_neuron(&(model->layers[i].neurons[j]), (i == 0) ? num_inputs : num_neurons_per_layer[i - 1], activation_function, rand() % 10 + 1);
        }
    }
}

// Function to erase memory allocated for the neural model
void fscl_jellyfish_erase_neural_model(JellyfishNeuralModel *model) {
    for (int i = 0; i < model->num_layers; ++i) {
        for (int j = 0; j < model->layers[i].num_neurons; ++j) {
            fscl_jellyfish_erase_neuron(&(model->layers[i].neurons[j]));
        }
        free(model->layers[i].neurons);
    }
    free(model->layers);
}

// Function to display a summary of the neural model architecture
void fscl_jellyfish_print_neural_model_summary(const JellyfishNeuralModel *model, int num_inputs) {
    printf("Neural Model Summary:\n");
    for (int i = 0; i < model->num_layers; ++i) {
        printf("Layer %d: %d neurons\n", i + 1, model->layers[i].num_neurons);
        for (int j = 0; j < model->layers[i].num_neurons; ++j) {
            fscl_jellyfish_print_neuron(&(model->layers[i].neurons[j]), (i == 0) ? num_inputs : model->layers[i - 1].num_neurons);
        }
    }
}

// Function to create a neuron with random weights and a specified activation function
void fscl_jellyfish_create_neuron(JellyfishNeuron *neuron, int num_inputs, double (*activation_function)(double), double strength) {
    neuron->weights = (double *)malloc(num_inputs * sizeof(double));
    for (int i = 0; i < num_inputs; ++i) {
        neuron->weights[i] = (rand() % 100) / 100.0; // Random weights between 0 and 1
    }
    neuron->bias = (rand() % 100) / 100.0; // Random bias between 0 and 1
    neuron->activation_function = activation_function;
    neuron->strength = strength;
}

// Function to erase memory allocated for a neuron
void fscl_jellyfish_erase_neuron(JellyfishNeuron *neuron) {
    free(neuron->weights);
}

// Function for the activation of a neuron
double fscl_jellyfish_activate(const JellyfishNeuron *neuron, const double *inputs, int num_inputs) {
    double sum = neuron->bias;
    for (int i = 0; i < num_inputs; ++i) {
        sum += inputs[i] * neuron->weights[i];
    }
    return neuron->activation_function(sum * neuron->strength);
}

// Function to create a neural network with random weights and a specified activation function
void fscl_jellyfish_create_neural_network(JellyfishNeuralNetwork *network, int num_inputs, int num_neurons, double (*activation_function)(double)) {
    network->num_neurons = num_neurons;
    network->neurons = (JellyfishNeuron *)malloc(num_neurons * sizeof(JellyfishNeuron));

    for (int i = 0; i < num_neurons; ++i) {
        fscl_jellyfish_create_neuron(&(network->neurons[i]), (i == 0) ? num_inputs : num_neurons, activation_function, rand() % 10 + 1);
    }
}

// Function to erase memory allocated for the neural network
void fscl_jellyfish_erase_neural_network(JellyfishNeuralNetwork *network) {
    for (int i = 0; i < network->num_neurons; ++i) {
        fscl_jellyfish_erase_neuron(&(network->neurons[i]));
    }
    free(network->neurons);
}

// Function for the forward pass through the network
void fscl_jellyfish_predict(const JellyfishNeuralNetwork *network, const double *inputs, double *outputs) {
    for (int i = 0; i < network->num_neurons; ++i) {
        outputs[i] = fscl_jellyfish_activate(&(network->neurons[i]), inputs, (i == 0) ? 1 : network->neurons[i - 1].strength);
    }
}

// Function to print the weights and bias of a neuron
void fscl_jellyfish_print_neuron(const JellyfishNeuron *neuron, int num_inputs) {
    printf("Neuron with %d inputs:\n", num_inputs);
    printf("Weights: ");
    for (int i = 0; i < num_inputs; ++i) {
        printf("%.3f ", neuron->weights[i]);
    }
    printf("\nBias: %.3f\n", neuron->bias);
    printf("Strength: %.3f\n", neuron->strength);
}

// Function to print the neural network architecture
void fscl_jellyfish_print_neural_network(const JellyfishNeuralNetwork *network, int num_inputs) {
    printf("Neural Network:\n");
    for (int i = 0; i < network->num_neurons; ++i) {
        fscl_jellyfish_print_neuron(&(network->neurons[i]), (i == 0) ? num_inputs : network->neurons[i - 1].strength);
    }
}
