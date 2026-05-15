#include <gtest/gtest.h>
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


// helper to set stdin from a file
void loadGraph() {
    readGraph(get_source_relative_path("../Code_library/graph.txt"));
}

TEST(GraphLoadTest, LoadsCorrectNodeEdgeCount) {
    loadGraph();
    EXPECT_EQ(n, 100);
    EXPECT_EQ(m, 9900);
}

TEST(DijkstraTest, SingleSource) {
    loadGraph();

    auto d = dijkstra(0);

    // expected shortest distances from node 0
    vector<int> expected = {0, 2, 2, 3, 2, 2, 2, 3, 2, 2, 3, 2, 3, 3, 2, 1, 2, 1, 3, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 3, 3, 2, 2, 2, 3, 3, 2, 2, 1, 3, 3, 2, 3, 2, 1, 2, 3, 2, 3, 3, 2, 2, 3, 3, 3, 2, 1, 3, 3, 2, 2, 2, 2, 2, 3, 3, 2, 3, 2, 3, 2, 3, 2, 3, 3, 2, 3, 1, 2, 3, 2, 3, 3, 3, 2, 2, 3, 3, 2, 2, 2, 2, 3, 2, 2, 3, 3, 2, 2};
    
    EXPECT_EQ(d.size(), expected.size());
    EXPECT_EQ(d, expected);
}

TEST(CompareAlgorithms, DijkstraVsFloyd) {
    loadGraph();

    auto d = repeatedDijkstra();
    auto f = floydWarshall();

    EXPECT_EQ(d, f);
}

