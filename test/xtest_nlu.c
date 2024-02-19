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

#include <fossil/xfish/nlu.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

XTEST_CASE(test_activation_functions) {
    // Test activation functions
    jellyfish_layer layer;
    
    fscl_jellyfish_set_activation(&layer, Sigmoid);
    TEST_ASSERT_EQUAL(Sigmoid, fscl_jellyfish_get_activation(&layer));
    
    fscl_jellyfish_set_activation(&layer, Tanh);
    TEST_ASSERT_EQUAL(Tanh, fscl_jellyfish_get_activation(&layer));
    
    fscl_jellyfish_set_activation(&layer, ReLU);
    TEST_ASSERT_EQUAL(ReLU, fscl_jellyfish_get_activation(&layer));
}

XTEST_CASE(test_loss_function) {
    // Test loss function
    jellyfish_network network;
    
    fscl_jellyfish_set_loss(&network, MeanSquaredError);
    TEST_ASSERT_EQUAL(MeanSquaredError, fscl_jellyfish_get_loss(&network));
    
    fscl_jellyfish_set_loss(&network, CrossEntropy);
    TEST_ASSERT_EQUAL(CrossEntropy, fscl_jellyfish_get_loss(&network));
}

XTEST_CASE(test_optimizer) {
    // Test optimization algorithm
    jellyfish_network network;
    
    fscl_jellyfish_set_optimizer(&network, SGD);
    TEST_ASSERT_EQUAL(SGD, fscl_jellyfish_get_optimizer(&network));
    
    fscl_jellyfish_set_optimizer(&network, Adam);
    TEST_ASSERT_EQUAL(Adam, fscl_jellyfish_get_optimizer(&network));
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(nlu_group) {
    XTEST_RUN_UNIT(test_activation_functions);
    XTEST_RUN_UNIT(test_loss_function);
    XTEST_RUN_UNIT(test_optimizer);
} // end of fixture
