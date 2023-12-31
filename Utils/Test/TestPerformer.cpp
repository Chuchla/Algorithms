//
// Created by GS65 on 11.06.2023.
//

#include "TestPerformer.h"
#include <chrono>
#include <iostream>
#include "../RandomGraph/RandomGraph.h"
#include <memory>
#include "../../BellmanFord/BellmanFordAlgorithm.h"
#include "../../Dijkstra/DijkstraAlgorithm.h"
#include "../../Kruskal/KruskalAlgorithm.h"
#include "../../Prim/PrimsAlgorithm.h"
#include <random>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
using namespace std::chrono;
const vector<int> TestPerformer::RANGES(
        {100}
);
const vector<int> TestPerformer::DENSITY(
        {3100}
        );

const int TestPerformer::TEST_REPEATS = 1;

double TestPerformer::calculateAverage(std::vector<long> *elements) {
    double total = .0;
    int n = 0;
    for (long element: *elements) {
        total += (double) element;
        n++;
    }
    return total / (double) n;
}
void TestPerformer::writeArrayToCsvFile(std::vector<double> *results, std::string fileName, std::vector<std::string> &headers) {
    using namespace std;
    string csv = "";
    fstream file;
    file.open(fileName, ios::out);
    for (int i = 0; i < headers.size(); i++) {
        string &header = headers.at(i);
        for(auto density : DENSITY){
            csv += header + " " + std::to_string(density) + ",";
        }
    }

    csv += "\n";
    for (int i = 0; i < headers.size(); i++) {
        for (auto density : DENSITY) {
            csv += headers.at(i) + " " + std::to_string(density) + "%:";
        }
    }
    csv += "\n";
    for (int i = 0; i < results->size(); i++) {
        string result = std::to_string(results->at(i));
        csv += i == results->size() - 1 ?  result : result + ",";
    }
    csv += "\n";
    file << csv;
}

void TestPerformer::BellmanFordTest() {
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }

    std::vector<double> testResultsMatrix;
    std::vector<double> testResultsList;
    std::vector<double> testResultIncidentMatrix;
    unique_ptr<BellmanFordAlgorithm> bellmanFordAlgorithm = make_unique<BellmanFordAlgorithm>();
    for (int size: RANGES) {
        for(int density: DENSITY){
            cout << "BellmanFord Test (" << size << ", " << density << "%)"  << endl;
            std::vector<long> measuredTimesMatrix;
            std::vector<long> measuredTimesList;
            std::vector<long> measuredTimesIncidentMatrix;
            for (int i = 0; i < TEST_REPEATS; i++) {
                unique_ptr<RandomGraph> randomGraph = make_unique<RandomGraph>(size);
                randomGraph ->GenerateGraphDirected(size,density);
                auto start = high_resolution_clock::now();
                bellmanFordAlgorithm ->computeAlgorithmMatrix(randomGraph -> getMatrixGraph(),0);
                auto mid = high_resolution_clock::now();
                bellmanFordAlgorithm ->computeAlgorithmList(randomGraph -> getListGraph(), 0);
                auto secondMid = high_resolution_clock::now();
                bellmanFordAlgorithm ->computeAlgorithmIncidentMatrix(randomGraph -> getIncidentMatrixGraph(),0);
                auto end = high_resolution_clock::now();
                auto durationMatrix = duration_cast<microseconds>(mid - start);
                auto durationList = duration_cast<microseconds>(secondMid - mid);
                auto durationIncidentMatrix = duration_cast<microseconds>(end-secondMid);
                long timeMatrix = durationMatrix.count();
                long timeList = durationList.count();
                long timeIncidentMatrix = durationIncidentMatrix.count();
                measuredTimesMatrix.push_back(timeMatrix);
                measuredTimesList.push_back(timeList);
                measuredTimesIncidentMatrix.push_back(timeIncidentMatrix);
            }
            double resultMatrix = calculateAverage(&measuredTimesMatrix);
            double resultList = calculateAverage(&measuredTimesList);
            double resultIncidentMatrix = calculateAverage(&measuredTimesIncidentMatrix);
            testResultsMatrix.push_back(resultMatrix);
            testResultsList.push_back(resultList);
            testResultIncidentMatrix.push_back(resultIncidentMatrix);
        }

    }

    writeArrayToCsvFile(&testResultsMatrix,
                                    "BellmanFordMatrix.csv",
                                    headers
    );
    writeArrayToCsvFile(&testResultsList,
                        "BellmanFordList.csv",
                        headers
    );
    writeArrayToCsvFile(&testResultIncidentMatrix,
                          "BellmanFordIncidentMatrix.csv",
                          headers
    );

}

