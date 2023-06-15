//
// Created by GS65 on 11.06.2023.
//

#ifndef ALGORITHMS_PRIMSALGORITHM_H
#define ALGORITHMS_PRIMSALGORITHM_H
#include "../Utils/RandomGraph/RandomGraph.h"
#include <vector>

class PrimAlgorithm {
public:
    std::vector<std::pair<int, std::pair<int, int>>> computeAlgorithmMatrix(const std::vector<std::vector<int>> &graphMatrix);

    std::vector<std::pair<int, std::pair<int, int>>> computeAlgorithmList(const std::vector<std::list<std::pair<int, int>>> &graphList);

    std::vector<std::pair<int, std::pair<int, int>>>
    computeAlgorithmIncidentMatrix(const std::vector<std::vector<int>> &incidentMatrix);
};


#endif //ALGORITHMS_PRIMSALGORITHM_H
