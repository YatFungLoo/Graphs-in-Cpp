#include "graph.hpp"

// @brief Recursive top-down implementation, return maximum price of rod input length.
[[maybe_unused]] int Algo::cutRod(const int length, std::array<Rod, NUM_LENGTH> const &data) {
    if (length == 0) {
        return 0;
    }

    int price = 0;
    for (int i = 1; i <= length; i++) {
        price = std::max(price, (data[i].price + cutRod(length - i, data)));
    }

    return price;
}
