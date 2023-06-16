//
// Created by GS65 on 11.06.2023.
//


#include "../Utils/RandomGraph/RandomGraph.h"
#include <vector>
#include <climits>
#include <queue>
#include "DijkstraAlgorithm.h"

    std::pair<std::vector<int>,std::vector<int>> DijkstraAlgorithm::computeAlgorithmMatrix(const std::vector<std::vector<int>> &graphMatrix, int sourceVertex) {
        std::pair<std::vector<int>, std::vector<int>> pairReturn;
        if(graphMatrix.size()==0) return pairReturn;
        else {
            std::vector<int> shortestPath(graphMatrix.size(), INT_MAX);
            std::vector<int> parents(graphMatrix.size(), -1);
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
                        parents[v] = u;
                        minHeap.push({shortestPath[v], v});
                    }
                }
            }
            pairReturn.first = shortestPath;
            pairReturn.second = parents;
            return pairReturn;
        }
    }

std::pair<std::vector<int>,std::vector<int>>
    DijkstraAlgorithm::computeAlgorithmList(const std::vector<std::list<std::pair<int, int>>> &graphList, int sourceVertex) {
    std::pair<std::vector<int>,std::vector<int>> pairReturn;
    if(graphList.size() == 0) return pairReturn;
    else {
        std::vector<int> shortestPath(graphList.size(), INT_MAX);
        std::vector<int> parents(graphList.size(), -1);
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
                    parents[v] = u;
                    minHeap.push({shortestPath[v], v});
                }
            }
        }
        pairReturn.first = shortestPath;
        pairReturn.second = parents;
        return pairReturn;
    }
    }
std::pair<std::vector<int>,std::vector<int>> DijkstraAlgorithm::computeAlgorithmIncidentMatrix(const std::vector<std::vector<int>> &incidentMatrix, int sourceVertex){
    int vertices = incidentMatrix[0].size();
    std::pair<std::vector<int>,std::vector<int>> pairReturn;
    if(vertices == 0 ) return pairReturn;
    else {
        std::vector<int> parents(vertices, -1);
        std::vector<int> shortestPath(vertices, INT_MAX);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
        shortestPath[sourceVertex] = 0;
        minHeap.push({0, sourceVertex});

        while (!minHeap.empty()) {
            int u = minHeap.top().second;
            minHeap.pop();

            for (int i = 0; i < incidentMatrix.size() - 1; i++) {
                int edgeWeight = incidentMatrix[i][u];
                if (edgeWeight > 0) {
                    int v = -1; // find the other end of the edge
                    for (int j = 0; j < incidentMatrix[i].size(); ++j) {
                        if (j != u && incidentMatrix[i][j] != 0) {
                            v = j;
                            break;
                        }
                    }
                    if (v == -1) continue; // no other end found
                    if (shortestPath[u] + edgeWeight < shortestPath[v]) {
                        shortestPath[v] = shortestPath[u] + edgeWeight;
                        parents[v] = u;
                        minHeap.push({shortestPath[v], v});
                    }
                }
            }
        }
        pairReturn.first = shortestPath;
        pairReturn.second = parents;
        return pairReturn;
    }
}

