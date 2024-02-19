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
#ifndef FSCL_JELLYFISH_NLP_H
#define FSCL_JELLYFISH_NLP_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xfish/jellyfish.h"

// Lookup table for English stop words
const char *ENGLISH_STOP_WORDS[] = {
    "the", "and", "is", "in", "it", "to", "of", "that", "you", "this",
    "have", "for", "not", "with", "as", "at", "do", "be", "by", "are",
    "on", "but", "if", "or", "was", "we", "an", "your", "our", "my"
    // Add more English stop words as needed
};

// Lookup table for Spanish stop words
const char *SPANISH_STOP_WORDS[] = {
    "el", "la", "es", "en", "y", "a", "los", "las", "de", "que",
    "tu", "esto", "con", "por", "un", "una", "lo", "se", "como", "para"
    // Add more Spanish stop words as needed
};

// Lookup table for Italian stop words
const char *ITALIAN_STOP_WORDS[] = {
    "il", "la", "è", "in", "e", "un", "una", "con", "per", "che",
    "non", "su", "come", "lo", "ma", "al", "si", "dei", "delle", "da"
    // Add more Italian stop words as needed
};

// Lookup table for Russian stop words
const char *RUSSIAN_STOP_WORDS[] = {
    "и", "в", "не", "на", "с", "что", "как", "по", "это", "он",
    "она", "но", "или", "у", "от", "за", "для", "при", "же", "вы"
    // Add more Russian stop words as needed
};

// Lookup table for Canadian (English) stop words
const char *CANADIAN_STOP_WORDS[] = {
    "eh", "aboot", "oot", "eh?", "toque", "double-double", "chesterfield",
    "poutine", "tuque", "loonie", "toonie", "serviette", "hydro", "keener",
    "mickey", "hydro", "runners", "washroom", "chesterfield", "all-dressed"
    // Add more Canadian English stop words as needed
};

typedef struct {
    jellyfish_model *model;
    char ***stop_words_list;  // Ensure stop_words_list is declared as char ***
} JellyfishNLP;

// ========================================================================
// create and erase functions
// ========================================================================

// Function to initialize a JellyfishNLP object
JellyfishNLP *fscl_jellyfish_nlp_create(const char *model_file, const char *language);

// Function to perform NLP processing with stop words filtering
float *fscl_jellyfish_nlp_process(JellyfishNLP *nlp, float *input, const char *language, const char *tone);

// Function to deallocate memory for JellyfishNLP object
void fscl_jellyfish_nlp_erase(JellyfishNLP *nlp);

#ifdef __cplusplus
}
#endif

#endif
