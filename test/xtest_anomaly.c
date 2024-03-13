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

#include <fossil/xfish/anomaly.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

XTEST_CASE(test_anomaly_detection_basic) {
    // Create a model with input size 2 and output size 1
    jellyfish_model *model = fscl_anomaly_create_model(2, 1, "test_model");

    // Train the model with some sample data (for simplicity, using dummy data)
    float **input_data = (float **)malloc(sizeof(float *) * 3); // 3 samples
    for (int i = 0; i < 3; ++i) {
        input_data[i] = (float *)malloc(sizeof(float) * 2); // Input size is 2
        input_data[i][0] = i; // Dummy input data
        input_data[i][1] = i + 1; // Dummy input data
    }
    fscl_anomaly_train(model, input_data, 3, 10, 1); // Training for 10 epochs

    // Test anomaly detection with an input that is expected to be normal
    float input_normal[2] = {1.5, 2.5}; // Dummy normal input for testing
    float anomaly_score_normal = fscl_anomaly_detect(model, input_normal);
    TEST_ASSERT_TRUE(anomaly_score_normal >= 0); // Assuming anomaly score should be non-negative

    // Free allocated memory
    for (int i = 0; i < 3; ++i) {
        free(input_data[i]);
    }
    free(input_data);
    fscl_jellyfish_erase_model(model);
}

XTEST_CASE(test_anomaly_detection_high) {
    // Create a model with input size 2 and output size 1
    jellyfish_model *model = fscl_anomaly_create_model(2, 1, "test_model");

    // Train the model with some sample data (for simplicity, using dummy data)
    float **input_data = (float **)malloc(sizeof(float *) * 3); // 3 samples
    for (int i = 0; i < 3; ++i) {
        input_data[i] = (float *)malloc(sizeof(float) * 2); // Input size is 2
        input_data[i][0] = i; // Dummy input data
        input_data[i][1] = i + 1; // Dummy input data
    }
    fscl_anomaly_train(model, input_data, 3, 10, 1); // Training for 10 epochs

    // Test anomaly detection with an input that is expected to be anomalous (high value)
    float input_high[2] = {10.5, 20.5}; // Dummy high input for testing
    float anomaly_score_high = fscl_anomaly_detect(model, input_high);
    TEST_ASSERT_TRUE(anomaly_score_high >= 0); // Assuming anomaly score should be non-negative

    // Free allocated memory
    for (int i = 0; i < 3; ++i) {
        free(input_data[i]);
    }
    free(input_data);
    fscl_jellyfish_erase_model(model);
}

XTEST_CASE(test_anomaly_detection_low) {
    // Create a model with input size 2 and output size 1
    jellyfish_model *model = fscl_anomaly_create_model(2, 1, "test_model");

    // Train the model with some sample data (for simplicity, using dummy data)
    float **input_data = (float **)malloc(sizeof(float *) * 3); // 3 samples
    for (int i = 0; i < 3; ++i) {
        input_data[i] = (float *)malloc(sizeof(float) * 2); // Input size is 2
        input_data[i][0] = i; // Dummy input data
        input_data[i][1] = i + 1; // Dummy input data
    }
    fscl_anomaly_train(model, input_data, 3, 10, 1); // Training for 10 epochs

    // Test anomaly detection with an input that is expected to be anomalous (low value)
    float input_low[2] = {-10.5, -20.5}; // Dummy low input for testing
    float anomaly_score_low = fscl_anomaly_detect(model, input_low);
    TEST_ASSERT_TRUE(anomaly_score_low >= 0); // Assuming anomaly score should be non-negative

    // Free allocated memory
    for (int i = 0; i < 3; ++i) {
        free(input_data[i]);
    }
    free(input_data);
    fscl_jellyfish_erase_model(model);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(anomaly_group) {
    XTEST_RUN_UNIT(test_anomaly_detection_basic);
    XTEST_RUN_UNIT(test_anomaly_detection_high);
    XTEST_RUN_UNIT(test_anomaly_detection_low);
} // end of fixture