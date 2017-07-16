#include "../src/graph.h"

#include <memory>
#include <vector>

#include <catch/catch.hpp>

SCENARIO("constructing an adjacency list", "[graph][adjacency_list]") {
    THEN("should create new empty adjacency list") {
        graph::adjacency_list new_graph(0);

        REQUIRE(new_graph.get_nodes_count() == 0);
        REQUIRE(new_graph.get_nodes().empty());
    }
}

SCENARIO("adding a node", "[graph][adjacency_list]") {
    GIVEN("nodes to add to the graph") {
        graph::node node_a("A", 0);
        graph::node node_b("B", 0);

        WHEN("adding nodes") {
            graph::adjacency_list new_graph(1);
            new_graph.add_node(std::make_shared<graph::node>(node_a));

            THEN("should have updated size") {
                REQUIRE(new_graph.get_nodes_count() ==1);
            }

            THEN("should contain correct nodes") {
                REQUIRE(*(new_graph.get_nodes()[0]) == node_a);

                REQUIRE(new_graph.contains_node(
                    std::make_shared<graph::node>(node_a)));
                REQUIRE_FALSE(new_graph.contains_node(
                    std::make_shared<graph::node>(node_b)));
            }
        }

        WHEN("adding more nodes than specified") {
            graph::adjacency_list new_graph(0);
            new_graph.add_node(std::make_shared<graph::node>(node_a));

            THEN("should have updated size") {
                REQUIRE(new_graph.get_nodes_count() == 1);
            }

            THEN("should contain correct nodes") {
                REQUIRE(*(new_graph.get_nodes()[0]) == node_a);

                REQUIRE(new_graph.contains_node(
                    std::make_shared<graph::node>(node_a)));
                REQUIRE_FALSE(new_graph.contains_node(
                    std::make_shared<graph::node>(node_b)));
            }
        }
    }
}

SCENARIO("removing a node", "[graph][adjacency_list]") {
    GIVEN("a graph with nodes") {
        graph::node node_a("A", 0);
        graph::node node_b("B", 0);

        graph::adjacency_list new_graph(2);
        new_graph.add_node(std::make_shared<graph::node>(node_a));
        new_graph.add_node(std::make_shared<graph::node>(node_b));

        CHECK(new_graph.get_nodes_count() == 2);

        WHEN("removing nodes") {
            new_graph.remove_node(std::make_shared<graph::node>(node_a));

            THEN("should have updated size") {
                REQUIRE(new_graph.get_nodes_count() == 1);
            }

            THEN("should contain correct nodes") {
                REQUIRE(*(new_graph.get_nodes()[0]) == node_b);

                REQUIRE_FALSE(new_graph.contains_node(
                    std::make_shared<graph::node>(node_a)));
                REQUIRE(new_graph.contains_node(
                    std::make_shared<graph::node>(node_b)));
            }
        }
    }
}
