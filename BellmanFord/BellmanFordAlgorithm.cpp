//
// Created by GS65 on 11.06.2023.
//

#include "../Utils/RandomGraph/RandomGraph.h"
#include "BellmanFordAlgorithm.h"
#include <vector>
#include <climits>
#include <iostream>

std::pair<std::vector<int>, std::vector<int>>
BellmanFordAlgorithm::computeAlgorithmMatrix(const std::vector<std::vector<int>> &graphMatrix, int sourceVertex) {
    int vertices = graphMatrix.size();
    std::vector<int> distance(vertices, INT_MAX);
    distance[sourceVertex] = 0;
    std::vector<int> parent(vertices, -1);
    std::pair<std::vector<int>,std::vector<int>> pairReturn;

    for (int i = 1; i <= vertices - 1; ++i) {
        for (int u = 0; u < vertices; ++u) {
            for (int v = 0; v < vertices; ++v) {
                if (graphMatrix[u][v] && distance[u] != INT_MAX && distance[u] + graphMatrix[u][v] < distance[v]){
                    distance[v] = distance[u] + graphMatrix[u][v];
                    parent[v] = u;
                }
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
    pairReturn.first = distance;
    pairReturn.second = parent;

    return pairReturn;
}

std::pair<std::vector<int>, std::vector<int>>
BellmanFordAlgorithm::computeAlgorithmList(const std::vector<std::list<std::pair<int, int>>> &graphList,
                                           int sourceVertex) {
    int vertices = graphList.size();
    std::vector<int> distance(vertices, INT_MAX);
    distance[sourceVertex] = 0;
    std::vector<int> parent(vertices, -1);
    std::pair<std::vector<int>,std::vector<int>> pairReturn;
    for (int i = 1; i <= vertices - 1; ++i) {
        for (int u = 0; u < vertices; ++u) {
            for (auto &edge: graphList[u]) {
                int v = edge.first, weight = edge.second;
                if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
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
    pairReturn.first = distance;
    pairReturn.second = parent;
    return pairReturn;
}

std::pair<std::vector<int>, std::vector<int>>
BellmanFordAlgorithm::computeAlgorithmIncidentMatrix(const std::vector<std::vector<int>> &incidentMatrixGraph,
                                                     int sourceVertex) {

        int vertexNumber = incidentMatrixGraph[0].size();
        std::vector<int> distance(vertexNumber, INT_MAX);
        distance[sourceVertex] = 0;
    std::vector<int> parent(vertexNumber, -1);
    std::pair<std::vector<int>,std::vector<int>> pairReturn;
        for (int i = 1; i < vertexNumber - 1; i++) {
            for (int j = 0; j < incidentMatrixGraph.size()-1; j++) {
                int targetVertex = 0;
                int fromVertex = 0;

                for (int k = 0; k < incidentMatrixGraph[j].size(); k++) {
                    if (incidentMatrixGraph[j][k] != 0)
                        if (incidentMatrixGraph[j][k] < 0) targetVertex = k;
                        else fromVertex = k;
                }
                int weight = incidentMatrixGraph[j][fromVertex];
                if (distance[fromVertex] + weight < distance[targetVertex] && (distance[fromVertex] != INT_MAX)) {
                    distance[targetVertex] = distance[fromVertex] + incidentMatrixGraph[j][fromVertex];
                    parent[targetVertex] = fromVertex;
                }
            }
        }

        for (int j = 0; j < incidentMatrixGraph[j].size(); j++) {
            int targetVertex = 0;
            int fromVertex = 0;

            for (int k = 0; k < incidentMatrixGraph[j].size(); k++) {
                if (incidentMatrixGraph[j][k] != 0)
                    if (incidentMatrixGraph[j][k] < 0) targetVertex = k;
                    else fromVertex = k;
            }
            int weight = incidentMatrixGraph[j][fromVertex];
            if (distance[fromVertex] + weight < distance[targetVertex] && (distance[fromVertex] != INT_MAX)) {
                std::cout << "Graph contains a negative-weight cycle." << std::endl;
                return {};
            }
        }
        pairReturn.first = distance;
        pairReturn.second = parent;
        return pairReturn;
    }




