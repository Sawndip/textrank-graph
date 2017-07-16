#include "graph.h"

#include <vector>

using namespace graph;

adjacency_list::adjacency_list(size_t n_nodes) {
    this->size = 0;
    this->adj_list = std::vector<adjacency_list_entry>{};

    if (n_nodes > 0) this->adj_list.reserve(n_nodes);
}

void adjacency_list::add_node(std::shared_ptr<node> n) {
    if (!this->contains_node(n)) return;

    adjacency_list_entry new_entry = std::make_tuple(n, std::vector<edge>{});

    if (this->size == this->adj_list.size()) {
        this->adj_list.push_back(new_entry);
    } else {
        this->adj_list[this->size] = new_entry;
    }

    this->size++;
}

size_t adjacency_list::get_size() {
    return this->size;
}

std::vector<std::shared_ptr<node>> adjacency_list::get_nodes() {
    std::vector<std::shared_ptr<node>> nodes{};
    nodes.reserve(this->size);

    for (auto const& entry : this->adj_list) {
        nodes.push_back(std::get<0>(entry));
    }

    return nodes;
}

bool adjacency_list::contains_node(std::shared_ptr<node> search_node) {
    return this->find_node(search_node) != this->adj_list.end();
}
