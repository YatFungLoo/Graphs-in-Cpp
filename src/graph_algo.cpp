#include "graph_algo.hpp"

int Search::count() { return g.degree(s); }

bool Search::marked(const int &v) {
    return std::any_of(begin(g.getEdges(v)), end(g.getEdges(v)), [this](const auto &w) { return w == this->s; });
    // auto it = std::find_if(begin(g.getEdges(v)), end(g.getEdges(v)), [this](const auto &w) { return w == this->s; });
    // return it != end(g.getEdges(v));
}

void DepthFirstSearch::dfs(Graph &g, const int v) {
    marked[v] = true;
    count++;
    const auto adj = g.getEdges(v);
    for (auto &w : adj) {
        if (!marked[w])
            dfs(g, w);
    }
}

void dfsPaths::dfp(Graph &g, int v) {
    marked[v] = true;
    const auto adj = g.getEdges(v);
    for (auto &w : adj) {
        if (!marked[w]) {
            edgeTo[w] = v;
            dfp(g, w);
        }
    }
}

std::vector<int> dfsPaths::hasPathTo(const int v) {
    if (!isConnected(v))
        return {};
    // std::stack<int>;
    return {};
}
