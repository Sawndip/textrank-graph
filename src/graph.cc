#include "graph.h"

#include <vector>

using namespace graph;

adjacency_list::adjacency_list(size_t n_nodes) {
    this->nodes_count = 0;
    this->adj_list = std::vector<adjacency_list_entry>{};

    if (n_nodes > 0) this->adj_list.reserve(n_nodes);
}

void adjacency_list::add_node(node new_node) {
    if (this->contains_node(std::make_shared<node>(new_node))) return;

    adjacency_list_entry new_entry =
        std::make_pair(new_node, std::vector<std::shared_ptr<node>>{});

    if (this->nodes_count == this->adj_list.size()) {
        this->adj_list.push_back(new_entry);
    } else {
        this->adj_list[this->nodes_count] = new_entry;
    }

    this->nodes_count++;
}

void adjacency_list::remove_node(std::shared_ptr<node> remove_node) {
    auto it = this->find_entry(remove_node);
    if (it == this->adj_list.end()) return;

    this->adj_list.erase(it);
    this->nodes_count--;
}

void adjacency_list::add_edge(std::shared_ptr<node> node_i, std::shared_ptr<node> node_f) {
    auto it = this->find_entry(node_i);
    if (it == this->adj_list.end()) this->add_node(*node_i);

    it->second.push_back(node_f);
}

bool adjacency_list::contains_node(std::shared_ptr<node> search_node) {
    return this->find_entry(search_node) != this->adj_list.end();
}

size_t adjacency_list::get_nodes_count() {
    return this->nodes_count;
}

std::vector<std::shared_ptr<node>> adjacency_list::get_nodes() {
    std::vector<std::shared_ptr<node>> nodes{};
    nodes.reserve(this->nodes_count);

    for (auto const& entry : this->adj_list) {
        nodes.push_back(std::make_shared<node>(entry.first));
    }

    return nodes;
}
