#include "graph_test.hpp"
#include "graph.hpp"
#include "graph_algo.hpp"
#include <gtest/gtest.h>

// getter tests
TEST(getterTest, HandlesPositiveInput) {
    Graph myGraph(10);
    EXPECT_EQ(myGraph.getVertex(), 10);
    EXPECT_EQ(myGraph.getEdges(), 0);
};

// setter tests
TEST(resizeTest, HandlesPositiveInput) {
    Graph myGraph(4);
    myGraph.resizeVertex(6);
    EXPECT_EQ(myGraph.getVertex(), 6);
};

// adding edge tests
TEST(addEdgeTest, HandlesPositiveInput) {
    Graph myGraph(4);
    myGraph.addEdge(1, 0);
    EXPECT_EQ(myGraph.getEdges(), 1);
    myGraph.addEdge(1, 2);
    EXPECT_EQ(myGraph.getEdges(), 2);
    myGraph.addEdge(3, 2);
    EXPECT_EQ(myGraph.getEdges(), 3);
}

// print edge(s) tests
TEST(iterateEdgeTest, HandlePositiveInput) {
    Graph myGraph(4);
    myGraph.addEdge(1, 0);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(2, 3);
    myGraph.addEdge(3, 0);

    testing::internal::CaptureStdout();
    myGraph.printIterEdges(0);
    std::string output_0 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output_0, "1, 3\n");

    testing::internal::CaptureStdout();
    myGraph.printIterEdges(1);
    std::string output_1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output_1, "0, 2\n");

    testing::internal::CaptureStdout();
    myGraph.printIterEdges(2);
    std::string output_2 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output_2, "1, 3\n");

    testing::internal::CaptureStdout();
    myGraph.printIterEdges(3);
    std::string output_3 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output_3, "2, 0\n");
}

// delete edge tests
TEST(deleteEdgeTest, HandlesPositiveInput) {
    Graph myGraph(4);
    myGraph.addEdge(1, 0);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(3, 2);

    myGraph.deleteEdge(1, 0);
    testing::internal::CaptureStdout();
    myGraph.printIterEdges(1);
    std::string output_0 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output_0, "2\n");

    myGraph.deleteEdge(1, 2);
    testing::internal::CaptureStdout();
    myGraph.printIterEdges(1);
    std::string output_1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output_1, "No edges are connected to this vertex.\n");

    myGraph.deleteEdge(3, 2);
    testing::internal::CaptureStdout();
    myGraph.printIterEdges(3);
    std::string output_2 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output_2, "No edges are connected to this vertex.\n");
}

// degree tests
TEST(degreeTest, HandlesPositiveInput) {
    Graph myGraph(4);
    myGraph.addEdge(1, 0);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(3, 1);
    myGraph.addEdge(2, 1);
    EXPECT_EQ(myGraph.degree(1), 4);
}

// max degree tests
TEST(maxDegreeTest, HandlesPositiveInput) {
    Graph myGraph(4);
    myGraph.addEdge(1, 0);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(3, 1);
    myGraph.addEdge(3, 2);
    EXPECT_EQ(myGraph.maxDegree(), 3);
}

// self loop counter tests
TEST(selfLoopTest, HandlesPositiveInput) {
    Graph myGraph(4);
    myGraph.addEdge(1, 1);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(3, 1);
    myGraph.addEdge(3, 2);
    myGraph.addEdge(3, 3);
    EXPECT_EQ(myGraph.selfLoop(), 2);
}

// search class test
TEST(searchClassTest, HandlesPositiveInput) {
    Graph myGraph(4);
    myGraph.addEdge(1, 1);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(3, 1);
    myGraph.addEdge(3, 2);
    myGraph.addEdge(3, 3);

    Search mySearch(myGraph, 2);
    EXPECT_EQ(mySearch.count(), 2);
    EXPECT_EQ(mySearch.marked(1), true);
    EXPECT_EQ(mySearch.marked(3), true);
}