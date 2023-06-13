//
// Created by GS65 on 11.06.2023.
//

#ifndef ALGORITHMS_UNIONFIND_H
#define ALGORITHMS_UNIONFIND_H

#include <vector>

class UnionFind {
public:
    UnionFind(int n);
    int find(int x);
    void unite(int x, int y);
    bool same(int x, int y);
    std::vector<int> parent, rank;
    void merge(int x, int y);
};
#endif //ALGORITHMS_UNIONFIND_H
