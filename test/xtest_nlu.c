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

XTEST_CASE(test_nlu_initialize_and_free) {
    JellyfishNLU *nlu = fscl_jellyfish_nlu_create(10, 5, "test_model");
    TEST_ASSERT_NOT_CNULLPTR(nlu);
    fscl_jellyfish_nlu_erase(nlu);
}

XTEST_CASE(test_nlu_process_input) {
    JellyfishNLU *nlu = fscl_jellyfish_nlu_create(10, 5, "test_model");
    TEST_ASSERT_NOT_CNULLPTR(nlu);

    const char *input_text = "sample input";
    float *processed_input = fscl_jellyfish_nlu_process_input(nlu, input_text);

    // Add assertions based on the expected processed input data
    TEST_ASSERT_NOT_CNULLPTR(processed_input);

    // Free the allocated memory for processed input data
    free(processed_input);
    fscl_jellyfish_nlu_erase(nlu);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(nlu_group) {
    XTEST_RUN_UNIT(test_nlu_initialize_and_free);
    XTEST_RUN_UNIT(test_nlu_process_input);
} // end of fixture