void TestPerformer::DijkstraTest() {
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    std::vector<double> testResultsMatrix;
    std::vector<double> testResultsList;
    std::vector<double> testResultIncidentMatrix;
    unique_ptr<DijkstraAlgorithm> dijkstraAlgorithm = make_unique<DijkstraAlgorithm>();
    for (int size: RANGES) {
        for (int density: DENSITY) {
            cout << "Dijkstra Test (" << size << ", " << density << "%)" << endl;
            std::vector<long> measuredTimesMatrix;
            std::vector<long> measuredTimesList;
            std::vector<long> measuredTimesIncidentMatrix;
            for (int i = 0; i < TEST_REPEATS; i++) {
                unique_ptr<RandomGraph> randomGraph = make_unique<RandomGraph>(size);

                randomGraph->GenerateGraphDirected(size, density);
                auto start = high_resolution_clock::now();
                dijkstraAlgorithm->computeAlgorithmMatrix(randomGraph->getMatrixGraph(), 0);
                auto mid = high_resolution_clock::now();
                dijkstraAlgorithm->computeAlgorithmList(randomGraph->getListGraph(), 0);
                auto secondMid = high_resolution_clock::now();
                dijkstraAlgorithm->computeAlgorithmIncidentMatrix(randomGraph->getIncidentMatrixGraph(), 0);
                auto end = high_resolution_clock::now();
                auto durationMatrix = duration_cast<microseconds>(mid - start);
                auto durationList = duration_cast<microseconds>(secondMid - mid);
                auto durationIncidentMatrix = duration_cast<microseconds>(end - secondMid);
                long timeMatrix = durationMatrix.count();
                long timeList = durationList.count();
                long timeIncidentMatrix = durationIncidentMatrix.count();
                measuredTimesMatrix.push_back(timeMatrix);
                measuredTimesList.push_back(timeList);
                measuredTimesIncidentMatrix.push_back(timeIncidentMatrix);
            }
            double resultMatrix = calculateAverage(&measuredTimesMatrix);
            double resultList = calculateAverage(&measuredTimesList);
            double resultIncidentMatrix = calculateAverage(&measuredTimesIncidentMatrix);
            testResultsMatrix.push_back(resultMatrix);
            testResultsList.push_back(resultList);
            testResultIncidentMatrix.push_back(resultIncidentMatrix);

        }

        writeArrayToCsvFile(&testResultsMatrix,
                            "DijkstraMatrix.csv",
                            headers
        );
        writeArrayToCsvFile(&testResultsList,
                            "DijkstraList.csv",
                            headers
        );
        writeArrayToCsvFile(&testResultIncidentMatrix,
                            "DijkstraIncidentMatrix.csv",
                            headers
        );

    }
}
void TestPerformer::KruskalTest() {
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    std::vector<double> testResultsMatrix;
    std::vector<double> testResultsList;
    std::vector<double> testResultIncidentMatrix;
    unique_ptr<KruskalAlgorithm> kruskalAlgorithm = make_unique<KruskalAlgorithm>();
    for (int size: RANGES) {
        for (int density: DENSITY) {
            cout << "Kruskal Test (" << size << ", " << density << "%)" << endl;
            std::vector<long> measuredTimesMatrix;
            std::vector<long> measuredTimesList;
            std::vector<long> measuredTimesIncidentMatrix;
            for (int i = 0; i < TEST_REPEATS; i++) {
                unique_ptr<RandomGraph> randomGraph = make_unique<RandomGraph>(size);
                randomGraph->GenerateGraphUndirected(size, density);
                auto start = high_resolution_clock::now();
                kruskalAlgorithm->computeAlgorithmMatrix(randomGraph->getMatrixGraph());
                auto mid = high_resolution_clock::now();
                kruskalAlgorithm->computeAlgorithmList(randomGraph->getListGraph());
                auto secondMid = high_resolution_clock::now();
                kruskalAlgorithm->computeAlgorithmIncidentMatrix(randomGraph->getIncidentMatrixGraph());
                auto end = high_resolution_clock::now();

                auto durationMatrix = duration_cast<microseconds>(mid - start);
                auto durationList = duration_cast<microseconds>(secondMid - mid);
                auto durationIncidentMatrix = duration_cast<microseconds>(end - secondMid);
                long timeMatrix = durationMatrix.count();
                long timeList = durationList.count();
                long timeIncidentMatrix = durationIncidentMatrix.count();
                measuredTimesMatrix.push_back(timeMatrix);
                measuredTimesList.push_back(timeList);
                measuredTimesIncidentMatrix.push_back(timeIncidentMatrix);
            }
            double resultMatrix = calculateAverage(&measuredTimesMatrix);
            double resultList = calculateAverage(&measuredTimesList);
            double resultIncidentMatrix = calculateAverage(&measuredTimesIncidentMatrix);
            testResultsMatrix.push_back(resultMatrix);
            testResultsList.push_back(resultList);
            testResultIncidentMatrix.push_back(resultIncidentMatrix);

            writeArrayToCsvFile(&testResultsMatrix,
                                "KruskalMatrix.csv",
                                headers
            );
            writeArrayToCsvFile(&testResultsList,
                                "KruskalList.csv",
                                headers
            );
            writeArrayToCsvFile(&testResultIncidentMatrix,
                                  "KruskalIncidentMatrix.csv",
                                  headers
            );

        }
    }
}
void TestPerformer::PrimTest() {
    std::vector<std::string> headers;
    for (const auto &item: RANGES) {
        headers.push_back(std::to_string(item));
    }
    std::vector<double> testResultsMatrix;
    std::vector<double> testResultsList;
    std::vector<double> testResultIncidentMatrix;
    unique_ptr<PrimAlgorithm> primAlgorithm = make_unique<PrimAlgorithm>();
    for (int size: RANGES) {
        for(int density: DENSITY) {
            cout << "Prim Test (" << size << ", " << density << "%)" << endl;
            std::vector<long> measuredTimesMatrix;
            std::vector<long> measuredTimesList;
            std::vector<long> measuredTimesIncidentMatrix;
            for (int i = 0; i < TEST_REPEATS; i++) {
                unique_ptr<RandomGraph> randomGraph = make_unique<RandomGraph>(size);
                randomGraph->GenerateGraphUndirected(size, density);
                auto start = high_resolution_clock::now();
                primAlgorithm->computeAlgorithmMatrix(randomGraph->getMatrixGraph());
                auto mid = high_resolution_clock::now();
                primAlgorithm->computeAlgorithmList(randomGraph->getListGraph());
                auto secondMid = high_resolution_clock::now();
                primAlgorithm ->computeAlgorithmIncidentMatrix(randomGraph -> getIncidentMatrixGraph());
                auto end = high_resolution_clock::now();
                auto durationMatrix = duration_cast<microseconds>(mid - start);
                auto durationList = duration_cast<microseconds>(secondMid - mid);
                auto durationIncidentMatrix = duration_cast<microseconds>(end - secondMid);
                long timeMatrix = durationMatrix.count();
                long timeList = durationList.count();
                long timeIncidentMatrix = durationIncidentMatrix.count();
                measuredTimesMatrix.push_back(timeMatrix);
                measuredTimesList.push_back(timeList);
                measuredTimesIncidentMatrix.push_back(timeIncidentMatrix);
            }
            double resultMatrix = calculateAverage(&measuredTimesMatrix);
            double resultList = calculateAverage(&measuredTimesList);
            double resultIncidentMatrix = calculateAverage(&measuredTimesIncidentMatrix);
            testResultsMatrix.push_back(resultMatrix);
            testResultsList.push_back(resultList);
            testResultIncidentMatrix.push_back(resultIncidentMatrix);
        }
    }

    writeArrayToCsvFile(&testResultsMatrix,
                        "PrimMatrix.csv",
                        headers
    );
    writeArrayToCsvFile(&testResultsList,
                        "PrimList.csv",
                        headers
    );
    writeArrayToCsvFile(&testResultIncidentMatrix,
                        "PrimIncidentMatrix.csv",
                        headers
    );

}
