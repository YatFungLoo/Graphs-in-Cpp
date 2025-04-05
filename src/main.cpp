#include "graph.hpp"
#include "graph_algo.hpp"

int main(int argc, char *argv[]) {
    if (argc == 2) {
        Graph myGraph;
        myGraph.readFile(argv[1]);
        // Search mySearch(myGraph, 0);
        // DepthFirstSearch myDfs(myGraph, 0);
    }
    return 0;
}
