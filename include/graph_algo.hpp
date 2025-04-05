#ifndef GRAPH_ALGO_H
#define GRAPH_ALGO_H

#include "graph.hpp"
#include <algorithm>
#include <vector>

class Search {
  public:
    Search(Graph &g_, int s_) : g(g_), s(s_) {}
    Search() = delete;
    int count();
    bool marked(const int &v);

  private:
    Graph &g;
    int s; // source
};

// @brief Recursive method for searching in a connected graph, visiting all vertices and edges.
class DepthFirstSearch {
  public:
    DepthFirstSearch(Graph &g_, int v) : g(g_), count(0) {
        marked.resize(g.getVertex());
        dfs(g, v);
    }
    DepthFirstSearch() = delete;
    bool isMarked(int w) { return marked[w]; }
    std::vector<bool> retMarked() { return marked; }
    int getCount() { return count; }

  private:
    Graph &g;
    std::vector<bool> marked;
    int count;

    void dfs(Graph &g, int v);
};

#endif
