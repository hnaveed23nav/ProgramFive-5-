#include "WeightedGraph.h"

int main() {
    WeightedGraph graph;

    graph.addEdge('A', 'B', 10);
    graph.addEdge('A', 'C', 12);
    graph.addEdge('A', 'D', 60);
    graph.addEdge('B', 'C', 20);
    graph.addEdge('C', 'D', 32);
    graph.addEdge('E', 'A', 7);

    std::vector<char> path;
    int cost = 0;

    // DFS from E
    graph.dfs('E', path, cost);
    std::cout << "DFS: ";
    for (char c : path) std::cout << c << " ";
    std::cout << "\nCost: " << cost << "\n";

    // BFS from E
    path.clear();
    cost = 0;
    graph.bfs('E', path, cost);
    std::cout << "BFS: ";
    for (char c : path) std::cout << c << " ";
    std::cout << "\nCost: " << cost << "\n";

    // Path from E to D
    path.clear();
    cost = 0;
    if (graph.isPath('E', 'D', path, cost)) {
        std::cout << "Path E to D: ";
        for (char c : path) std::cout << c << " ";
        std::cout << "\nCost: " << cost << "\n";
    } else {
        std::cout << "No path from E to D\n";
    }

    return 0;
}

