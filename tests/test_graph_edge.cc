#include "../src/graph.h"

#include <catch/catch.hpp>

SCENARIO("checking edge equality", "[edge]") {
    GIVEN("graph nodes") {
        graph::node node_a("A", 0);
        graph::node node_b("B", 0);
        graph::node node_c("C", 0);

        THEN("should return true for equal edge") {
            graph::edge edge_a(std::make_shared<graph::node>(node_a),
                               std::make_shared<graph::node>(node_b));
            graph::edge edge_b(std::make_shared<graph::node>(node_a),
                               std::make_shared<graph::node>(node_b));

            REQUIRE(edge_a == edge_b);
        }

        THEN("should return false for different initial node") {
            graph::edge edge_a(std::make_shared<graph::node>(node_a),
                               std::make_shared<graph::node>(node_b));
            graph::edge edge_b(std::make_shared<graph::node>(node_c),
                               std::make_shared<graph::node>(node_b));

            REQUIRE_FALSE(edge_a == edge_b);
        }

        THEN("should return false for difference final node") {
            graph::edge edge_a(std::make_shared<graph::node>(node_a),
                               std::make_shared<graph::node>(node_b));
            graph::edge edge_b(std::make_shared<graph::node>(node_a),
                               std::make_shared<graph::node>(node_c));

            REQUIRE_FALSE(edge_a == edge_b);
        }
    }
}
