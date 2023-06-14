//
// Created by GS65 on 11.06.2023.
//

#ifndef ALGORITHMS_DIJKSTRAALGORITHM_H
#define ALGORITHMS_DIJKSTRAALGORITHM_H
#include "../Utils/RandomGraph/RandomGraph.h"
#include <vector>

class DijkstraAlgorithm {
public:

    std::vector<int> computeAlgorithmMatrix(const std::vector<std::vector<int>> &graphMatrix, int sourceVertex);

    std::vector<int>
    computeAlgorithmList(const std::vector<std::list<std::pair<int, int>>> &graphList, int sourceVertex);
};


#endif //ALGORITHMS_DIJKSTRAALGORITHM_H
