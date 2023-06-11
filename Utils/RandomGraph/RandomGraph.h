//
// Created by GS65 on 10.06.2023.
//

#ifndef ALGORITHMS_RANDOMGRAPH_H
#define ALGORITHMS_RANDOMGRAPH_H


#include <vector>
#include <utility>
#include <list>
#include <string>

class RandomGraph {
public :
    int vertexNumber;
    std::vector<std::vector<int>> matrixGraph;
    std::vector<std::list<std::pair<int,int>>> listGraph;

    RandomGraph(int vertexNumber);

    int getRandomWeight();

    void readGraphFromFileUndirected(const std::__cxx11::basic_string<char> &filename);

    int getRandomVertex();

    int maxNumberOfEdges();

    void printGraphMatrix(std::vector<std::vector<int>> graph);

    void printGraphList(std::vector<std::list<std::pair<int, int>>> graph);

    void GenerateGraphUndirected(int graphDensity);

    void addEdgeUndirected(int sourceVertex, int targetVertex, int weight);

    void printGraphList();

    void printGraphMatrix();

    void maxDensityUndirected();
};


#endif //ALGORITHMS_RANDOMGRAPH_H
