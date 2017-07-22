#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "../src/graph.h"

using namespace graph;

TEST(graph_node, equality) {
    node node_a("N", 0);
    node node_b("N", 1);

    ASSERT_TRUE(node_a == node_b);
}

TEST(graph_node, inequality) {
    node node_a("A", 0);
    node node_b("B", 0);

    ASSERT_FALSE(node_a == node_b);
}

TEST(graph_node, add_variation) {
    node new_node("N", 0);

    EXPECT_TRUE(new_node.get_variations().empty());

    new_node.add_variation("V");

    std::vector<std::string> expected_variations{"V"};
    ASSERT_EQ(new_node.get_variations(), expected_variations);
}

TEST(graph_node, add_duplicate_variation) {
    node new_node("N", 0);
    new_node.add_variation("V");

    std::vector<std::string> expected_variations{"V"};
    EXPECT_EQ(new_node.get_variations(), expected_variations);

    new_node.add_variation("V");

    ASSERT_EQ(new_node.get_variations(), expected_variations);
}

TEST(graph_node, has_variation) {
    node new_node("N", 0);

    EXPECT_FALSE(new_node.has_variation("V"));

    new_node.add_variation("V");

    ASSERT_TRUE(new_node.has_variation("V"));
}

TEST(graph_node, get_averaged_score) {
    double score = 10;
    int n_variations = 5;

    node new_node("N", score);
    for (int i = 0; i < n_variations; i++) {
        new_node.add_variation("V" + std::to_string(i));
    }

    EXPECT_EQ(new_node.get_variations().size(), n_variations);
    ASSERT_EQ(new_node.get_averaged_score(), score / n_variations);
}
