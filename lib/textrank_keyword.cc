#include "textrank.h"

#include <string>
#include <vector>

#include "graph.h"

using namespace textrank;

keyword::keyword(graph::node node) {
    this->node = node;
}

double keyword::get_score() {
    return this->node.score;
}

std::string keyword::get_keyword() {
    return this->node.data;
}

std::vector<std::string> keyword::get_variations() {
    return this->node.get_variations();
}
