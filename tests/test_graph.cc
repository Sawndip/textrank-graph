#include "../src/graph.h"

#include <vector>

#include <catch/catch.hpp>

SCENARIO("constructing an adjacency list", "[graph][adjacency_list]") {
    THEN("should create new empty adjacency list") {
        graph::adjacency_list new_graph(0);

        REQUIRE(new_graph.get_size() == 0);
        REQUIRE(new_graph.get_nodes().empty());
    }
}
