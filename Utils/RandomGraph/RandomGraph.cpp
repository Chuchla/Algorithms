//
// Created by GS65 on 10.06.2023.
//
#include "RandomGraph.h"
#include <random>
#include <vector>
#include <iostream>

    int RandomGraph::getRandomWeight() {
        using namespace std;
        random_device device;
        mt19937 rng(device());
        uniform_int_distribution<> distribution(1, 100);
        return distribution(rng);

    }int RandomGraph::getRandomVertex(int vertexNumber){
        using namespace std;
        random_device device;
        std::mt19937 rng(device());
        std::uniform_int_distribution<> distribution(1, vertexNumber-1);
        return distribution(rng);
    }

    int RandomGraph::maxNumberOfEdges(int vertexNumber){
        return (vertexNumber*(vertexNumber-1))/2; // n*(n-1) / 2
    }
    std::vector<std::vector<int>> RandomGraph::maxDensity(int vertexNumber, std::vector<std::vector<int>> graph){
        for(int i = 1; i < vertexNumber; i++)
            for(int j = i+1; j< vertexNumber; j++){
                int weight = getRandomWeight();
                graph[i][j] = weight;
                graph[j][i] = weight;
            }
        return graph;
    }

    std::vector<std::vector<int>> RandomGraph::GenerateUndirectedGraph(int vertexNumber, int graphDensity){
        using namespace std;

        vector<vector<int>> graph;
        graph.resize(vertexNumber, vector<int>(vertexNumber, 0));
        if(graphDensity == 100) graph = maxDensity(vertexNumber, graph);
        else {
            int maxEdges = maxNumberOfEdges(vertexNumber) * graphDensity/100;
            int numberOfEdgesAdded = 0;
            while (numberOfEdgesAdded < maxEdges) {
                int sourceVertex = getRandomVertex(vertexNumber);
                int targetVertex = getRandomVertex(vertexNumber);
                if (sourceVertex != targetVertex && graph[sourceVertex][targetVertex] == 0) {
                    int weight = getRandomWeight();
                    graph[sourceVertex][targetVertex] = weight;
                    graph[targetVertex][sourceVertex] = weight;
                    numberOfEdgesAdded++;
                }
            }
        }
        return graph;
    }
    void RandomGraph::printGraph(std::vector<std::vector<int>> graph) {
        using namespace std;
        for (std::vector<int> element : graph) {
            for (int edge : element) {
                cout << edge << " ";
            }
            cout << endl;
        }
    }




