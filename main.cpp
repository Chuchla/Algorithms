#include <iostream>
#include "Utils/RandomGraph/RandomGraph.h"
#include <memory>

int main() {
    using namespace std;
    unique_ptr<RandomGraph> randomGraph = make_unique<RandomGraph>(10);
    randomGraph ->GenerateGraphUndirected(100);
    randomGraph ->printGraphList();
    randomGraph ->printGraphMatrix();
    return 0;
}
