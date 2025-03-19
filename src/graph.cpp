#include "graph.hpp"

/**
 * @brief Convert input string into int and return the value with try catch.
 *
 * @param line input string
 * @return int conveted from input string
 */
int Graph::string2int(const std::string &line) {
    std::size_t pos{};
    try {
        const int ret{std::stoi(line, &pos)};
        return ret;
    } catch (std::invalid_argument const &ex) {
        std::cout << "std::invalid_argument::what(): " << ex.what() << '\n';
    } catch (std::out_of_range const &ex) {
        std::cout << "std::out_of_range::what(): " << ex.what() << '\n';
        const long long ll{std::stoll(line, &pos)};
        std::cout << "std::stoll(" << std::quoted(line) << "): " << ll << "; pos: " << pos << '\n';
    }
    return EPERM;
}

/**
 * @brief take input string and return first two int.
 *
 * @param line
 * @return std::vector
 */
std::vector<int> Graph::string2vector(const std::string &line) {
    std::stringstream ss(line);
    auto start = std::istream_iterator<int>{ss};
    auto end = std::istream_iterator<int>{};
    // Note: this is new to me, remember this!!!
    std::vector<int> ret(start, end);
    return ret;
}

/**
 * @brief read text file and add to graph object called.
 *
 * @param filename
 */
void Graph::readFile(char *filename) {
    // open file for reading
    std::ifstream istrm(filename, std::ios::binary);
    std::string line;
    if (!istrm.is_open())
        std::cout << "failed to open " << filename << '\n';
    else {
        // first line: number of vertice(s)
        std::getline(istrm, line);
        vertex = string2int(line);
        resizeVertex(vertex);
        // second line: number of edge(s)
        std::getline(istrm, line);
        edges = string2int(line);
        // rest of the lines: edge pairs
        int e_checker = 0; // For verifying user provided number of edge(s)
        while (std::getline(istrm, line)) {
            std::vector<int> e = string2vector(line);
            if (e[0] > vertex || e[1] > vertex) {
                throw std::invalid_argument("Vertex larger than specified.");
            }
            (*adj)[e[0]].push_back(e[1]);
            (*adj)[e[1]].push_back(e[0]);
            e_checker++;
        }
        if (edges != e_checker)
            std::cerr << "Warning: Provided number of edges does not match self counted edges." << std::endl;
    }
    istrm.close();
}

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
    auto it_v = std::find_if(adj_ref[v].begin(), adj_ref[v].end(), [w](const int &W) { return W == w; });
    auto it_w = std::find_if(adj_ref[w].begin(), adj_ref[w].end(), [v](const int &V) { return V == v; });
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
 * @brief return maximum degree of the graph.
 *
 * @return int
 */
int Graph::maxDegree() {
    int max = 0;
    int size = (*adj).size();
    for (int i = 0; i < size; i++) {
        max = std::max(degree(i), max);
    }
    return max;
}

/**
 * @brief return number of self loops in the graph.
 *
 * @return int
 */
int Graph::selfLoop() {
    int sl = 0; // self loop count
    for (int v = 0; v < vertex; v++) {
        for (auto &w : (*adj)[v]) {
            if (v == w)
                sl++;
        }
    }
    return sl / 2;
}