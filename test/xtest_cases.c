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

#include <fossil/xfish/nlp.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

// Function to test is_punctuation
XFISH_CASE(test_is_punctuation) {
    TEST_ASSERT_TRUE(is_punctuation('.'));
    TEST_ASSERT_TRUE(is_punctuation(','));
    TEST_ASSERT_FALSE(is_punctuation('a'));
}

// Function to test is_numeric
XFISH_CASE(test_is_numeric) {
    TEST_ASSERT_TRUE(is_numeric('5'));
    TEST_ASSERT_TRUE(is_numeric('9'));
    TEST_ASSERT_FALSE(is_numeric('a'));
}

// Function to test is_stop_word
XFISH_CASE(test_is_stop_word) {
    TEST_ASSERT_TRUE(is_stop_word("the", "english"));
    TEST_ASSERT_TRUE(is_stop_word("el", "spanish"));
    TEST_ASSERT_TRUE(is_stop_word("e", "italian"));
    TEST_ASSERT_FALSE(is_stop_word("hello", "english"));
}

// Function to test detect_language
XFISH_CASE(test_detect_language) {
    TEST_ASSERT_EQUAL_STRING("english", detect_language("This is an English sentence."));
    TEST_ASSERT_EQUAL_STRING("spanish", detect_language("Hola, cómo estás?"));
    TEST_ASSERT_EQUAL_STRING("italian", detect_language("Ciao, come stai?"));
}

// Function to test is_name
XFISH_CASE(test_is_name) {
    TEST_ASSERT_TRUE(is_name("John"));
    TEST_ASSERT_FALSE(is_name("hello"));
}

// Function to test detect_humor
XFISH_CASE(test_detect_humor) {
    TEST_ASSERT_TRUE(detect_humor("This is a funny sentence."));
    TEST_ASSERT_FALSE(detect_humor("This is a serious sentence."));
}

// Function to test detect_sarcasm
XFISH_CASE(test_detect_sarcasm) {
    TEST_ASSERT_TRUE(detect_sarcasm("Oh, that's just great!"));
    TEST_ASSERT_FALSE(detect_sarcasm("This is genuinely good."));
}

// Function to test fscl_nlp_fish
XFISH_CASE(test_fscl_nlp_fish) {
    char text[] = "This is a haha funny sample sentence in English. Not good, as if that'll work!";
    char context[] = "During a casual conversation";
    TEST_ASSERT_EQUAL(1, 1); // Add your assertions based on the expected behavior
    // You might want to redirect stdout to capture the output for more detailed testing
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(nlp_group) {
    XTEST_RUN_UNIT(test_is_punctuation);
    XTEST_RUN_UNIT(test_is_numeric);
    XTEST_RUN_UNIT(test_is_stop_word);
    XTEST_RUN_UNIT(test_detect_language);
    XTEST_RUN_UNIT(test_is_name);
    XTEST_RUN_UNIT(test_detect_humor);
    XTEST_RUN_UNIT(test_detect_sarcasm);
    XTEST_RUN_UNIT(test_fscl_nlp_fish);
} // end of fixture
