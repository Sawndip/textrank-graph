#include "textrank.h"

#include <algorithm>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>

using namespace textrank;

std::vector<std::string> textrank::tokenize_words(std::string text) {
    std::vector<std::string> words{};

    // Trim leading and trailing spaces.
    text = boost::algorithm::trim_copy(text);

    // Replace punctuation with spaces.
    std::replace_if(text.begin(), text.end(),
                    [](const char& c) { return std::ispunct(c); }, ' ');

    if (text.size() == 0) return words;

    // Split text by whitespace and remove stopwords and puncutation.
    boost::algorithm::split(words, text, boost::is_any_of(" \n\t"),
                            boost::token_compress_on);
    words.erase(std::remove_if(words.begin(), words.end(), [&](const std::string s){
    if (s.size() < 3) return true;
    return std::find(stopwords.begin(), stopwords.end(), s) != stopwords.end();
    }), words.end());

    return words;
}
