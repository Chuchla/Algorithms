//
// Created by GS65 on 11.06.2023.
//


#include "../Utils/RandomGraph/RandomGraph.h"
#include <vector>
#include <climits>
#include <queue>
#include "DijkstraAlgorithm.h"

    std::vector<int> DijkstraAlgorithm::computeAlgorithmMatrix(const std::vector<std::vector<int>> &graphMatrix, int sourceVertex) {
        std::vector<int> shortestPath(graphMatrix.size(), INT_MAX);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
        shortestPath[sourceVertex] = 0;
        minHeap.push({0, sourceVertex});
        while (!minHeap.empty()) {
            int u = minHeap.top().second;
            minHeap.pop();
            for (int v = 0; v < graphMatrix[u].size(); ++v) {
                if (graphMatrix[u][v] && shortestPath[u] != INT_MAX &&
                    shortestPath[u] + graphMatrix[u][v] < shortestPath[v]) {
                    shortestPath[v] = shortestPath[u] + graphMatrix[u][v];
                    minHeap.push({shortestPath[v], v});
                }
            }
        }
        return shortestPath;
    }

    std::vector<int>
    DijkstraAlgorithm::computeAlgorithmList(const std::vector<std::list<std::pair<int, int>>> &graphList, int sourceVertex) {
        std::vector<int> shortestPath(graphList.size(), INT_MAX);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
        shortestPath[sourceVertex] = 0;
        minHeap.push({0, sourceVertex});
        while (!minHeap.empty()) {
            int u = minHeap.top().second;
            minHeap.pop();
            for (auto &edge: graphList[u]) {
                int v = edge.first, weight = edge.second;
                if (shortestPath[u] != INT_MAX && shortestPath[u] + weight < shortestPath[v]) {
                    shortestPath[v] = shortestPath[u] + weight;
                    minHeap.push({shortestPath[v], v});
                }
            }
        }
        return shortestPath;
    }

