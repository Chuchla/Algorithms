#include "../Utils/RandomGraph/RandomGraph.h"
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
#include "PrimsAlgorithm.h"

std::vector<std::pair<int, std::pair<int, int>>>
PrimAlgorithm::computeAlgorithmMatrix(const std::vector<std::vector<int>> &graphMatrix) {
    std::vector<std::pair<int, std::pair<int, int>>> mst;
    if (graphMatrix.size() == 0) return mst;
    else {
        int vertices = graphMatrix.size();
        std::vector<int> key(vertices, INT_MAX);
        std::vector<bool> inMST(vertices, false);
        std::vector<int> parent(vertices, -1);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        key[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {

            int u = pq.top().second;
            pq.pop();
            inMST[u] = true;

            for (int v = 0; v < vertices; ++v) {
                int weight = graphMatrix[u][v];
                if (graphMatrix[u][v] && inMST[v] == false && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                    pq.push({key[v], v});
                }
            }
        }


        for (int i = 1; i < vertices; ++i)
            mst.push_back({graphMatrix[i][parent[i]], {parent[i], i}});
        return mst;
    }
}

std::vector<std::pair<int, std::pair<int, int>>>
PrimAlgorithm::computeAlgorithmList(const std::vector<std::list<std::pair<int, int>>> &graphList) {
    std::vector<std::pair<int, std::pair<int, int>>> mst;
    if (graphList.size() == 0) return mst;
    else {
        int vertices = graphList.size();
        std::vector<int> key(vertices, INT_MAX);
        std::vector<bool> inMST(vertices, false);
        std::vector<int> parent(vertices, -1);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        key[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            inMST[u] = true;

            for (auto &i: graphList[u]) {
                int v = i.first;
                int weight = i.second;
                if (inMST[v] == false && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                    pq.push({key[v], v});
                }
            }
        }


        for (int i = 1; i < vertices; ++i) {
            for (auto &j: graphList[i]) {
                if (j.first == parent[i]) {
                    mst.push_back({j.second, {parent[i], i}});
                    break;
                }
            }
        }

        return mst;
    }
}

std::vector<std::pair<int, std::pair<int, int>>>
PrimAlgorithm::computeAlgorithmIncidentMatrix(const std::vector<std::vector<int>> &incidentMatrix) {
    std::vector<std::pair<int, std::pair<int, int>>> mst;
    if(incidentMatrix[0].size() == 0 ) return mst;
    else {
        int vertices = incidentMatrix[0].size();
        std::vector<int> key(vertices, INT_MAX);
        std::vector<bool> inMST(vertices, false);
        std::vector<int> parent(vertices, -1);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        key[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            inMST[u] = true;

            for (int i = 0; i < incidentMatrix.size() - 1; ++i) {
                int edgeWeight = incidentMatrix[i][u];
                if (edgeWeight != 0) {
                    int v = -1; // find the other end of the edge
                    for (int j = 0; j < incidentMatrix[i].size(); ++j) {
                        if (j != u && incidentMatrix[i][j] != 0) {
                            v = j;
                            break;
                        }
                    }
                    if (v == -1 || inMST[v]) continue; // no other end found or the other end is already in MST
                    if (edgeWeight < key[v]) {
                        parent[v] = u;
                        key[v] = edgeWeight;
                        pq.push({key[v], v});
                    }
                }
            }
        }


        for (int i = 1; i < vertices; ++i)
            mst.push_back({key[i], {parent[i], i}});

        return mst;
    }
}



