#include "graph.hpp"

void Graph::resizeVertex(int V) {
    (*adj).resize(V);
    vertex = V;
}

/**
 * @brief Add edge pair to graph.
 *
 * @param v First vertex.
 * @param w Second vertex.
 */
void Graph::addEdge(int v, int w) {
    (*adj)[v].push_back(w);
    (*adj)[w].push_back(v);
    edges++;
}

/**
 * @brief Delete edge pair using edgeExistChecker(), delete on both vectors.
 *
 * @param v First vertex.
 * @param w Second vertex.
 */
void Graph::deleteEdge(int v, int w) {
    auto i = edgeExistChecker(v, w, true);
    if (!i)
        std::cout << "Edge " << v << "-" << w << " not deleted, pair not found." << std::endl;
}

/**
 * @brief Helper function to check if an edge pair exist.
 *
 * @param v First vertex.
 * @param w Second vertex.
 */
void Graph::doesEdgeExist(int v, int w) {
    if (edgeExistChecker(v, w, false)) {
        std::cout << "Edge " << v << "-" << w << " found." << std::endl;
    } else {
        std::cout << "Edge " << v << "-" << w << " not found." << std::endl;
    }
}

/**
 * @brief Two way check for edge pair.
 *
 * @param v first vertex.
 * @param w Second vertex.
 * @param del True delete if pair exist, false otherwise.
 *
 * @return True if pair found, false otherwise.
 */
bool Graph::edgeExistChecker(int v, int w, bool del) {
    auto &adj_ref = *adj;
    auto it_v = std::find_if(adj_ref[v].begin(), adj_ref[v].end(), [w](const int W) { return W == w; });
    auto it_w = std::find_if(adj_ref[w].begin(), adj_ref[w].end(), [v](const int V) { return V == v; });
    if (it_v != adj_ref[v].end() && it_w != adj_ref[w].end()) {
        if (del == true) {
            adj_ref[v].erase(it_v);
            adj_ref[w].erase(it_w);
        }
        return true;
    } else {
        return false;
    }
}

/**
 * @brief print all edges of a vertex.
 *
 * @param v Vertex id.
 */
void Graph::printIterEdges(int v) {
    if ((*adj)[v].empty()) {
        std::cout << "No edges are connected to this vertex." << std::endl;
    } else {
        auto first = begin((*adj)[v]);
        auto last = end((*adj)[v]);
        while (first != last) {
            std::cout << *first++;
            if (first != last)
                std::cout << ", ";
        }
        std::cout << std::endl;
    }
}

/**
 * @brief return edges of given vertex.
 *
 * @param v vertex
 * @return std::vector<int> ret
 */
std::vector<int> Graph::iterEdges(int v) {
    std::vector<int> ret;
    for (auto &i : (*adj)[v])
        ret.push_back(i);
    return ret;
}