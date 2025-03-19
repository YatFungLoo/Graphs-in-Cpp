#include "graph_algo.hpp"

int Search::count() { return g.degree(s); }
bool Search::marked(const int &v) {
    std::vector<int> v_edges = g.iterEdges(v);
    auto it = std::find_if(v_edges.begin(), v_edges.end(), [this](const int &v) { return v == this->s; });
    if (it != v_edges.end()) {
        return true;
    } else {
        return false;
    }
}