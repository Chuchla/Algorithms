//
// Created by GS65 on 11.06.2023.
//

#include "../Utils/RandomGraph/RandomGraph.h"
#include "BellmanFordAlgorithm.h"
#include <vector>
#include <climits>
#include <iostream>

std::vector<int>
BellmanFordAlgorithm::computeAlgorithmMatrix(const std::vector<std::vector<int>> &graphMatrix, int sourceVertex) {
    int vertices = graphMatrix.size();
    std::vector<int> distance(vertices, INT_MAX);
    distance[sourceVertex] = 0;

    for (int i = 1; i <= vertices - 1; ++i) {
        for (int u = 0; u < vertices; ++u) {
            for (int v = 0; v < vertices; ++v) {
                if (graphMatrix[u][v] && distance[u] != INT_MAX && distance[u] + graphMatrix[u][v] < distance[v])
                    distance[v] = distance[u] + graphMatrix[u][v];
            }
        }
    }

    // Sprawdzenie cykli o ujemnej wadze
    for (int u = 0; u < vertices; ++u) {
        for (int v = 0; v < vertices; ++v) {
            if (graphMatrix[u][v] && distance[u] != INT_MAX && distance[u] + graphMatrix[u][v] < distance[v]) {
                std::cout << "Graph contains a negative-weight cycle." << std::endl;
                return {};
            }
        }
    }

    return distance;
}

std::vector<int>
BellmanFordAlgorithm::computeAlgorithmList(const std::vector<std::list<std::pair<int, int>>> &graphList, int sourceVertex) {
    int vertices = graphList.size();
    std::vector<int> distance(vertices, INT_MAX);
    distance[sourceVertex] = 0;

    for (int i = 1; i <= vertices - 1; ++i) {
        for (int u = 0; u < vertices; ++u) {
            for (auto &edge: graphList[u]) {
                int v = edge.first, weight = edge.second;
                if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                    distance[v] = distance[u] + weight;
            }
        }
    }

    // Sprawdzenie cykli o ujemnej wadze
    for (int u = 0; u < vertices; ++u) {
        for (auto &edge: graphList[u]) {
            int v = edge.first, weight = edge.second;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                std::cout << "Graph contains a negative-weight cycle." << std::endl;
                return {};
            }
        }
    }

    return distance;
}
