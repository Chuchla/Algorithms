#include <iostream>
#include "Utils/RandomGraph/RandomGraph.h"
#include <memory>
#include "BellmanFord/BellmanFordAlgorithm.h"
#include "Dijkstra/DijkstraAlgorithm.h"
#include "Kruskal/KruskalAlgorithm.h"
#include "Prim/PrimsAlgorithm.h"
#include "Utils/Test/TestPerformer.h"
#include <iomanip>
void printShortestDistances(const std::pair<std::vector<int>, std::vector<int>> &pair) {
    std::cout << "Shortest distances from source vertex 0:" << std::endl;
    for (int i = 0; i < pair.first.size(); ++i) {
        if(pair.first[i] == 2147483647) std::cout << "Vertex " << i << ": path does not exist (+oo)" << std::endl;
        else {
            std::cout << "Vertex " << std::setw(3)<<i << ": " << pair.first[i];
            if( pair.second[i] == -1) std::cout << "  source";
            else {
                std::cout << std::setw(3) << "V" <<pair.second[i];
                int parent = pair.second[i];
                while(parent > 0 ) {

                    std::cout << "<-V" << pair.second[parent];
                    parent = pair.second[parent];
                }
            }
            std::cout << std::endl;
        }
    }
}
void printMinimumSpanningTree(const std::vector<std::pair<int, std::pair<int, int>>>& mst) {
    std::cout << "Minimum Spanning Tree:" << std::endl;
    for (const auto& edge : mst) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        std::cout << "Edge (" << u << " - " << v << ") with weight " << weight << std::endl;
    }
}

int main() {
    using namespace std;

    return 0;
}
