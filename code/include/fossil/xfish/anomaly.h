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
#ifndef FSCL_JELLYFISH_ANOMALY_H
#define FSCL_JELLYFISH_ANOMALY_H

#ifdef __cplusplus
extern "C"
{
#endif

// Enum to represent different anomaly detection algorithms
typedef enum {
    ZScore,
    IsolationForest,
    // Add more algorithms as needed
} AnomalyDetectionAlgorithm;

// Anomaly detection model structure
typedef struct {
    jellyfish_model *normalization_model;
    AnomalyDetectionAlgorithm current_algorithm;
    // Add additional components for other algorithms or features as needed
} AnomalyDetectionModel;

// ========================================================================
// create and erase functions
// ========================================================================

// Function to create an anomaly detection model
AnomalyDetectionModel *fscl_jellyfish_anomaly_detection_create_model(void);

// Function to erase an anomaly detection model
void fscl_jellyfish_anomaly_detection_erase_model(AnomalyDetectionModel *anomaly_model);

// Function to train the anomaly detection model
void fscl_jellyfish_anomaly_detection_train(AnomalyDetectionModel *anomaly_model, float **training_data, int num_samples, int num_features);

// Function to detect anomalies in new data
int *fscl_jellyfish_anomaly_detection_detect(AnomalyDetectionModel *anomaly_model, float **new_data, int num_samples, int num_features);

// Function to detect anomalies in new data with a configurable threshold
int *fscl_jellyfish_anomaly_detection_detect_threshold(AnomalyDetectionModel *anomaly_model, float **new_data, int num_samples, int num_features, float threshold);

// Function to update the anomaly detection model with new data
void fscl_jellyfish_anomaly_detection_update(AnomalyDetectionModel *anomaly_model, float **new_data, int num_samples, int num_features);

// Function to save the anomaly detection model to a file
void fscl_jellyfish_anomaly_detection_save_model(AnomalyDetectionModel *anomaly_model, const char *model_name);

// Function to load the anomaly detection model from a file
AnomalyDetectionModel *fscl_jellyfish_anomaly_detection_load_model(const char *model_name);

// Function to evaluate the performance of the anomaly detection model
void fscl_jellyfish_anomaly_detection_evaluate(AnomalyDetectionModel *anomaly_model, float **test_data, int *ground_truth_labels, int num_samples, int num_features);

// Function to visualize the detected anomalies
void fscl_jellyfish_anomaly_detection_visualize(AnomalyDetectionModel *anomaly_model, float **new_data, int *anomaly_labels, int num_samples, int num_features);

// Function to set the anomaly detection algorithm
void fscl_jellyfish_anomaly_detection_set_algorithm(AnomalyDetectionModel *anomaly_model, AnomalyDetectionAlgorithm algorithm);

#ifdef __cplusplus
}
#endif

#endif
