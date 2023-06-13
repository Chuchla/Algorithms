//
// Created by GS65 on 11.06.2023.
//

#ifndef ALGORITHMS_KRUSKALALGORITHM_H
#define ALGORITHMS_KRUSKALALGORITHM_H
#include "../Utils/RandomGraph/RandomGraph.h"
#include <vector>

class KruskalAlgorithm {
public:
    static std::vector<std::pair<int, int>> computeAlgorithmMatrix(RandomGraph& graph);
    static std::vector<std::pair<int, int>> computeAlgorithmList(RandomGraph& graph);

    std::vector<std::pair<int, std::pair<int, int>>>
    computeAlgorithmMatrix(const std::vector<std::vector<int>> &graphMatrix);

    std::vector<std::pair<int, std::pair<int, int>>>
    computeAlgorithmList(const std::vector<std::vector<std::pair<int, int>>> &graphList);

    std::vector<std::pair<int, std::pair<int, int>>>
    computeAlgorithmList(const std::vector<std::list<std::pair<int, int>>> &graphList);
};


#endif //ALGORITHMS_KRUSKALALGORITHM_H
