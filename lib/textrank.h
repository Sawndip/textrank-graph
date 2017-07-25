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

    std::vector<keyword> rank_keywords(std::string text);
    std::vector<sentence> rank_sentences(std::string text);
}
