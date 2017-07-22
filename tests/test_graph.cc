#include <memory>
#include <vector>

#include <gtest/gtest.h>

#include "../src/graph.h"

using namespace graph;

TEST(graph, create_adjacency_list) {
    adjacency_list new_graph(0);

    ASSERT_EQ(new_graph.get_nodes_count(), 0);
    ASSERT_TRUE(new_graph.get_nodes().empty());
}

TEST(graph, add_node) {
    adjacency_list new_graph(1);

    EXPECT_EQ(new_graph.get_nodes_count(), 0);

    node new_node("N", 0);
    new_graph.add_node(new_node);

    ASSERT_EQ(new_graph.get_nodes_count(), 1);
    ASSERT_TRUE(*(new_graph.get_nodes()[0]) == new_node);
}

TEST(graph, add_more_nodes_than_specified) {
    adjacency_list new_graph(0);

    EXPECT_EQ(new_graph.get_nodes_count(), 0);

    node new_node("N", 0);
    new_graph.add_node(new_node);

    ASSERT_EQ(new_graph.get_nodes_count(), 1);
    ASSERT_TRUE(*(new_graph.get_nodes()[0]) == new_node);
}

TEST(graph, add_duplicate_node) {
    node new_node("N", 0);
    adjacency_list new_graph(1);

    new_graph.add_node(new_node);
    EXPECT_EQ(new_graph.get_nodes_count(), 1);

    new_graph.add_node(new_node);

    ASSERT_EQ(new_graph.get_nodes_count(), 1);
    ASSERT_TRUE(*(new_graph.get_nodes()[0]) == new_node);
}

TEST(graph, remove_node) {
    node new_node("N", 0);
    adjacency_list new_graph(1);

    new_graph.add_node(new_node);
    EXPECT_EQ(new_graph.get_nodes_count(), 1);

    new_graph.remove_node(std::make_shared<node>(new_node));

    ASSERT_EQ(new_graph.get_nodes_count(), 0);
    ASSERT_TRUE(new_graph.get_nodes().empty());
}

TEST(graph, remove_node_not_in_graph) {
    node node_a("A", 0);
    node node_b("B", 0);
    adjacency_list new_graph(1);

    new_graph.add_node(node_a);
    EXPECT_EQ(new_graph.get_nodes_count(), 1);

    new_graph.remove_node(std::make_shared<node>(node_b));

    ASSERT_EQ(new_graph.get_nodes_count(), 1);
    ASSERT_TRUE(*(new_graph.get_nodes()[0]) == node_a);
}

TEST(graph, contains_node) {
    node new_node("N", 0);
    adjacency_list new_graph(1);

    EXPECT_FALSE(new_graph.contains_node(std::make_shared<node>(new_node)));

    new_graph.add_node(new_node);

    EXPECT_TRUE(new_graph.contains_node(std::make_shared<node>(new_node)));
}
