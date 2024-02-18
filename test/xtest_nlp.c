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
XTEST_CASE(test_tokenize) {
    NlpModel *nlp_model = fscl_jellyfish_nlp_create_model();
    char *text = "This is a sample sentence.";

    char **tokens = fscl_jellyfish_nlp_tokenize(text, nlp_model);

    TEST_ASSERT_NOT_CNULLPTR(tokens);
    TEST_ASSERT_EQUAL_CSTRING("This", tokens[0]);
    TEST_ASSERT_EQUAL_CSTRING("is", tokens[1]);
    TEST_ASSERT_EQUAL_CSTRING("a", tokens[2]);
    TEST_ASSERT_EQUAL_CSTRING("sample", tokens[3]);
    TEST_ASSERT_EQUAL_CSTRING("sentence", tokens[4]);
    TEST_ASSERT_CNULLPTR(tokens[5]);

    fscl_jellyfish_nlp_erase_model(nlp_model);
    fscl_jellyfish_nlp_erase_tokens(tokens);
}

XTEST_CASE(test_pos_tagging) {
    NlpModel *nlp_model = fscl_jellyfish_nlp_create_model();
    char *text = "The quick brown fox jumps over the lazy dog.";

    PartOfSpeech *pos_tags = fscl_jellyfish_nlp_pos_tag(text, nlp_model);

    TEST_ASSERT_NOT_CNULLPTR(pos_tags);
    TEST_ASSERT_EQUAL_INT(Noun, pos_tags[0]);
    TEST_ASSERT_EQUAL_INT(Adjective, pos_tags[2]);
    TEST_ASSERT_EQUAL_INT(Adjective, pos_tags[4]);
    TEST_ASSERT_EQUAL_INT(Noun, pos_tags[6]);
    TEST_ASSERT_EQUAL_INT(Verb, pos_tags[8]);
    TEST_ASSERT_EQUAL_INT(Preposition, pos_tags[10]);
    TEST_ASSERT_EQUAL_INT(Noun, pos_tags[12]);
    TEST_ASSERT_EQUAL_INT(Adjective, pos_tags[16]);
    TEST_ASSERT_EQUAL_INT(Adjective, pos_tags[18]);
    TEST_ASSERT_EQUAL_INT(Noun, pos_tags[20]);
    TEST_ASSERT_CNULLPTR(pos_tags[22]);

    fscl_jellyfish_nlp_erase_model(nlp_model);
    free(pos_tags);
}

XTEST_CASE(test_sentiment_analysis) {
    NlpModel *nlp_model = fscl_jellyfish_nlp_create_model();
    char *positive_text = "I love this product! It's amazing.";
    char *negative_text = "This is the worst experience ever.";

    Sentiment positive_sentiment = fscl_jellyfish_nlp_sentiment_analysis(positive_text, nlp_model);
    Sentiment negative_sentiment = fscl_jellyfish_nlp_sentiment_analysis(negative_text, nlp_model);

    TEST_ASSERT_EQUAL_INT(Positive, positive_sentiment);
    TEST_ASSERT_EQUAL_INT(Negative, negative_sentiment);

    fscl_jellyfish_nlp_erase_model(nlp_model);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(nlp_group) {
    XTEST_RUN_UNIT(test_tokenize);
    XTEST_RUN_UNIT(test_pos_tagging);
    XTEST_RUN_UNIT(test_sentiment_analysis);
} // end of fixture
