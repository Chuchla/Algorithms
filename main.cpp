#include <iostream>
#include "Utils/RandomGraph/RandomGraph.h"
#include <memory>
#include "BellmanFord/BellmanFordAlgorithm.h"
#include "Dijkstra/DijkstraAlgorithm.h"
#include "Kruskal/KruskalAlgorithm.h"
#include "Prim/PrimsAlgorithm.h"
#include "Utils/Test/TestPerformer.h"
void printShortestDistances(const std::vector<int>& distances) {
    std::cout << "Shortest distances from source vertex 0:" << std::endl;
    for (int i = 0; i < distances.size(); ++i) {
        if(distances[i] == 2147483647) std::cout << "Vertex " << i << ": path does not exist (+oo)" << std::endl;
        else std::cout << "Vertex " << i << ": " << distances[i] << std::endl;
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

    shared_ptr<RandomGraph> randomGraph = make_shared<RandomGraph>(5);
    shared_ptr<RandomGraph> randomGraph2 = randomGraph;
    shared_ptr<RandomGraph> randomGraph1 = make_shared<RandomGraph>(10);

//    shared_ptr<BellmanFordAlgorithm> bellmanFordAlgorithm = make_shared<BellmanFordAlgorithm>();
//    shared_ptr<DijkstraAlgorithm>  dijkstraAlgorithm = make_shared<DijkstraAlgorithm>();
//    shared_ptr<KruskalAlgorithm> kruskalAlgorithm = make_shared<KruskalAlgorithm>();
//    shared_ptr<PrimAlgorithm> primAlgorithm = make_shared<PrimAlgorithm>();
//    randomGraph ->readGraphFromFileDirected("C:\\Users\\GS65\\CLionProjects\\Algorithms\\test");
//    randomGraph1 ->readGraphFromFileUndirected("C:\\Users\\GS65\\CLionProjects\\Algorithms\\test");
//    //randomGraph ->printGraphMatrix();
//    cout << endl;
//    randomGraph1 -> printGraphMatrix();
//    std::vector<std::pair<int, std::pair<int, int>>> result2 = kruskalAlgorithm->computeAlgorithmMatrix(randomGraph1->getMatrixGraph());
//    std::vector<std::pair<int, std::pair<int, int>>> result3 = kruskalAlgorithm->computeAlgorithmList(randomGraph1->getListGraph());
//    auto result5 = primAlgorithm ->computeAlgorithmMatrix(randomGraph1-> getMatrixGraph());
//    auto result6 = primAlgorithm ->computeAlgorithmList(randomGraph1 -> getListGraph());
//    //auto result1 = bellmanFordAlgorithm->computeAlgorithmMatrix(randomGraph->getMatrixGraph(),0);
//
//    printMinimumSpanningTree(result2);
//    printMinimumSpanningTree(result3);
//    printMinimumSpanningTree(result5);
//    printMinimumSpanningTree(result6);
//    cout << endl;*/
//    //printShortestDistances(result1);
//    unique_ptr<TestPerformer> testPerformer = make_unique<TestPerformer>();
//    /*testPerformer -> BellmanFordTest();
//    testPerformer -> DijkstraTest();
//    testPerformer -> KruskalTest();
//    testPerformer -> PrimTest();

        randomGraph ->GenerateGraphDirected(20);

        randomGraph ->printGraphIncidentMatrix();
    cout << endl;
        randomGraph ->printGraphMatrix();
        cout << endl;
        randomGraph ->printGraphList();
    return 0;
}
