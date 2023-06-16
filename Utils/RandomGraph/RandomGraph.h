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
    RandomGraph();

    int vertexNumber;
    int edgesAdded;
    std::vector<std::vector<int>> matrixGraph;
    std::vector<std::list<std::pair<int,int>>> listGraph;
    std::vector<std::vector<int>> incidentMatrixGraph;

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

    int maxNumberOfEdgesUndirected();
    int maxNumberOfEdgesDirected();

    void maxDensityDirected();

    void readGraphFromFileDirected(const std::string &filename);

    void addEdgeDirected(int sourceVertex, int targetVertex, int weight);

    void GenerateGraphDirected(int graphDensity);

    std::vector<std::vector<int>> getMatrixGraph();

    std::vector<std::list<std::pair<int, int>>> getListGraph();

    void clearGraph();

    void printGraphIncidentMatrix();

    std::vector<std::vector<int>> getIncidentMatrixGraph();

    void GenerateGraphUndirected(int vertexNumber, int graphDensity);

    void GenerateGraphDirected(int vertexNumber, int graphDensity);
};


#endif //ALGORITHMS_RANDOMGRAPH_H
