#include "graph.hpp"

int main(int argc, char *argv[]) {
    if (argc == 2) {
        Graph myGraph;
        myGraph.readFile(argv[1]);
    }
    return 0;
}
