//
// Created by GS65 on 11.06.2023.
//
#ifndef ALGORITHMS_BELLMANFORDALGORITHM_H
#define ALGORITHMS_BELLMANFORDALGORITHM_H
#include "../Utils/RandomGraph/RandomGraph.h"
#include <vector>

class BellmanFordAlgorithm {
public:


    std::pair<std::vector<int>, std::vector<int>>
    computeAlgorithmMatrix(const std::vector<std::vector<int>> &graphMatrix, int sourceVertex);

    std::pair<std::vector<int>, std::vector<int>>
    computeAlgorithmList(const std::vector<std::list<std::pair<int, int>>> &graphList, int sourceVertex);

    std::pair<std::vector<int>, std::vector<int>>
    computeAlgorithmIncidentMatrix(const std::vector<std::vector<int>> &incidentMatrixGraph, int sourceVertex);

};
#endif //ALGORITHMS_BELLMANFORDALGORITHM_H
