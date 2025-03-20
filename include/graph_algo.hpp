#ifndef GRAPH_ALGO_H
#define GRAPH_ALGO_H

#include "graph.hpp"
#include <iostream>

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

#endif