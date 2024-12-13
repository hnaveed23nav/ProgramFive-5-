#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>

class WeightedGraph {
private:
    std::unordered_map<char, std::vector<std::pair<char, int>>> adjList;
public:
    void addEdge(char u, char v, int weight);
    void dfs(char start, std::vector<char>& path, int& cost);
    void bfs(char start, std::vector<char>& path, int& cost);
    bool isPath(char src, char dest, std::vector<char>& path, int& cost);
};

#endif

