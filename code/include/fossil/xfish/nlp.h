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

#include "jellyfish.h"

// Language enum
typedef enum {
    English,
    Spanish,
    Italian,
    UnknownLanguage
} NlpLanguage;

// Sentiment enum
typedef enum {
    Positive,
    Negative,
    Neutral
} Sentiment;

// Part-of-Speech (POS) enum
typedef enum {
    Noun,
    Verb,
    Adjective,
    Adverb,
    Pronoun,
    Preposition,
    Conjunction,
    Interjection,
    UnknownPOS
} PartOfSpeech;

// NLP Model structure
typedef struct {
    jellyfish_model *tokenization_model;
    jellyfish_model *pos_tagging_model;
} NlpModel;

// ==========================================================
// General API for NLP
// ==========================================================

// Tokenization function
char **fscl_jellyfish_nlp_tokenize(const char *text, NlpModel *nlp_model);

// Punctuation removal function
char *fscl_jellyfish_nlp_remove_punctuation(const char *text);

// Stop word removal function
char *fscl_jellyfish_nlp_remove_stop_words(const char *text, NlpLanguage language);

// Language detection function
NlpLanguage fscl_jellyfish_nlp_detect_language(const char *text);

// Erase tokens function
void fscl_jellyfish_nlp_erase_tokens(char **tokens);

// Part-of-Speech (POS) tagging function
PartOfSpeech *fscl_jellyfish_nlp_pos_tag(const char *text, NlpModel *nlp_model);

// Sentiment Analysis function
Sentiment fscl_jellyfish_nlp_sentiment_analysis(const char *text, NlpModel *nlp_model);

// ==========================================================
// NLP Model functions
// ==========================================================

// Function to create an NLP model
NlpModel *fscl_jellyfish_nlp_create_model(void);

// Function to erase an NLP model
void fscl_jellyfish_nlp_erase_model(NlpModel *nlp_model);

#ifdef __cplusplus
}
#endif

#endif
