#include "graph.hpp"
#include "graph_algo.hpp"

int main(int argc, char *argv[]) {
    if (argc == 2) {
        Graph myGraph;
        myGraph.readFile(argv[1]);
        // Search mySearch(myGraph, 0);
        // DepthFirstSearch myDfs(myGraph, 0);
        dfsPaths myPaths(myGraph, 0);
        myPaths.isConnected(5) ? std::cout << "connected" : std::cout << "not connected";
        std::cout << "\n";
    }
    return 0;
}
