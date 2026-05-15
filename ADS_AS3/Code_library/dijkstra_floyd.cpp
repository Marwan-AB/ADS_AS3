/********************************************************************************
* WARNING: Please do not remove or modify this comment block.
 *
 * Student Information:
 * Name: Marwan Aboelnour
 * Student ID: 900233384
 * Section Number: 01
 * Instructions:
 * - Fill out your name, student ID, and section number above.
 * - This information is mandatory for the submission of your assignment.
 * - Do not modify this file beyond the specified tasks and guidelines.
 *
 ********************************************************************************/

#include "dijkstra.h"
#include "floyd.h"
#include "graph.h"
#include <vector>
#include <queue>

using namespace std;

vector<int> dijkstra(int src) {
    // Initialize all distances to "infinity"
    const int INF = 1e9;
    vector<int> dist(n, INF);
 
    // Min-heap: (distance, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
 
    // Source node has distance 0
    dist[src] = 0;
    pq.push({0, src});
 
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
 
        // Skip if we already found a shorter path to u
        if (d > dist[u])
            continue;
 
        // Relax all neighbours of u
        for (auto [v, w] : adjList[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
 
    return dist;
}
 
// Run Dijkstra from every node to build the All-Pairs Shortest Path matrix.
// Time complexity: O(V * (V + E) log V)
vector<vector<int>> repeatedDijkstra() {
    vector<vector<int>> all(n, vector<int>(n));
 
    for (int i = 0; i < n; i++)
        all[i] = dijkstra(i);   // row i = shortest distances from node i
 
    return all;
}
 
// Floyd-Warshall All-Pairs Shortest Path.
// Uses dynamic programming with the adjacency matrix as the starting point.
// Time complexity: O(V^3)
vector<vector<int>> floydWarshall() {
    const int INF = 1e9;
 
    // Start with a copy of the adjacency matrix
    // adjMatrix already has: 0 on diagonal, edge weights, INF where no edge
    vector<vector<int>> dist = adjMatrix;
 
    // For each intermediate node k, relax all (i, j) pairs
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            // Skip if i can't even reach k
            if (dist[i][k] == INF)
                continue;
            for (int j = 0; j < n; j++) {
                if (dist[k][j] == INF)
                    continue;
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    return dist;
}
