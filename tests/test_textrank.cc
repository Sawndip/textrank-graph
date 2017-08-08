#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "../lib/textrank.h"

using namespace textrank;

TEST(tokenize_words, empty_string) {
    ASSERT_TRUE(tokenize_words("").empty());
    ASSERT_TRUE(tokenize_words(" ").empty());
    ASSERT_TRUE(tokenize_words("\n").empty());
    ASSERT_TRUE(tokenize_words("\t").empty());
}

TEST(tokenize_words, split_whitespace) {
    std::string words = "abc\ndef\tghi jkl  mno";
    std::vector<std::string> expected_tokens{"abc", "def", "ghi", "jkl", "mno"};

    ASSERT_TRUE(tokenize_words(words) == expected_tokens);
}

TEST(tokenize_words, strip_whitespace) {
    std::string words = " abc def ghi\n";
    std::vector<std::string> expected_tokens{"abc", "def", "ghi"};

    ASSERT_TRUE(tokenize_words(words) == expected_tokens);
}

TEST(tokenize_words, strip_punctuation) {
    std::string words = "abc.def: ghi, jkl";
    std::vector<std::string> expected_tokens{"abc", "def", "ghi", "jkl"};

    ASSERT_TRUE(tokenize_words(words) == expected_tokens);
}

TEST(tokenize_words, strip_stopwords) {
    std::string words = "the dog is funny";
    std::vector<std::string> expected_tokens{"dog", "funny"};

    ASSERT_TRUE(tokenize_words(words) == expected_tokens);
}
