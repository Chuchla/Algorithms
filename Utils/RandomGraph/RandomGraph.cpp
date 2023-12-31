//
// Created by GS65 on 10.06.2023.
//
#include "RandomGraph.h"
#include <random>
#include <vector>
#include <iostream>
#include <utility>
#include <iomanip>
#include <unordered_set>
#include <fstream>
RandomGraph::RandomGraph(int vertexNumber) : vertexNumber(vertexNumber) {
    edgesAdded = 0;
    matrixGraph.resize(vertexNumber, std::vector<int>(vertexNumber, 0));
    listGraph.resize(vertexNumber);
    incidentMatrixGraph.resize(1,std::vector<int>(vertexNumber,0));
}


int RandomGraph::getRandomWeight() {
    using namespace std;
    random_device device;
    mt19937 rng(device());
    uniform_int_distribution<> distribution(1, 100);
    return distribution(rng);

}

int RandomGraph::getRandomVertex() {
    using namespace std;
    random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution<> distribution(0, vertexNumber - 1);
    return distribution(rng);
}

int RandomGraph::maxNumberOfEdgesUndirected() {
    return (vertexNumber * (vertexNumber - 1)) / 2; // n*(n-1) / 2
}
int RandomGraph::maxNumberOfEdgesDirected() {
    return vertexNumber * (vertexNumber - 1); // n*(n-1) for directed graph
}

void RandomGraph::maxDensityUndirected() {
    using namespace std;
    incidentMatrixGraph.resize(maxNumberOfEdgesUndirected(), vector<int>(vertexNumber, 0));
    edgesAdded = maxNumberOfEdgesUndirected();
    int edgesIndex=0;
    for (int i = 0; i < matrixGraph.size(); i++)
        for (int j = i + 1; j < matrixGraph.size(); j++) {
            if (i != j) {
                int weight = getRandomWeight();
                listGraph[i].emplace_back(make_pair(j, weight));
                listGraph[j].emplace_back(make_pair(i, weight));
                matrixGraph[i][j] = weight;
                matrixGraph[j][i] = weight;
                incidentMatrixGraph[edgesIndex][i] = weight;
                incidentMatrixGraph[edgesIndex][j] = weight;
                edgesIndex++;
            }
        }

}
void RandomGraph::maxDensityDirected() {
    using namespace std;
    incidentMatrixGraph.resize(maxNumberOfEdgesDirected(), vector<int>(vertexNumber, 0));
    edgesAdded = maxNumberOfEdgesDirected();
    int edgesIndex=0;
    for (int i = 0; i < matrixGraph.size(); i++)
        for (int j = 0; j < matrixGraph.size(); j++) {
            if (i != j) {
                int weight = getRandomWeight();
                listGraph[i].emplace_back(make_pair(j, weight));
                matrixGraph[i][j] = weight;
                incidentMatrixGraph[edgesIndex][i] = weight;
                incidentMatrixGraph[edgesIndex][j] = -weight;
                edgesIndex++;
            }
        }

}

