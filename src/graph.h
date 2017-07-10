#pragma once

#include <memory>
#include <string>
#include <vector>

namespace graph {
    class node {
    public:
        node(std::string data, double score);

        bool operator==(node const& n);

        void add_variation(std::string data);
        void remove_variation(std::string data);

        bool has_variation(std::string data);

        double get_averaged_score();
        double get_score();
        std::string get_data();
        std::vector<std::string> get_variations();

    private:
        double score;
        std::string data;

        // We are using a vector instead of an unordered_set because a linear
        // search is going to be faster than a hash table lookup and compare for
        // the reasonable small number of variations.
        std::vector<std::string> variations;
    };

    class edge {
    public:
        edge(std::shared_ptr<node> node_i, std::shared_ptr<node> node_f);

        std::shared_ptr<node> node_i;  // initial node
        std::shared_ptr<node> node_f;  // final node
    };

    class adjacency_list {
    public:
        adjacency_list(size_t n_nodes);

    private:
        std::vector<node> nodes;
        std::vector<std::shared_ptr<node>> edges;
    };
}
