#include "graph.h"

#include <memory>

using namespace graph;

edge::edge(std::shared_ptr<node> node_i, std::shared_ptr<node> node_f) {
    this->node_i = node_i;
    this->node_f = node_f;
}

bool edge::operator==(edge const& e) {
    return *(this->node_i) == *(e.node_i) && *(this->node_f) == *(e.node_f);
}
