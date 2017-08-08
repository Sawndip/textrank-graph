#pragma once

#include <string>
#include <vector>

#include "graph.h"

/**
 * TextRank algorithm.
 */
namespace textrank {
    class keyword {
    public:
        keyword(graph::node node);

        double get_score();
        std::string get_keyword();
        std::vector<std::string> get_variations();

    private:
        graph::node node;
    };

    class sentence {
    public:
        sentence(graph::node node);

        std::string get_sentence();
        double get_score();

    private:
        graph::node node;
    };

    // std::vector<keyword> rank_keywords(std::vector<std::string> tokens);
    // std::vector<sentence> rank_sentences(std::vector<std::string> tokens);

    std::vector<std::string> tokenize_words(std::string text);

    static const std::vector<std::string> stopwords{
        "a",       "about",   "above",  "after",      "again",    "against",    "ain",
        "all",     "am",      "an",     "and",        "any",      "are",        "aren",
        "as",      "at",      "be",     "because",    "been",     "before",     "being",
        "below",   "between", "both",   "but",        "by",       "can",        "couldn",
        "d",       "did",     "didn",   "do",         "does",     "doesn",      "doing",
        "don",     "down",    "during", "each",       "few",      "for",        "from",
        "further", "had",     "hadn",   "has",        "hasn",     "have",       "haven",
        "having",  "he",      "her",    "here",       "hers",     "herself",    "him",
        "himself", "his",     "how",    "i",          "if",       "in",         "into",
        "is",      "isn",     "it",     "its",        "itself",   "just",       "ll",
        "m",       "ma",      "me",     "mightn",     "more",     "most",       "mustn",
        "my",      "myself",  "needn",  "no",         "nor",      "not",        "now",
        "o",       "of",      "off",    "on",         "once",     "only",       "or",
        "other",   "our",     "ours",   "ourselves",  "out",      "over",       "own",
        "re",      "s",       "same",   "shan",       "she",      "should",     "shouldn",
        "so",      "some",    "such",   "t",          "than",     "that",       "the",
        "their",   "theirs",  "them",   "themselves", "then",     "there",      "these",
        "they",    "this",    "those",  "through",    "to",       "too",        "under",
        "until",   "up",      "ve",     "very",       "was",      "wasn",       "we",
        "were",    "weren",   "what",   "when",       "where",    "which",      "while",
        "who",     "whom",    "why",    "will",       "with",     "won",        "wouldn",
        "y",       "you",     "your",   "yours",      "yourself", "yourselves",
    };
}
