#ifndef GRAPH_ALGO_H
#define GRAPH_ALGO_H

#include "graph.hpp"
#include <algorithm>
#include <vector>
#include <stack>

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
    DepthFirstSearch(Graph &g_, int s_) : g(g_), s(s_), count(0) {
        marked.resize(g.getVertex());
        dfs(g, s);
    }
    DepthFirstSearch() = delete;
    bool isMarked(int w) { return marked[w]; }
    std::vector<bool> retMarked() { return marked; }
    int getCount() { return count; }
    bool isConnected(const int w) { return marked[w]; }

  private:
    Graph &g;
    std::vector<bool> marked;
    int s; // source
    int count;

    void dfs(Graph &g, int v);
};

class dfsPaths {
  public:
    dfsPaths(Graph &g_, int s_) : g(g_), s(s_) {
        marked.resize(g.getVertex());
        edgeTo.resize(g.getVertex());
        dfp(g, s);
    }
    bool isConnected(const int w) { return marked[w]; }
    std::vector<int> hasPathTo (const int v);

  private:
    Graph &g;
    std::vector<bool> marked;
    std::vector<int> edgeTo;
    int s; // source

    void dfp(Graph &g, int v);
};

#endif
