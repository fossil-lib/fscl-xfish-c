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
#include <ctype.h>
#include <locale.h>

// Custom strdup function
char* fscl_custom_strdup(const char* str) {
    size_t len = strlen(str) + 1;  // +1 for the null terminator
    char* duplicate = (char*)malloc(len);
    if (duplicate != NULL) {
        strcpy(duplicate, str);
    }
    return duplicate;
}

// Function to tokenize text
void tokenize_text(char *text, char *tokens[], int *num_tokens) {
    // Assuming space as a delimiter for simplicity
    const char delimiter[] = " ";

    *num_tokens = 0;
    char *token = strtok(text, delimiter);

    while (token != NULL) {
        tokens[*num_tokens] = fscl_custom_strdup(token);  // Use the custom strdup function
        (*num_tokens)++;
        token = strtok(NULL, delimiter);
    }
}

// Function to check if a character is a punctuation mark
int is_punctuation(char c) {
    return ispunct(c);
}

// Function to check if a character is a numeric digit
int is_numeric(char c) {
    return isdigit(c);
}

// Function to check if a word is a stop word in English, Spanish, or Italian
int is_stop_word(char *word, char *language) {
    char *english_stop_words[] = {"a", "an", "and", "the", "is", "it", /* Add more as needed */};
    char *spanish_stop_words[] = {"el", "la", "y", "es", "lo", /* Add more as needed */};
    char *italian_stop_words[] = {"il", "la", "e", "è", "lo", /* Add more as needed */};

    char **stop_words;
    if (strcmp(language, "english") == 0) {
        stop_words = english_stop_words;
    } else if (strcmp(language, "spanish") == 0) {
        stop_words = spanish_stop_words;
    } else if (strcmp(language, "italian") == 0) {
        stop_words = italian_stop_words;
    } else {
        return 0; // Unsupported language
    }

    // Check if the word is a stop word
    for (int i = 0; i < sizeof(stop_words) / sizeof(stop_words[0]); i++) {
        if (strcmp(word, stop_words[i]) == 0) {
            return 1; // It's a stop word
        }
    }

    return 0; // Not a stop word
}

// Function to auto-detect the language of the text
char *detect_language(char *text) {
    if (strstr(text, "es")) {
        return "spanish";
    } else if (strstr(text, "it")) {
        return "italian";
    } else {
        return "english"; // Default to English if no match
    }
}

// Function to check if a word is likely a name (based on capitalization)
int is_name(char *word) {
    int len = strlen(word);
    if (len > 1 && isupper(word[0])) {
        // Check if most characters are uppercase (assumes names are generally capitalized)
        int uppercase_count = 0;
        for (int i = 1; i < len; i++) {
            if (isupper(word[i])) {
                uppercase_count++;
            }
        }
        // If at least half of the characters (excluding the first) are uppercase, consider it a name
        if (uppercase_count >= len / 2) {
            return 1;
        }
    }
    return 0;
}

// Function to detect humor using a more sophisticated rule-based system
int detect_humor(char *text) {
    // This is a simplified rule-based system; real-world solutions use machine learning models
    if (strstr(text, "haha") || strstr(text, "lol") || strstr(text, "funny") ||
        strstr(text, "joke") || strstr(text, "laugh") || strstr(text, "amusing")) {
        return 1; // Humor detected
    }
    return 0; // No humor detected
}

// Function to detect sarcasm using a more sophisticated rule-based system
int detect_sarcasm(char *text) {
    // This is a simplified rule-based system; real-world solutions use machine learning models
    if ((strstr(text, "not") && strstr(text, "good")) || strstr(text, "oh, great") ||
        strstr(text, "as if") || strstr(text, "sure, that'll work") ||
        (strstr(text, "real smooth") && strstr(text, "genius"))) {
        return 1; // Sarcasm detected
    }
    return 0; // No sarcasm detected
}

// Function to process text with auto-detected language, name detection, humor, sarcasm, and context
void fscl_nlp_fish(char *text, char *context) {
    // Initialize Jellyfish locale to handle Unicode characters
    setlocale(LC_ALL, "");

    char *detected_language = detect_language(text);

    // Check for humor and sarcasm
    int is_humor = detect_humor(text);
    int is_sarcasm = detect_sarcasm(text);

    char *tokens[100]; // Assuming a maximum of 100 tokens, adjust as needed
    int num_tokens;

    // Tokenize the text using Jellyfish
    tokenize_text(text, tokens, &num_tokens);

    for (int i = 0; i < num_tokens; i++) {
        // Process each word token
        if (!is_stop_word(tokens[i], detected_language)) {
            // Check if the word is likely a name
            if (is_name(tokens[i])) {
                printf("Name: %s\n", tokens[i]);
            } else {
                // Do something with non-stop words that are not names
                printf("%s ", tokens[i]);
            }
        }
    }

    // Print humor, sarcasm, and context detection results
    if (is_humor) {
        printf("\nHumor Detected!\n");
    }

    if (is_sarcasm) {
        printf("Sarcasm Detected!\n");
        // Incorporate context-awareness for sarcasm
        if (strstr(context, "disappointment")) {
            printf("Context suggests sarcasm due to disappointment.\n");
        } else {
            printf("Context suggests sarcasm.\n");
        }
    }

    // Incorporate context-awareness here using 'context'
    printf("Context: %s\n", context);
}
