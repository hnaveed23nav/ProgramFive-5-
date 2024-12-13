#include "WeightedGraph.h"

void WeightedGraph::addEdge(char u, char v, int weight) {
    adjList[u].push_back({v, weight});
}

void WeightedGraph::dfs(char start, std::vector<char>& path, int& cost) {
    std::stack<std::pair<char, int>> s;
    std::unordered_map<char, bool> visited;
    s.push({start, 0});

    while (!s.empty()) {
        auto [node, currentCost] = s.top();
        s.pop();
        if (!visited[node]) {
            visited[node] = true;
            path.push_back(node);
            cost += currentCost;
            for (auto it = adjList[node].rbegin(); it != adjList[node].rend(); ++it)
                s.push(*it);
        }
    }
}

void WeightedGraph::bfs(char start, std::vector<char>& path, int& cost) {
    std::queue<std::pair<char, int>> q;
    std::unordered_map<char, bool> visited;
    q.push({start, 0});

    while (!q.empty()) {
        auto [node, currentCost] = q.front();
        q.pop();
        if (!visited[node]) {
            visited[node] = true;
            path.push_back(node);
            cost += currentCost;
            for (auto& neighbor : adjList[node])
                q.push(neighbor);
        }
    }
}

bool WeightedGraph::isPath(char src, char dest, std::vector<char>& path, int& cost) {
    std::queue<std::pair<char, int>> q;
    std::unordered_map<char, char> parent;
    parent[src] = '\0';
    q.push({src, 0});

    while (!q.empty()) {
        auto [node, currentCost] = q.front();
        q.pop();
        if (node == dest) {
            for (char at = dest; at != '\0'; at = parent[at])
                path.push_back(at);
            std::reverse(path.begin(), path.end());
            cost = currentCost;
            return true;
        }
        for (auto& neighbor : adjList[node])
            if (!parent.count(neighbor.first))
                parent[neighbor.first] = node, q.push({neighbor.first, currentCost + neighbor.second});
    }
    return false;
}

