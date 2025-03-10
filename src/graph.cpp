#include "graph.hpp"

void Graph::resizeVertex(int V) {}

// @brief Add a single edge pair to the adj list.
void Graph::addEdge(int v, int w) {
    (*adj)[v].push_back(w);
    (*adj)[w].push_back(v);
    edges++;
}
