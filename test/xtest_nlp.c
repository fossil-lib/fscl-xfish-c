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

XTEST_CASE(testNLPProcessingEnglishPositiveTone) {
    // Arrange
    JellyfishNLP *nlp = fscl_jellyfish_nlp_create("english_model", "english");
    const char *language = "english";
    const char *tone = "positive";
    float input[] = {0.1, 0.2, 0.3, 0.4, 0.5}; // Sample input data for English
    float *result;

    // Act
    result = fscl_jellyfish_nlp_process(nlp, input, language, tone);

    // Assert
    TEST_ASSERT_NOT_CNULLPTR(result);

    // Clean up
    fscl_jellyfish_nlp_erase(nlp);
    free(result);
}

XTEST_CASE(testNLPProcessingSpanishNegativeTone) {
    // Arrange
    JellyfishNLP *nlp = fscl_jellyfish_nlp_create("spanish_model", "spanish");
    const char *language = "spanish";
    const char *tone = "negative";
    float input[] = {0.5, 0.4, 0.3, 0.2, 0.1}; // Sample input data for Spanish
    float *result;

    // Act
    result = fscl_jellyfish_nlp_process(nlp, input, language, tone);

    // Assert
    TEST_ASSERT_NOT_CNULLPTR(result);

    // Clean up
    fscl_jellyfish_nlp_erase(nlp);
    free(result);
}

XTEST_CASE(testNLPProcessingItalianDefaultTone) {
    // Arrange
    JellyfishNLP *nlp = fscl_jellyfish_nlp_create("italian_model", "italian");
    const char *language = "italian";
    const char *tone = "unknown_tone"; // Default case
    float input[] = {0.3, 0.6, 0.1, 0.9, 0.2}; // Sample input data for Italian
    float *result;

    // Act
    result = fscl_jellyfish_nlp_process(nlp, input, language, tone);

    // Assert
    TEST_ASSERT_NOT_CNULLPTR(result);

    // Clean up
    fscl_jellyfish_nlp_erase(nlp);
    free(result);
}

XTEST_CASE(testNLPProcessingRussianPositiveTone) {
    // Arrange
    JellyfishNLP *nlp = fscl_jellyfish_nlp_create("russian_model", "russian");
    const char *language = "russian";
    const char *tone = "positive";
    float input[] = {0.1, 0.2, 0.3, 0.4, 0.5}; // Sample input data for Russian
    float *result;

    // Act
    result = fscl_jellyfish_nlp_process(nlp, input, language, tone);

    // Assert
    TEST_ASSERT_NOT_CNULLPTR(result);

    // Clean up
    fscl_jellyfish_nlp_erase(nlp);
    free(result);
}

XTEST_CASE(testNLPProcessingCanadianNegativeTone) {
    // Arrange
    JellyfishNLP *nlp = fscl_jellyfish_nlp_create("canadian_model", "canadian");
    const char *language = "canadian";
    const char *tone = "negative";
    float input[] = {0.5, 0.4, 0.3, 0.2, 0.1}; // Sample input data for Canadian
    float *result;

    // Act
    result = fscl_jellyfish_nlp_process(nlp, input, language, tone);

    // Assert
    TEST_ASSERT_NOT_CNULLPTR(result);

    // Clean up
    fscl_jellyfish_nlp_erase(nlp);
    free(result);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(nlp_group) {
    XTEST_RUN_UNIT(testNLPProcessingEnglishPositiveTone);
    XTEST_RUN_UNIT(testNLPProcessingSpanishNegativeTone);
    XTEST_RUN_UNIT(testNLPProcessingItalianDefaultTone);
    XTEST_RUN_UNIT(testNLPProcessingRussianPositiveTone);
    XTEST_RUN_UNIT(testNLPProcessingCanadianNegativeTone);
} // end of fixture
