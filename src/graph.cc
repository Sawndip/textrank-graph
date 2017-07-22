#include "graph.h"

#include <algorithm>
#include <memory>
#include <utility>
#include <vector>

using namespace graph;

adjacency_list::adjacency_list(size_t n_nodes) {
    this->nodes_count = 0;
    this->adj_list = std::vector<adjacency_list_entry>{};

    if (n_nodes > 0) this->adj_list.reserve(n_nodes);
}

void adjacency_list::add_node(node new_node) {
    if (this->contains_node(std::make_shared<node>(new_node))) return;

    adjacency_list_entry new_entry = std::make_pair(new_node, std::vector<node_ptr>{});

    if (this->nodes_count == this->adj_list.size()) {
        this->adj_list.push_back(new_entry);
    } else {
        this->adj_list[this->nodes_count] = new_entry;
    }

    this->nodes_count++;
}

void adjacency_list::remove_node(node_ptr remove_node) {
    auto it = this->find_entry(remove_node);
    if (it == this->adj_list.end()) return;

    this->adj_list.erase(it);
    this->nodes_count--;
}

// TODO: Add tests.
void adjacency_list::add_edge(node_ptr node_i, node_ptr node_f) {
    auto it = this->find_entry(node_i);
    if (it == this->adj_list.end()) this->add_node(*node_i);

    it->second.push_back(node_f);
}

// TODO: Add tests.
void adjacency_list::remove_edge(node_ptr node_i, node_ptr node_f) {
    auto it = this->find_entry(node_i);
    if (it == this->adj_list.end()) return;

    auto adjacent = it->second;
    adjacent.erase(
        std::remove_if(adjacent.begin(), adjacent.end(),
                       [node_f](node_ptr focus_node) { return *node_f == *focus_node; }),
        adjacent.end());
}

bool adjacency_list::contains_node(node_ptr search_node) {
    return this->find_entry(search_node) != this->adj_list.end();
}

size_t adjacency_list::get_nodes_count() {
    return this->nodes_count;
}

std::vector<node_ptr> adjacency_list::get_nodes() {
    std::vector<node_ptr> nodes{};
    nodes.reserve(this->nodes_count);

    for (auto const& entry : this->adj_list) {
        nodes.push_back(std::make_shared<node>(entry.first));
    }

    return nodes;
}

/**
 * Get nodes that are connected to `node_f`.
 * @param node_f Final node.
 *
 * TODO: Add tests.
 */
std::vector<node_ptr> adjacency_list::get_connected_to(node_ptr node_f) {
    std::vector<node_ptr> connected_to{};

    for (auto entry : this->adj_list) {
        auto it = std::find_if(
            entry.second.begin(), entry.second.end(),
            [node_f](node_ptr& search_node) { return *node_f == *search_node; });

        if (it != entry.second.end()) {
            connected_to.push_back(std::make_shared<node>(entry.first));
        }
    }

    return connected_to;
}

/**
 * Get nodes that `node_i` is connected to.
 * @param node_i Initial node.
 *
 * TODO: Add tests.
 */
std::vector<node_ptr> adjacency_list::get_connected_from(node_ptr node_i) {
    auto it = this->find_entry(node_i);

    if (it == this->adj_list.end()) {
        return std::vector<node_ptr>{};
    }
    return it->second;
}
