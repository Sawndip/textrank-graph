#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <utility>
#include <vector>

// TODO: Inline documentation.
// For node variations we are using a vector instead of an unordered_set
// because a linear search is going to be faster than a hash table lookup and
// compare for the reasonable small number of variations.

namespace graph {
    class node {
    public:
        double score;
        std::string data;

        node(std::string data, double score);

        bool operator==(node const& n);

        void add_variation(std::string data);
        void remove_variation(std::string data);

        bool has_variation(std::string data);

        double get_averaged_score();
        std::vector<std::string> get_variations();

    private:
        std::vector<std::string> variations;
    };

    typedef std::pair<node, std::vector<std::shared_ptr<node>>>
        adjacency_list_entry;
    typedef std::vector<adjacency_list_entry>::iterator adj_list_iterator;

    class adjacency_list {
    public:
        adjacency_list(size_t n_nodes);

        void add_node(node new_node);
        void remove_node(std::shared_ptr<node> remove_node);

        void add_edge(std::shared_ptr<node> node_i,
                      std::shared_ptr<node> node_f);
        void remove_edge(std::shared_ptr<node> node_i,
                         std::shared_ptr<node> node_f);

        bool contains_node(std::shared_ptr<node> search_node);

        size_t get_nodes_count();
        std::vector<std::shared_ptr<node>> get_nodes();

        // List of nodes that are connected to the specified node.
        std::vector<node> get_connected_to(node);

        // List of nodes that are the specified node is connected to.
        std::vector<node> get_connected_from(node);

    private:
        size_t nodes_count;

        std::vector<adjacency_list_entry> adj_list;

        inline adj_list_iterator find_entry(std::shared_ptr<node> search_node) {
            // clang-format off
            return std::find_if(
                this->adj_list.begin(), this->adj_list.end(),
                [search_node](adjacency_list_entry& entry) {
                    return entry.first == *search_node;
                }
            );
            // clang-format on
        }
    };
}
