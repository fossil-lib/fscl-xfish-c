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
#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

#include <fossil/xfish/jellyfish.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

// Test case for creating a neuron
XFISH_CASE(test_create_neuron) {
    JellyfishNeuron neuron;
    fscl_jellyfish_create_neuron(&neuron, 3, sigmoid, 1.0);

    // Add assertions to check the expected behavior
    TEST_ASSERT_NOT_NULL(neuron.weights);
    TEST_ASSERT_EQUAL_FLOAT(0.0, neuron.bias);
    TEST_ASSERT_EQUAL_FLOAT(1.0, neuron.strength);

    fscl_jellyfish_erase_neuron(&neuron);  // Clean up after the test
}

// Test case for predicting with a neural network
XFISH_CASE(test_predict) {
    JellyfishNeuralNetwork network;
    fscl_jellyfish_create_neural_network(&network, 2, 3, sigmoid);

    double inputs[] = {0.5, 0.8};
    double outputs[3];

    fscl_jellyfish_predict(&network, inputs, outputs);

    // Add assertions to check the expected behavior
    // For simplicity, you might want to compare with known output values

    fscl_jellyfish_erase_neural_network(&network);  // Clean up after the test
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(jellyfish_group) {
    XTEST_RUN_UNIT(test_create_neuron);
    XTEST_RUN_UNIT(test_predict);
} // end of fixture