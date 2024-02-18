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
#ifndef FSCL_JELLYFISH_NLG_H
#define FSCL_JELLYFISH_NLG_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "jellyfish.h"

// Enum to represent different NLG tasks
typedef enum {
    SourceCodeDocumentation,
    Description,
    PseudoCode,
    MarkdownDocumentation,
    // Add more NLG tasks as needed
} NLGTask;

// Enum to represent supported programming languages
typedef enum {
    C,
    CPlusPlus,
    Python,
    Cython,
    Dart,
    // Add more languages as needed
} ProgrammingLanguage;

// NLG model structure
typedef struct {
    jellyfish_model *language_models[5]; // Assuming 5 languages for illustration
    // Add additional components for other NLG tasks or features as needed
} NLGModel;

// ==========================================================
// General API for NLG
// ==========================================================

// Function to create an NLG model
NLGModel *fscl_jellyfish_nlg_create_model(void);

// Function to erase an NLG model
void fscl_jellyfish_nlg_erase_model(NLGModel *nlg_model);

// Function to generate natural language for a specific task and language
char *fscl_jellyfish_nlg_generate(NLGModel *nlg_model, NLGTask task, ProgrammingLanguage language, const char *input);

#ifdef __cplusplus
}
#endif

#endif
