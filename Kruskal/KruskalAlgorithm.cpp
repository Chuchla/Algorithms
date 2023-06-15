//
// Created by GS65 on 11.06.2023.
//

#include "../Utils/RandomGraph/RandomGraph.h"
#include <vector>
#include <algorithm>
#include "KruskalAlgorithm.h"
#include "UnionFind.h"

    std::vector<int> parent, rank;

    UnionFind::UnionFind(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int UnionFind::find(int u) {
        if(u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void UnionFind::merge(int x, int y) {
        x = find(x), y = find(y);
        if(rank[x] > rank[y])
            parent[y] = x;
        else
            parent[x] = y;
        if(rank[x] == rank[y])
            rank[y]++;
    }


    std::vector<std::pair<int, std::pair<int, int>>> KruskalAlgorithm::computeAlgorithmMatrix(const std::vector<std::vector<int>>& graphMatrix) {
        int vertices = graphMatrix.size();
        std::vector<std::pair<int, std::pair<int, int>>> edges, mst;
        for(int i = 0; i < vertices; ++i) {
            for(int j = 0; j < i; ++j) {
                if(graphMatrix[i][j])
                    edges.push_back({graphMatrix[i][j], {i, j}});
            }
        }
        std::sort(edges.begin(), edges.end());
        UnionFind uf(vertices);
        for(auto & edge : edges) {
            int u = edge.second.first, v = edge.second.second;
            if(uf.find(u) != uf.find(v)) {
                mst.push_back(edge);
                uf.merge(u, v);
            }
        }
        return mst;
    }

    std::vector<std::pair<int, std::pair<int, int>>> KruskalAlgorithm::computeAlgorithmList(const std::vector<std::list<std::pair<int, int>>>& graphList) {
        int vertices = graphList.size();
        std::vector<std::pair<int, std::pair<int, int>>> edges, mst;
        for(int i = 0; i < vertices; ++i) {
            for(auto & edge : graphList[i]) {
                if(i < edge.first)
                    edges.push_back({edge.second, {i, edge.first}});
            }
        }
        std::sort(edges.begin(), edges.end());
        UnionFind uf(vertices);
        for(auto & edge : edges) {
            int u = edge.second.first, v = edge.second.second;
            if(uf.find(u) != uf.find(v)) {
                mst.push_back(edge);
                uf.merge(u, v);
            }
        }
        return mst;
    }
std::vector<std::pair<int, std::pair<int, int>>> KruskalAlgorithm::computeAlgorithmIncidentMatrix(const std::vector<std::vector<int>>& incidentMatrix) {
    int vertices = incidentMatrix[0].size();
    std::vector<std::pair<int, std::pair<int, int>>> edges, mst;

    for(int i = 0; i < incidentMatrix.size(); ++i) {
        int u = -1, v = -1;
        int edgeWeight = 0;
        for(int j = 0; j < incidentMatrix[i].size(); ++j) {
            if(incidentMatrix[i][j] != 0){
                edgeWeight = incidentMatrix[i][j];
                if(u == -1){
                    u = j;
                } else {
                    v = j;
                    break;
                }
            }
        }
        if(u != -1 && v != -1){
            edges.push_back({edgeWeight, {u, v}});
        }
    }

    std::sort(edges.begin(), edges.end());
    UnionFind uf(vertices);
    for(auto & edge : edges) {
        int u = edge.second.first, v = edge.second.second;
        if(uf.find(u) != uf.find(v)) {
            mst.push_back(edge);
            uf.merge(u, v);
        }
    }

    return mst;
}


