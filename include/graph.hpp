#ifndef GRAPH_H
#define GRAPH_H

#include "data.hpp"
#include <algorithm>
#include <array>
#include <errno.h>
#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <vector>

class Graph {
  public:
    Graph() : vertex(0), edges(0) { adj = std::make_unique<std::vector<std::vector<int>>>(0); }
    Graph(int V) : vertex(V), edges(0) {
        // can also use resize(), but this ensure V stays the same.
        adj = std::make_unique<std::vector<std::vector<int>>>(vertex);
    }

    // @brief Return number of vertex(s).
    int getVertex() { return vertex; }
    // @brief Return number of edges.
    int getEdges() { return edges; }
    void readFile(char *filename);
    void resizeVertex(int V);
    void addEdge(int v, int w);
    void deleteEdge(int v, int w);
    void doesEdgeExist(int v, int w);
    void printIterEdges(int v);
    const std::vector<int> iterEdges(int v) { return (*adj)[v]; }
    int degree(int v) { return (*adj)[v].size(); }
    int maxDegree();
    // 2 times due to each edge connected to two vertices.
    int avgDegree() { return (2 * edges) / vertex; }
    int selfLoop();

  private:
    int vertex;
    int edges;
    // Shared for used in search and additional algorithm class.
    std::shared_ptr<std::vector<std::vector<int>>> adj;

    bool edgeExistChecker(int v, int w, bool del);
    int string2int(const std::string &line);
    std::vector<int> string2vector(const std::string &line);
};

#endif
