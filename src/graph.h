#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <utility>
#include <vector>

/**
 * Graph represented by an adjacency list.
 *
 * For the graph's nodes, variations are stored using a vector instead of an unordered set.
 * This is because a linear search is going to be faster than a hash table lookup and
 * compare for the reasonably small number of variations a node will have.
 */
namespace graph {
    /**
     * Node in the graph.
     */
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

    /**
     * Pointer to a graph node.
     */
    typedef std::shared_ptr<node> node_ptr;

    /**
     * Iterator of node_ptr entries.
     */
    typedef std::vector<node_ptr>::iterator node_ptr_iterator;

    /**
     * Entry in the adjacency list.
     */
    typedef std::pair<node, std::vector<node_ptr>> adjacency_list_entry;

    /**
     * Iterator of adjacency list entries.
     */
    typedef std::vector<adjacency_list_entry>::iterator adj_list_iterator;

    /**
     * Adjacency list representation of a graph.
     */
    class adjacency_list {
    public:
        adjacency_list(size_t n_nodes);

        void add_node(node new_node);
        void remove_node(node_ptr remove_node);

        bool contains_node(node_ptr search_node);

        void add_edge(node_ptr node_i, node_ptr node_f);
        void remove_edge(node_ptr node_i, node_ptr node_f);

        size_t get_nodes_count();
        size_t get_edges_count();

        std::vector<node_ptr> get_nodes();
        std::vector<node_ptr> get_connected_to(node_ptr node_f);
        std::vector<node_ptr> get_connected_from(node_ptr node_i);

    private:
        size_t nodes_count;

        std::vector<adjacency_list_entry> adj_list;

        inline node_ptr_iterator find_node(std::vector<node_ptr> v, node_ptr n) {
            // clang-format off
            return std::find_if(v.begin(), v.end(), [n](node_ptr search_node) {
                return *n == *search_node;
            });
            // clang-format on
        }

        inline adj_list_iterator find_entry(node_ptr search_node) {
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
