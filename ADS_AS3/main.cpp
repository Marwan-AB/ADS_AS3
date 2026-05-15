#include <iostream>
#include <chrono>
#include "graph.h"
#include "dijkstra.h"
#include "floyd.h"

using namespace std;

#include <filesystem>

std::string get_source_relative_path(const std::string& relative_file) {
    // __FILE__ is a macro that gives you the path to this source file
    std::filesystem::path source_path(__FILE__);

    // Get the directory of the current source file
    std::filesystem::path source_dir = source_path.parent_path();

    // Append the desired relative file
    std::filesystem::path full_path = source_dir / relative_file;

    return full_path.string();
}

bool equalMat(const vector<vector<int>>& A,
              const vector<vector<int>>& B)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] != B[i][j])
                return false;
    return true;
}

int main() {
    readGraph(get_source_relative_path("Code_library/graph.txt"));

    auto t1 = chrono::high_resolution_clock::now();
    auto d1 = repeatedDijkstra();
    auto t2 = chrono::high_resolution_clock::now();

    auto t3 = chrono::high_resolution_clock::now();
    auto f1 = floydWarshall();
    auto t4 = chrono::high_resolution_clock::now();

    cout << "Repeated Dijkstra time: "
         << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count()
         << " ms\n";

    cout << "Floyd-Warshall time: "
         << chrono::duration_cast<chrono::milliseconds>(t4 - t3).count()
         << " ms\n";

    cout << (equalMat(d1, f1) ? "MATCH\n" : "MISMATCH\n");
}
