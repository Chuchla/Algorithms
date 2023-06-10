#include <iostream>
#include "Utils/RandomGraph/RandomGraph.h"
#include <memory>

int main() {
    using namespace std;
    unique_ptr<RandomGraph> randomGraph = make_unique<RandomGraph>();
    vector<vector<int>> graph = randomGraph ->GenerateUndirectedGraph(10,10);
    randomGraph ->printGraph(graph);

    return 0;
}
