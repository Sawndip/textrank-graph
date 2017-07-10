#include "../src/graph.h"

#include <string>

#include <catch/catch.hpp>

SCENARIO("checking equality of nodes", "[node]") {
    GIVEN("nodes with equal data") {
        graph::node node_a("N", 0);
        graph::node node_b("N", 0);

        THEN("should return true") {
            REQUIRE(node_a == node_b);
        }
    }

    GIVEN("nodes with different data") {
        graph::node node_a("A", 0);
        graph::node node_b("B", 0);

        THEN("should return false") {
            REQUIRE_FALSE(node_a == node_b);
        }
    }
}

SCENARIO("adding variation to node", "[node]") {
    GIVEN("a node without variations") {
        graph::node new_node("N", 0);

        CHECK(new_node.get_variations().empty());

        THEN("should add variation") {
            new_node.add_variation("V");

            std::vector<std::string> expected_variations{"V"};
            REQUIRE(new_node.get_variations() == expected_variations);
        }
    }

    GIVEN("a node with an existing variation") {
        graph::node new_node("N", 0);
        new_node.add_variation("V");

        std::vector<std::string> init_variations{"V"};
        CHECK(new_node.get_variations() == init_variations);

        THEN("should not add duplicate variation") {
            new_node.add_variation("V");

            std::vector<std::string> expected_variations{"V"};
            REQUIRE(new_node.get_variations() == expected_variations);
        }
    }
}

SCENARIO("removing variation from node", "[node]") {
    GIVEN("a node with existing variations") {
        graph::node new_node("N", 0);
        new_node.add_variation("V1");
        new_node.add_variation("V2");

        THEN("should be a nop if variation doesn't exist") {
            new_node.remove_variation("V3");

            std::vector<std::string> expected_variations{"V1", "V2"};
            REQUIRE(new_node.get_variations() == expected_variations);
        }

        THEN("should remove the specified variation") {
            new_node.remove_variation("V2");

            std::vector<std::string> expected_variations{"V1"};
            REQUIRE(new_node.get_variations() == expected_variations);
        }
    }
}

SCENARIO("checking if node has a variation", "[node]") {
    GIVEN("a node with existing variations") {
        graph::node new_node("N", 0);
        new_node.add_variation("V");

        THEN("should return true if variation exists") {
            REQUIRE(new_node.has_variation("V"));
        }

        THEN("should return false if variation doesn't exists") {
            REQUIRE_FALSE(new_node.has_variation("W"));
        }
    }
}

SCENARIO("getting average score", "[node]") {
    GIVEN("a node with multiple variations") {
        double score = 10;
        int n_variations = 5;

        graph::node new_node("N", score);
        for (int i = 0; i < n_variations; i++) {
            new_node.add_variation("V" + std::to_string(i));
        }

        THEN("average score should be an average of the variations") {
            REQUIRE(new_node.get_averaged_score() == score / n_variations);
        }
    }
}
