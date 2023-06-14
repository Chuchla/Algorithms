//
// Created by GS65 on 11.06.2023.
//

#ifndef ALGORITHMS_TESTPERFORMER_H
#define ALGORITHMS_TESTPERFORMER_H


#include <vector>
#include <string>

class TestPerformer {
    double calculateAverage(std::vector<long> *elements);

    static const int TEST_REPEATS;

    static const std::vector<int> RANGES;
    static const std::vector<int> DENSITY;
public:
    void BellmanFordTest();

    void DijkstraTest();

    void KruskalTest();

    void PrimTest();

    void writeArrayToCsvFile(std::vector<double> *results, std::string fileName, std::vector<std::string> &headers);
};


#endif //ALGORITHMS_TESTPERFORMER_H
