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

//
// XUNIT-CASES: list of test cases testing project features
//

// Function to test is_punctuation
XTEST_CASE(test_nlg_create_and_erase_model) {
    // Call the function to create an NLG model
    NLGModel *nlg_model = fscl_jellyfish_nlg_create_model();

    // Perform assertions using Unity's macros
    TEST_ASSERT_NOT_CNULLPTR(nlg_model);
    // Add more assertions based on your expectations

    // Call the function to erase the NLG model
    fscl_jellyfish_nlg_erase_model(nlg_model);

    // The model should be NULL after erasing
    TEST_ASSERT_CNULLPTR(nlg_model);
}

XTEST_CASE(test_nlg_generate) {
    // Call the function to create an NLG model
    NLGModel *nlg_model = fscl_jellyfish_nlg_create_model();

    // Input code for documentation generation
    const char *input_code = "int main() {\n  // Your code here\n  return 0;\n}";

    // Call the function to generate source code documentation for C language
    char *documentation_c = fscl_jellyfish_nlg_generate(nlg_model, SourceCodeDocumentation, C, input_code);

    // Perform assertions using Unity's macros
    TEST_ASSERT_NOT_CNULLPTR(documentation_c);
    // Add more assertions based on your expectations

    // Clean up allocated memory
    free(documentation_c);

    // Call the function to erase the NLG model
    fscl_jellyfish_nlg_erase_model(nlg_model);
}

XTEST_CASE(test_nlg_generate_python) {
    // Call the function to create an NLG model
    NLGModel *nlg_model = fscl_jellyfish_nlg_create_model();

    // Input code for documentation generation in Python
    const char *input_code_python = "def my_function():\n    # Your code here\n    return 42";

    // Call the function to generate source code documentation for Python language
    char *documentation_python = fscl_jellyfish_nlg_generate(nlg_model, SourceCodeDocumentation, Python, input_code_python);

    // Perform assertions using Unity's macros
    TEST_ASSERT_NOT_CNULLPTR(documentation_python);
    // Add more assertions based on your expectations for Python documentation

    // Clean up allocated memory
    free(documentation_python);

    // Call the function to erase the NLG model
    fscl_jellyfish_nlg_erase_model(nlg_model);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(nlg_group) {
    XTEST_RUN_UNIT(test_nlg_create_and_erase_model);
    XTEST_RUN_UNIT(test_nlg_generate);
    XTEST_RUN_UNIT(test_nlg_generate_python);
} // end of fixture
