#ifndef ALGO_TEST_H
#define ALGO_TEST_H

#include "data.hpp"
#include <array>

class TestData {
  public:
    static constexpr std::array<Rod, NUM_LENGTH> data{{
        // Price table.
        {0, 0},
        {1, 1},
        {2, 5},
        {3, 8},
        {4, 9},
        {5, 10},
        {6, 17},
        {7, 17},
        {8, 20},
        {9, 24},
        {10, 30},
    }};

    // Note to self: directly initialisation of a static const std:vector inside a class definition is not allowed
    // because it is dynamically allocated
    static constexpr std::array<int, NUM_LENGTH> ans{0, 1, 5, 8, 10, 13, 17, 18, 22, 25, 30};

    static constexpr std::array<int, 11> fib_ans{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
};

#endif