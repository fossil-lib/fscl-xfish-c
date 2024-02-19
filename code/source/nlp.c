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
#include "fossil/xfish/nlp.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom strdup function
static char *fscl_nlp_strdup(const char *str) {
    size_t len = strlen(str) + 1;  // Including the null terminator
    char *duplicate = (char *)malloc(len);
    if (duplicate != NULL) {
        strcpy(duplicate, str);
    }
    return duplicate;
}

// Function to check if a word is a stop word
int is_stop_word(char ***stop_words_list, const char *word) {
    // Assuming stop_words_list is an array of arrays of strings
    // If it's a 2D array of strings, it can iterate through rows and columns
    // If it's a 1D array of strings, it can iterate through the array directly

    // Example assuming a 2D array
    for (int i = 0; stop_words_list[i] != NULL; i++) {
        for (int j = 0; stop_words_list[i][j] != NULL; j++) {
            if (strcmp(stop_words_list[i][j], word) == 0) {
                return 1; // Word is a stop word
            }
        }
    }
    return 0; // Word is not a stop word
}

// Function to set stop words based on the specified language
static int set_stop_words(char ****stop_words_list, const char *language) {
    int num_stop_words = 0;
    const char **stop_words = NULL;

    // Determine stop words based on the specified language
    if (strcmp(language, "english") == 0) {
        stop_words = ENGLISH_STOP_WORDS;
        num_stop_words = sizeof(ENGLISH_STOP_WORDS) / sizeof(ENGLISH_STOP_WORDS[0]);
    } else if (strcmp(language, "spanish") == 0) {
        stop_words = SPANISH_STOP_WORDS;
        num_stop_words = sizeof(SPANISH_STOP_WORDS) / sizeof(SPANISH_STOP_WORDS[0]);
    } else if (strcmp(language, "italian") == 0) {
        stop_words = ITALIAN_STOP_WORDS;
        num_stop_words = sizeof(ITALIAN_STOP_WORDS) / sizeof(ITALIAN_STOP_WORDS[0]);
    } else if (strcmp(language, "russian") == 0) {
        stop_words = RUSSIAN_STOP_WORDS;
        num_stop_words = sizeof(RUSSIAN_STOP_WORDS) / sizeof(RUSSIAN_STOP_WORDS[0]);
    } else if (strcmp(language, "canadian") == 0) {
        stop_words = CANADIAN_STOP_WORDS;
        num_stop_words = sizeof(CANADIAN_STOP_WORDS) / sizeof(CANADIAN_STOP_WORDS[0]);
    } else {
        return 0; // Unsupported language
    }

    // Copy stop words to the JellyfishNLP object
    *stop_words_list = (char ***)malloc((num_stop_words + 1) * sizeof(char **));
    if (*stop_words_list == NULL) {
        return 0; // Memory allocation failed
    }

    for (int i = 0; i < num_stop_words; i++) {
        (*stop_words_list)[i] = fscl_nlp_strdup(stop_words[i]);
        if ((*stop_words_list)[i] == NULL) {
            // Memory allocation failed, clean up and return
            for (int j = 0; j < i; j++) {
                free((*stop_words_list)[j]);
            }
            free(*stop_words_list);
            return 0;
        }
    }

    // Set the last element of the list to NULL to indicate the end
    (*stop_words_list)[num_stop_words] = NULL;

    return 1; // Stop words set successfully
}

// Function to initialize a JellyfishNLP object
JellyfishNLP *fscl_jellyfish_nlp_create(const char *model_file, const char *language) {
    JellyfishNLP *nlp = (JellyfishNLP *)malloc(sizeof(JellyfishNLP));
    if (nlp == NULL) {
        return NULL; // Memory allocation failed
    }

    // Initialize stop_words_list to NULL for proper cleanup in case of errors
    nlp->stop_words_list = NULL;

    // Load the model from file
    nlp->model = fscl_jellyfish_load_model(model_file);
    if (nlp->model == NULL) {
        fscl_jellyfish_nlp_erase(nlp);
        return NULL; // Model loading failed
    }

    // Set stop words based on the specified language
    if (!set_stop_words((nlp->stop_words_list), language)) {
        fscl_jellyfish_nlp_erase(nlp);
        return NULL; // Stop words setting failed
    }

    // Additional initialization if needed

    return nlp;
}

// Function to perform NLP processing with stop words filtering and tone context
float *fscl_jellyfish_nlp_process(JellyfishNLP *nlp, float *input, const char *language, const char *tone) {
    if (nlp == NULL || nlp->model == NULL || input == NULL || language == NULL || tone == NULL) {
        return NULL; // Invalid input
    }

    int num_stop_words = 0;
    const char **stop_words_table = NULL;

    // Select the appropriate stop words table based on the specified language
    if (strcmp(language, "english") == 0) {
        stop_words_table = ENGLISH_STOP_WORDS;
        num_stop_words = sizeof(ENGLISH_STOP_WORDS) / sizeof(ENGLISH_STOP_WORDS[0]);
    } else if (strcmp(language, "spanish") == 0) {
        stop_words_table = SPANISH_STOP_WORDS;
        num_stop_words = sizeof(SPANISH_STOP_WORDS) / sizeof(SPANISH_STOP_WORDS[0]);
    } else if (strcmp(language, "italian") == 0) {
        stop_words_table = ITALIAN_STOP_WORDS;
        num_stop_words = sizeof(ITALIAN_STOP_WORDS) / sizeof(ITALIAN_STOP_WORDS[0]);
    } else if (strcmp(language, "russian") == 0) {
        stop_words_table = RUSSIAN_STOP_WORDS;
        num_stop_words = sizeof(RUSSIAN_STOP_WORDS) / sizeof(RUSSIAN_STOP_WORDS[0]);
    } else if (strcmp(language, "canadian") == 0) {
        stop_words_table = CANADIAN_STOP_WORDS;
        num_stop_words = sizeof(CANADIAN_STOP_WORDS) / sizeof(CANADIAN_STOP_WORDS[0]);
    }
    // Add more language cases as needed

    // Filter out stop words based on language
    // Apply context based on tone
    for (int i = 0; i < num_stop_words; i++) {
        if (is_stop_word(&(nlp->stop_words_list), stop_words_table[i])) {
            // If it's a stop word, apply context-based logic
            if (strcmp(tone, "positive") == 0) {
                // Apply positive context-based logic
                // For example, increase the importance of positive words
                input[i] *= 1.2; // Adjust weight for positive context
            } else if (strcmp(tone, "negative") == 0) {
                // Apply negative context-based logic
                // For example, increase the importance of negative words
                input[i] *= 0.8; // Adjust weight for negative context
            } else {
                // Default tone logic
                // For example, do nothing or apply neutral context-based logic
                // Here, we'll just leave the weight unchanged
            }
        }
    }

    // Perform NLP processing using the loaded model
    return fscl_jellyfish_predict(nlp->model, input);
}

// Function to deallocate memory for JellyfishNLP object
void fscl_jellyfish_nlp_erase(JellyfishNLP *nlp) {
    if (nlp != NULL) {
        if (nlp->model != NULL) {
            fscl_jellyfish_erase_model(nlp->model);
        }
        free(nlp);
    }
}