void RandomGraph::GenerateGraphUndirected(int vertexNumber,int graphDensity){
    using namespace std;
    this->vertexNumber = vertexNumber;
    matrixGraph.resize(vertexNumber, std::vector<int>(vertexNumber, 0));
    listGraph.resize(vertexNumber);
    incidentMatrixGraph.resize(1,std::vector<int>(vertexNumber,0));
    clearGraph();
    if (graphDensity == 100) {
        maxDensityUndirected();
    }
    else {
        int maxEdges = maxNumberOfEdgesUndirected() * graphDensity / 100;
        //int numberOfEdgesAdded = 0;
        vector<unordered_set<int>> visitedVerticies;
        visitedVerticies.resize(vertexNumber);
        while(edgesAdded < maxEdges){
            int sourceVertex = getRandomVertex();
            int targetVertex = getRandomVertex();
            int weight = getRandomWeight();
            if(sourceVertex != targetVertex && visitedVerticies[sourceVertex].count(targetVertex) == 0){
                addEdgeUndirected(targetVertex,sourceVertex,weight);
                visitedVerticies[sourceVertex].insert(targetVertex);
                visitedVerticies[targetVertex].insert(sourceVertex);
            }
        }
    }
}
void RandomGraph::GenerateGraphDirected(int vertexNumber,int graphDensity){
    using namespace std;
    this->vertexNumber = vertexNumber;
    matrixGraph.resize(vertexNumber, std::vector<int>(vertexNumber, 0));
    listGraph.resize(vertexNumber);
    incidentMatrixGraph.resize(1,std::vector<int>(vertexNumber,0));
    clearGraph();
    if (graphDensity == 100) {
        maxDensityDirected();
    }
    else {
        int maxEdges = maxNumberOfEdgesDirected() * graphDensity / 100;
        vector<unordered_set<int>> visitedVerticies;
        visitedVerticies.resize(vertexNumber);
        while(edgesAdded < maxEdges){
            int sourceVertex = getRandomVertex();
            int targetVertex = getRandomVertex();
            int weight = getRandomWeight();
            if(sourceVertex != targetVertex && visitedVerticies[sourceVertex].count(targetVertex) == 0){
                addEdgeDirected(sourceVertex, targetVertex, weight);
                visitedVerticies[sourceVertex].insert(targetVertex);
            }
        }
    }
}

void RandomGraph::printGraphMatrix() {
    using namespace std;
    cout << "        ";
    for (int i = 0; i < vertexNumber; ++i) {
        cout << setw(4) << "V" << i;
    }
    cout << endl;
    int vertexPrinted = 0;
    for (std::vector<int> element: matrixGraph) {
        cout << "Vertex " << vertexPrinted << ": ";
        vertexPrinted++;
        for (int edge: element) {
            cout << setw(5) << edge;
        }
        cout << endl;
    }
}

void RandomGraph::printGraphList() {
    using namespace std;
    for (int i = 0; i < listGraph.size(); ++i) {
        cout << "Vertex " << i << ": ";
        for (const auto &edge: listGraph[i]) {
            int targetVertex = edge.first;
            int weight = edge.second;
            cout << "(" << targetVertex << ", " << weight << ") ";
        }
        cout << endl;
    }
}

void RandomGraph::printGraphIncidentMatrix(){
    using namespace std;
    cout << "       ";
    for (int i = 0; i < vertexNumber; ++i) {
        cout << setw(4) << "V" << i;
    }
    cout << endl;
    for (int i = 0; i < edgesAdded; ++i) {
        cout << "Edge " << i << ": ";
        for (const auto &edge: incidentMatrixGraph[i]) {
            int weight = edge;
            cout << setw(5) << weight;
        }
        cout << endl;
    }

}
void RandomGraph::addEdgeUndirected(int sourceVertex, int targetVertex, int weight) {
    using namespace std;
    if(edgesAdded/2 < maxNumberOfEdgesUndirected()) {
        edgesAdded++;
        matrixGraph[sourceVertex][targetVertex] = weight;
        matrixGraph[targetVertex][sourceVertex] = weight; // dodajemy krawędź w przeciwnym kierunku
        listGraph[sourceVertex].emplace_back(make_pair(targetVertex, weight));
        listGraph[targetVertex].emplace_back(make_pair(sourceVertex, weight)); // dodajemy krawędź w przeciwnym kierunku
        incidentMatrixGraph.emplace_back(vector<int>(0));
        if(edgesAdded - 1 == 0){
            incidentMatrixGraph[edgesAdded-1][sourceVertex] = weight;
            incidentMatrixGraph[edgesAdded-1][targetVertex] = weight;
        }
        else {
            for(int i = 0 ; i < vertexNumber; i++) incidentMatrixGraph[edgesAdded-1].emplace_back(0);
            incidentMatrixGraph[edgesAdded-1][sourceVertex] = weight;
            incidentMatrixGraph[edgesAdded-1][targetVertex] = weight;

        }
    } else {
        cout << "Cannot add more edges. The graph is fully connected." << endl;
    }

}
void RandomGraph::addEdgeDirected(int sourceVertex, int targetVertex, int weight) {
    using namespace std;
    if(edgesAdded < maxNumberOfEdgesDirected()) {
        edgesAdded++;
        matrixGraph[sourceVertex][targetVertex] = weight;
        listGraph[sourceVertex].emplace_back(make_pair(targetVertex, weight));
        incidentMatrixGraph.emplace_back(vector<int>(0));
        if(edgesAdded - 1 == 0){
            incidentMatrixGraph[edgesAdded-1][sourceVertex] = weight;
            incidentMatrixGraph[edgesAdded-1][targetVertex] = -weight;
        }
        else {
            for(int i = 0 ; i < vertexNumber; i++) incidentMatrixGraph[edgesAdded-1].emplace_back(0);
            incidentMatrixGraph[edgesAdded-1][sourceVertex] = weight;
            incidentMatrixGraph[edgesAdded-1][targetVertex] = -weight;
        }

    } else {
        cout << "Cannot add more edges. The graph is fully connected." << endl;
    }
}

