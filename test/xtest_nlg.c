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

#include <fossil/xfish/nlg.h> // library under test

// Define network architecture parameters
enum {
    NLG_TEST_INPUT_SIZE = 10,
    NLG_TEST_OUTPUT_SIZE = 20
};

//
// XUNIT-CASES: list of test cases testing project features
//

// Test case for NLG library initialization
XTEST_CASE(test_nlg_initialization) {
    // Initialize NLG model
    JellyfishNLG *nlg = fscl_jellyfish_nlg_create("your_model_name", NLG_TEST_INPUT_SIZE, NLG_TEST_OUTPUT_SIZE);

    // Check if NLG model is not NULL (indicating successful initialization)
    TEST_ASSERT_NOT_CNULLPTR(nlg);

    // Destroy NLG model
    fscl_jellyfish_nlg_erase(nlg);
}

// Test case for text generation
XTEST_CASE(test_text_generation) {
    // Initialize NLG model
    JellyfishNLG *nlg = fscl_jellyfish_nlg_create("your_model_name", NLG_TEST_INPUT_SIZE, NLG_TEST_OUTPUT_SIZE);
    TEST_ASSERT_NOT_CNULLPTR(nlg);

    // Example input data (customize based on your input requirements)
    float input_data[NLG_TEST_INPUT_SIZE] = {0.1, 0.2, 0.3, 0.4};

    // Generate text
    char *text = fscl_jellyfish_nlg_generate_text(nlg, input_data);

    // Check if generated text is not NULL
    TEST_ASSERT_NOT_CNULLPTR(text);

    // Print generated text (optional)
    printf("Generated text: %s\n", text);

    // Clean up
    free(text);
    fscl_jellyfish_nlg_erase(nlg);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(nlg_group) {
    XTEST_RUN_UNIT(test_nlg_initialization);
    XTEST_RUN_UNIT(test_text_generation);
} // end of fixture
