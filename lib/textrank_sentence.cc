#include "textrank.h"

#include <string>
#include <vector>

#include "graph.h"

using namespace textrank;

sentence::sentence(graph::node node) {
    this->node = node;
}

double sentence::get_score() {
    return this->node.score;
}

std::string sentence::get_sentence() {
    return this->node.data;
}
