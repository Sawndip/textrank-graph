#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <tuple>
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

    class edge {
    public:
        edge(std::shared_ptr<node> node_i, std::shared_ptr<node> node_f);

        bool operator==(edge const& e);

        std::shared_ptr<node> node_i;  // initial node
        std::shared_ptr<node> node_f;  // final node
    };

    typedef std::tuple<std::shared_ptr<node>, std::vector<edge>>
        adjacency_list_entry;
    typedef std::vector<adjacency_list_entry>::iterator adj_list_iterator;

    class adjacency_list {
    public:
        adjacency_list(size_t n_nodes);

        void add_node(std::shared_ptr<node> n);
        void remove_node(std::shared_ptr<node> n);

        void add_edge(edge e);
        void remove_edge(edge e);

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

        inline adj_list_iterator find_node(std::shared_ptr<node> search_node) {
            // clang-format off
            return std::find_if(
                this->adj_list.begin(), this->adj_list.end(),
                [search_node](adjacency_list_entry& entry) {
                    return *std::get<0>(entry) == *search_node;
                }
            );
            // clang-format on
        }
    };
}
