//
// Created by GS65 on 10.06.2023.
//

#ifndef ALGORITHMS_RANDOMGRAPH_H
#define ALGORITHMS_RANDOMGRAPH_H


#include <vector>

class RandomGraph {
public :
    int getRandomWeight();

    int getRandomVertex(int vertexNumber);

    int maxNumberOfEdges(int vertexNumber);

    std::vector<std::vector<int>> maxDensity(int vertexNumber, std::vector<std::vector<int>> graph);


     std::vector<std::vector<int>> GenerateUndirectedGraph(int vertexNumber, int graphDensity);

     void printGraph(std::vector<std::vector<int>> graph);
};


#endif //ALGORITHMS_RANDOMGRAPH_H
