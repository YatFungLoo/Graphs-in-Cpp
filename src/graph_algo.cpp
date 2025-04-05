#include "graph_algo.hpp"

int Search::count() { return g.degree(s); }

bool Search::marked(const int &v) {
    // inconsistent results when using any_of.
    // return std::any_of(begin(g.iterEdges(v)), end(g.iterEdges(v)), [this](const int &v) { return v == this->s; });

    auto it = std::find_if(begin(g.getEdges(v)), end(g.getEdges(v)), [this](const auto &v) { return v == this->s; });
    return it != end(g.getEdges(v)) ? true : false;
}

void DepthFirstSearch::dfs(Graph &g, int v) {
    marked[v] = true;
    count++;
    const auto adj = g.getEdges(v);
    for (auto &w : adj) {
        if (!marked[w])
            dfs(g, w);
    }
}
