#include "graph_test.hpp"
#include "graph.hpp"
#include <gtest/gtest.h>

// cutRub tests
TEST(cutRodTest, HandlesPositiveInput) {
    for (int i = 0; i < NUM_LENGTH; i++) {
        EXPECT_EQ(Algo::cutRod(i, TestData::data), TestData::ans[i]) << "i is : " << i << std::endl;
    }
};
