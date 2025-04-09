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

// verbol edge checker tests
TEST(doesEdgeExistTest, HandlesPositiveInput) {
    Graph myGraph(4);
    myGraph.addEdge(1, 0);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(3, 1);
    myGraph.addEdge(2, 1);

    testing::internal::CaptureStdout();
    myGraph.doesEdgeExist(1, 0);
    std::string output_0 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output_0, "Edge 1-0 found.\n");
    testing::internal::CaptureStdout();
    myGraph.doesEdgeExist(1, 2);
    std::string output_1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output_1, "Edge 1-2 found.\n");
    testing::internal::CaptureStdout();
    myGraph.doesEdgeExist(3, 1);
    std::string output_2 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output_2, "Edge 3-1 found.\n");
    testing::internal::CaptureStdout();
    myGraph.doesEdgeExist(2, 1);
    std::string output_3 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output_3, "Edge 2-1 found.\n");

    testing::internal::CaptureStdout();
    myGraph.doesEdgeExist(3, 0);
    std::string output_4 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output_4, "Edge 3-0 not found.\n");
    testing::internal::CaptureStdout();
    myGraph.doesEdgeExist(2, 0);
    std::string output_5 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output_5, "Edge 2-0 not found.\n");
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

TEST(mySearchClassTest, HandlesPositiveInput) {
    Graph myGraph(13);
    myGraph.addEdge(0, 5);
    myGraph.addEdge(4, 3);
    myGraph.addEdge(0, 1);
    myGraph.addEdge(9, 12);
    myGraph.addEdge(6, 4);
    myGraph.addEdge(5, 4);
    myGraph.addEdge(0, 2);
    myGraph.addEdge(11, 12);
    myGraph.addEdge(9, 10);
    myGraph.addEdge(0, 6);
    myGraph.addEdge(7, 8);
    myGraph.addEdge(9, 11);
    myGraph.addEdge(5, 3);

    Search mySearch(myGraph, 0);
    EXPECT_EQ(mySearch.marked(1), true);
    EXPECT_EQ(mySearch.marked(2), true);
    EXPECT_EQ(mySearch.marked(5), true);
    EXPECT_EQ(mySearch.marked(6), true);
    EXPECT_EQ(mySearch.marked(7), false);
    EXPECT_EQ(mySearch.marked(11), false);
}

TEST(DepthFirstSearchClassTest, HandlesPositiveInput) {
    Graph myGraph(13);
    myGraph.addEdge(0, 5);
    myGraph.addEdge(4, 3);
    myGraph.addEdge(0, 1);
    myGraph.addEdge(9, 12);
    myGraph.addEdge(6, 4);
    myGraph.addEdge(5, 4);
    myGraph.addEdge(0, 2);
    myGraph.addEdge(11, 12);
    myGraph.addEdge(9, 10);
    myGraph.addEdge(0, 6);
    myGraph.addEdge(7, 8);
    myGraph.addEdge(9, 11);
    myGraph.addEdge(5, 3);

    DepthFirstSearch dfs(myGraph, 0);
    auto marked = dfs.retMarked();
    for (int i = 0; i < static_cast<int>(marked.size()); i++) {
        if (i <= 6) {
            EXPECT_EQ(marked[i], true);
        }
        if (i >= 7)
            EXPECT_EQ(marked[i], false);
    }
}
