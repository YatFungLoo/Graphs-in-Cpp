#ifndef GRAPH_H
#define GRAPH_H

#include "data.hpp"
#include <algorithm>
#include <array>
#include <vector>

class Algo {
  public:
    [[maybe_unused]] static int cutRod(const int length, std::array<Rod, NUM_LENGTH> const &data);
};

#endif
