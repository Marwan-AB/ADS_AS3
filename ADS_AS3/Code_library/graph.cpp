#include "graph.h"
#include <iostream>

int n, m;
std::vector<std::vector<std::pair<int,int>>> adjList;
std::vector<std::vector<int>> adjMatrix;

void readGraph(const std::string& filename) {
    freopen(filename.c_str(), "r", stdin);

    std::cin >> n >> m;
    adjList.assign(n, {});
    adjMatrix.assign(n, std::vector<int>(n, 1e9));

    for (int i = 0; i < n; i++)
        adjMatrix[i][i] = 0;

    int u, v, w;
    for (int i = 0; i < m; i++) {
        std::cin >> u >> v >> w;

        // adjacency list
        adjList[u].push_back({v, w});

        // adjacency matrix
        if (w < adjMatrix[u][v])
            adjMatrix[u][v] = w;
    }
}
