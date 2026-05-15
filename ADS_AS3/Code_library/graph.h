#pragma once
#include <vector>
#include <string>

extern int n, m;
extern std::vector<std::vector<std::pair<int,int>>> adjList;
extern std::vector<std::vector<int>> adjMatrix;

void readGraph(const std::string& filename);
