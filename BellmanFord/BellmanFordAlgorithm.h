//
// Created by GS65 on 11.06.2023.
//
#ifndef ALGORITHMS_BELLMANFORDALGORITHM_H
#define ALGORITHMS_BELLMANFORDALGORITHM_H
#include "../Utils/RandomGraph/RandomGraph.h"
#include <vector>

class BellmanFordAlgorithm {
public:
    static std::vector<int> computeAlgorithmMatrix(RandomGraph& graph, int sourceVertex);
    static std::vector<int> computeAlgorithmList(RandomGraph& graph, int sourceVertex);

    std::vector<int> computeAlgorithmMatrix(std::vector<std::vector<int>> &graphMatrix, int sourceVertex);

    std::vector<int> computeAlgorithmList(std::vector<std::vector<std::pair<int, int>>> &graphList, int sourceVertex);

    std::vector<int> computeAlgorithmMatrix(const std::vector<std::vector<int>> &graphMatrix, int sourceVertex);

    std::vector<int>
    computeAlgorithmList(const std::vector<std::vector<std::pair<int, int>>> &graphList, int sourceVertex);

    std::vector<int>
    computeAlgorithmList(const std::vector<std::list<std::pair<int, int>>> &graphList, int sourceVertex);
};
#endif //ALGORITHMS_BELLMANFORDALGORITHM_H
