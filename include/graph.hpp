#ifndef GRAPH_H
#define GRAPH_H

#include "data.hpp"
#include <array>
#include <memory>
#include <vector>

class Graph {
  public:
    Graph(int V) : vertex(V), edges(0) {
        // can also use resize(), but this ensure V stays the same.
        adj = std::make_unique<std::vector<std::vector<int>>>(V);
    }

    int getVertex() { return vertex; }
    int getEdges() { return edges; }
    void resizeVertex(int V);
    void addEdge(int v, int w);

  private:
    int vertex;
    int edges;
    std::unique_ptr<std::vector<std::vector<int>>> adj;
};

#endif