void RandomGraph::readGraphFromFileUndirected(const std::string &filename) {
    using namespace std;
    clearGraph();
    ifstream file(filename);
    if (!file) {
        cout << "Failed to open the file: " << filename << endl;
        return;
    }

    int numEdges;
    for(int i = 0; i<vertexNumber; i++) matrixGraph[i].clear();
    file >> numEdges >> vertexNumber;
    this->vertexNumber = vertexNumber;

    matrixGraph.resize(vertexNumber, vector<int>(vertexNumber, 0));
    listGraph.resize(vertexNumber);
    incidentMatrixGraph.resize(0);
    incidentMatrixGraph.resize(1,std::vector<int>(vertexNumber,0));

    for (int i = 0; i < numEdges; ++i) {
        int source, destination, weight;
        file >> source >> destination >> weight;
        addEdgeUndirected(source, destination, weight);
    }

    file.close();
}
void RandomGraph::readGraphFromFileDirected(const std::string &filename) {
    using namespace std;
    clearGraph();
    ifstream file(filename);
    if (!file) {
        cout << "Failed to open the file: " << filename << endl;
        return;
    }

    int numEdges;
    for(int i = 0; i<vertexNumber; i++) matrixGraph[i].clear();
    file >> numEdges >> vertexNumber;
    this->vertexNumber = vertexNumber;
    matrixGraph.resize(vertexNumber, vector<int>(vertexNumber, 0));
    listGraph.resize(vertexNumber);
    incidentMatrixGraph.resize(0);
    incidentMatrixGraph.resize(1,std::vector<int>(vertexNumber,0));

    for (int i = 0; i < numEdges; ++i) {
        int source, destination, weight;
        file >> source >> destination >> weight;
        addEdgeDirected(source, destination, weight);
    }

    file.close();
}
std::vector<std::vector<int>> RandomGraph::getMatrixGraph(){
    return matrixGraph;
}
std::vector<std::list<std::pair<int,int>>> RandomGraph::getListGraph(){
    return listGraph;
}
std::vector<std::vector<int>> RandomGraph::getIncidentMatrixGraph(){
    return incidentMatrixGraph;
}
void RandomGraph::clearGraph() {
    for(int i = 0; i<vertexNumber; i++) matrixGraph[i].clear();
    matrixGraph.clear();
    listGraph.clear();
    matrixGraph.resize(vertexNumber, std::vector<int>(vertexNumber, 0));
    listGraph.resize(vertexNumber);
    incidentMatrixGraph.clear();
    incidentMatrixGraph.resize(0);
    incidentMatrixGraph.resize(1,std::vector<int>(vertexNumber,0));
    edgesAdded = 0;
}








