#include "graph_test.hpp"
#include "graph.hpp"
#include <gtest/gtest.h>

// getter tests
TEST(getterTest, HandlesPositiveInput) {
    Graph myGraph(10);
    EXPECT_EQ(myGraph.getVertex(), 10);
    EXPECT_EQ(myGraph.getEdges(), 0);
};

// // setter tests
// TEST(setterTest, HandlesPositiveInput) {
//     Graph myGraph(4);
//     myGraph.setEdges(4);
//     EXPECT_EQ(myGraph.getEdges(), 4);
//     myGraph.setVertex(4);
//     EXPECT_EQ(myGraph.getVertex(), 4);
// };

// adding edge tests
TEST(addEdgeTest, HandlesPositiveInput) {
    Graph myGraph(4);
    myGraph.addEdge(1, 0);
    EXPECT_EQ(myGraph.getEdges(), 1);
    myGraph.addEdge(1, 2);
    EXPECT_EQ(myGraph.getEdges(), 2);
}
