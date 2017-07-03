#pragma once

#include <memory>
#include <string>
#include <vector>

namespace graph {
    class node {
    public:
        node(std::string data, double score);

    private:
        double score;
        std::string data;
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
