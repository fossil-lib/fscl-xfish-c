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

#include <fossil/xfish/ner.h> // library under test

// Set your input and output sizes for testing
#define TEST_INPUT_SIZE 10
#define TEST_OUTPUT_SIZE 5

//
// XUNIT-CASES: list of test cases testing project features
//

XTEST_CASE(test_prediction_not_null) {
    jellyfish_model *ner_model = fscl_ner_create_model(TEST_INPUT_SIZE, TEST_OUTPUT_SIZE, "test_model");
    float test_input[TEST_INPUT_SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0}; // Set your test input values
    float *prediction = fscl_ner_predict(ner_model, test_input);
    TEST_ASSERT_NOT_CNULLPTR(prediction);
    // Additional assertions or checks can be added based on your specific requirements
    free(prediction);
    fscl_jellyfish_erase_model(ner_model);
}

XTEST_CASE(test_set_get_activation_function) {
    jellyfish_model *ner_model = fscl_ner_create_model(TEST_INPUT_SIZE, TEST_OUTPUT_SIZE, "test_model");
    fscl_jellyfish_add_layer(ner_model->network, 10, TEST_OUTPUT_SIZE, Sigmoid); // Adjust layer parameters based on your model
    jellyfish_layer *added_layer = ner_model->network->layers[1]; // Adjust index based on your layer structure
    fscl_jellyfish_set_activation(added_layer, Tanh);
    ActivationFunction retrieved_activation = fscl_jellyfish_get_activation(added_layer);
    TEST_ASSERT_EQUAL_INT(Tanh, retrieved_activation);
    fscl_jellyfish_erase_model(ner_model);
}

XTEST_CASE(test_set_get_loss_and_optimizer) {
    jellyfish_model *ner_model = fscl_ner_create_model(TEST_INPUT_SIZE, TEST_OUTPUT_SIZE, "test_model");
    fscl_jellyfish_set_loss(ner_model->network, CrossEntropy);
    LossFunction retrieved_loss = fscl_jellyfish_get_loss(ner_model->network);
    TEST_ASSERT_EQUAL_INT(CrossEntropy, retrieved_loss);

    fscl_jellyfish_set_optimizer(ner_model->network, Adam);
    OptimizationAlgorithm retrieved_optimizer = fscl_jellyfish_get_optimizer(ner_model->network);
    TEST_ASSERT_EQUAL_INT(Adam, retrieved_optimizer);

    fscl_jellyfish_erase_model(ner_model);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(ner_group) {
    XTEST_RUN_UNIT(test_prediction_not_null);
    XTEST_RUN_UNIT(test_set_get_activation_function);
    XTEST_RUN_UNIT(test_set_get_loss_and_optimizer);
} // end of fixture