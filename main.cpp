#include <iostream>
#include "Utils/RandomGraph/RandomGraph.h"
#include <memory>
#include "BellmanFord/BellmanFordAlgorithm.h"
#include "Dijkstra/DijkstraAlgorithm.h"
#include "Kruskal/KruskalAlgorithm.h"
#include "Prim/PrimsAlgorithm.h"
#include "Utils/Test/TestPerformer.h"
#include <iomanip>

std::shared_ptr<BellmanFordAlgorithm> bellmanFordAlgorithm = std::make_shared<BellmanFordAlgorithm>();
std::shared_ptr<DijkstraAlgorithm> dijkstraAlgorithm = std::make_shared<DijkstraAlgorithm>();
std::shared_ptr<KruskalAlgorithm> kruskalAlgorithm = std::make_shared<KruskalAlgorithm>();
std::shared_ptr<PrimAlgorithm> primAlgorithm = std::make_shared<PrimAlgorithm>();
std::shared_ptr<TestPerformer> testPerformer = std::make_shared<TestPerformer>();

void printShortestDistances(const std::pair<std::vector<int>, std::vector<int>> &pair) {
    std::cout << "Shortest distances from source vertex 0:" << std::endl;
    for (int i = 0; i < pair.first.size(); ++i) {
        if (pair.first[i] == 2147483647) std::cout << "Vertex " << i << ": path does not exist (+oo)";
        else {
            std::cout << "Vertex " << std::setw(3) << i << ": " << pair.first[i];
            if (pair.second[i] == -1) std::cout << "  source";
            else {

                std::cout << std::setw(3) << "V" << pair.second[i];
                int parent = pair.second[i];
                while (parent > 0) {
                    std::cout << "<-V" << pair.second[parent];
                    parent = pair.second[parent];
                }
            }
        }
        std::cout << std::endl;
    }
}


void printMinimumSpanningTree(const std::vector<std::pair<int, std::pair<int, int>>> &mst) {
    std::cout << "Minimum Spanning Tree:" << std::endl;
    for (const auto &edge: mst) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (weight == INT_MAX || weight < 0)
            std::cout << "Edge (" << u << " - " << v << ") with: " << "couldn't be connected" << std::endl;
        else std::cout << "Edge (" << u << " - " << v << ") with weight: " << weight << std::endl;
    }
}

void menuMST() {
    using namespace std;
    int choice;
    string file;
    int vertexNumber;
    int density;
    int choiceChoice;
    std::shared_ptr<RandomGraph> randomGraph = make_shared<RandomGraph>(0);
    do {
        cout << "===================================" << endl;
        cout << "1. Wczytaj dane z pliku" << endl;
        cout << "2. Wygeneruj graf losowo" << endl;
        cout << "3. Wyswietl graf" << endl;
        cout << "4. Algorytm Kruskala" << endl;
        cout << "5. Algorytm Prima" << endl;
        cout << "6. Cofnij" << endl;
        cout << "===================================" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Podaj sciezke do pliku" << endl;
                cin >> file;
                randomGraph->readGraphFromFileUndirected(file);
                break;
            case 2:
                cout << "Podaj liczbe wierzcholkow grafu" << endl;
                cin >> vertexNumber;
                cout << "Podaj gestosc grafu" << endl;
                cin >> density;
                randomGraph->GenerateGraphUndirected(vertexNumber, density);
                break;
            case 3:
                do {
                    cout << endl;
                    cout << "===================================" << endl;
                    cout << "1. Wyswietl macierz sasiedztwa grafu" << endl;
                    cout << "2. Wyswietl liste sasiedztwa grafu" << endl;
                    cout << "3. Wyswietl macierz incydencji grafu" << endl;
                    cout << "4. Cofnij" << endl;
                    cout << "===================================" << endl;
                    cin >> choiceChoice;
                    switch (choiceChoice) {
                        case 1:
                            randomGraph->printGraphMatrix();
                            break;
                        case 2:
                            randomGraph->printGraphList();
                            break;
                        case 3:
                            randomGraph->printGraphIncidentMatrix();
                            break;
                        case 4:
                            choiceChoice = 4;
                            break;
                        default:
                            break;
                    }
                } while (choiceChoice != 4);
                break;
            case 4:
                do {
                    cout << endl;
                    cout << "===================================" << endl;
                    cout << "1. Uzywajac macierzy sasiedztwa" << endl;
                    cout << "2. Uzywajac listy sasiedztwa" << endl;
                    cout << "3. Uzywajac macierzy incydencji" << endl;
                    cout << "4. Cofnij" << endl;
                    cout << "===================================" << endl;
                    cin >> choiceChoice;
                    switch (choiceChoice) {
                        case 1:
                            printMinimumSpanningTree(
                                    kruskalAlgorithm->computeAlgorithmMatrix(randomGraph->getMatrixGraph()));
                            break;
                        case 2:
                            printMinimumSpanningTree(
                                    kruskalAlgorithm->computeAlgorithmList(randomGraph->getListGraph()));
                            break;
                        case 3:
                            printMinimumSpanningTree(kruskalAlgorithm->computeAlgorithmIncidentMatrix(
                                    randomGraph->getIncidentMatrixGraph()));
                            break;
                        case4:
                            choiceChoice = 4;
                            break;
                        default:
                            break;
                    }
                } while (choiceChoice != 4);
                break;
            case 5:
                do {
                    cout << endl;
                    cout << "===================================" << endl;
                    cout << "1. Uzywajac macierzy sasiedztwa" << endl;
                    cout << "2. Uzywajac listy sasiedztwa" << endl;
                    cout << "3. Uzywajac macierzy incydencji" << endl;
                    cout << "4. Cofnij" << endl;
                    cout << "===================================" << endl;
                    cin >> choiceChoice;
                    switch (choiceChoice) {
                        case 1:
                            printMinimumSpanningTree(
                                    primAlgorithm->computeAlgorithmMatrix(randomGraph->getMatrixGraph()));
                            break;
                        case 2:
                            printMinimumSpanningTree(primAlgorithm->computeAlgorithmList(randomGraph->getListGraph()));
                            break;
                        case 3:
                            printMinimumSpanningTree(primAlgorithm->computeAlgorithmIncidentMatrix(
                                    randomGraph->getIncidentMatrixGraph()));
                            break;
                        case 4:
                            choiceChoice = 4;
                            break;
                        default:
                            break;
                    }
                } while (choiceChoice != 4);
                break;
            case 6:
                choice = 6;
                break;
            default:
                break;
        }
    } while (choice != 6);
}

void menuSD() {
    using namespace std;
    int choice;
    string file;
    int vertexNumber;
    int density;
    int choiceChoice;
    int sourceVertex;
    std::shared_ptr<RandomGraph> randomGraph = make_shared<RandomGraph>(0);
    do {
        cout << "===================================" << endl;
        cout << "1. Wczytaj dane z pliku" << endl;
        cout << "2. Wygeneruj graf losowo" << endl;
        cout << "3. Wyswietl graf" << endl;
        cout << "4. Algorytm BellmanaForda" << endl;
        cout << "5. Algorytm Dijkstry" << endl;
        cout << "6. Cofnij" << endl;
        cout << "===================================" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Podaj sciezke do pliku" << endl;
                cin >> file;
                randomGraph->readGraphFromFileDirected(file);
                break;
            case 2:
                cout << "Podaj liczbe wierzcholkow grafu" << endl;
                cin >> vertexNumber;
                cout << "Podaj gestosc grafu" << endl;
                cin >> density;
                randomGraph->GenerateGraphDirected(vertexNumber, density);
                break;
            case 3:
                do {
                    cout << endl;
                    cout << "===================================" << endl;
                    cout << "1. Wyswietl macierz sasiedztwa grafu" << endl;
                    cout << "2. Wyswietl liste sasiedztwa grafu" << endl;
                    cout << "3. Wyswietl macierz incydencji grafu" << endl;
                    cout << "4. Cofnij" << endl;
                    cout << "===================================" << endl;
                    cin >> choiceChoice;
                    switch (choiceChoice) {
                        case 1:
                            randomGraph->printGraphMatrix();
                            break;
                        case 2:
                            randomGraph->printGraphList();
                            break;
                        case 3:
                            randomGraph->printGraphIncidentMatrix();
                            break;
                        case 4:
                            choiceChoice = 4;
                            break;
                        default:
                            break;
                    }
                } while (choiceChoice != 4);
                break;
            case 4:
                cout << "Podaj wierzcholek zrodlowy" << endl;
                cin >> sourceVertex;
                do {
                    cout << endl;
                    cout << "===================================" << endl;
                    cout << "1. Uzywajac macierzy sasiedztwa" << endl;
                    cout << "2. Uzywajac listy sasiedztwa" << endl;
                    cout << "3. Uzywajac macierzy incydencji" << endl;
                    cout << "4. Cofnij" << endl;
                    cout << "===================================" << endl;
                    cin >> choiceChoice;
                    switch (choiceChoice) {
                        case 1:
                            printShortestDistances(
                                    bellmanFordAlgorithm->computeAlgorithmMatrix(randomGraph->getMatrixGraph(),
                                                                                 sourceVertex));
                            break;
                        case 2:
                            printShortestDistances(
                                    bellmanFordAlgorithm->computeAlgorithmList(randomGraph->getListGraph(),
                                                                               sourceVertex));
                            break;
                        case 3:
                            printShortestDistances(
                                    bellmanFordAlgorithm->computeAlgorithmIncidentMatrix(
                                            randomGraph->getIncidentMatrixGraph(), sourceVertex));
                            break;
                        case 4:
                            choiceChoice = 4;
                            break;
                        default:
                            break;
                    }
                } while (choiceChoice != 4);
                break;
            case 5:
                cout << "Podaj wierzcholek zrodlowy" << endl;
                cin >> sourceVertex;
                do {
                    cout << endl;
                    cout << "===================================" << endl;
                    cout << "1. Uzywajac macierzy sasiedztwa" << endl;
                    cout << "2. Uzywajac listy sasiedztwa" << endl;
                    cout << "3. Uzywajac macierzy incydencji" << endl;
                    cout << "4. Cofnij" << endl;
                    cout << "===================================" << endl;
                    cin >> choiceChoice;
                    switch (choiceChoice) {
                        case 1:
                            printShortestDistances(
                                    dijkstraAlgorithm->computeAlgorithmMatrix(randomGraph->getMatrixGraph(),
                                                                              sourceVertex));
                            break;
                        case 2:
                            printShortestDistances(
                                    dijkstraAlgorithm->computeAlgorithmList(randomGraph->getListGraph(), sourceVertex));
                            break;
                        case 3:
                            printShortestDistances(
                                    dijkstraAlgorithm->computeAlgorithmIncidentMatrix(
                                            randomGraph->getIncidentMatrixGraph(), sourceVertex));
                            break;
                        case 4:
                            choiceChoice = 4;
                            break;
                        default:
                            break;
                    }
                } while (choiceChoice != 4);
                break;
            case 6:
                choice = 6;
                break;
            default:
                break;
        }
    } while (choice != 6);
}

void menuTest() {
    using namespace std;
    int choice;
    string file;
    int vertexNumber;
    int density;
    int choiceChoice;
    int sourceVertex;
    std::shared_ptr<RandomGraph> randomGraph = make_shared<RandomGraph>(0);
    do {
        cout << "===================================" << endl;
        cout << "1. Testy Bellman-Ford" << endl;
        cout << "2. Testy Dijkstra" << endl;
        cout << "3. Testy Kruskal" << endl;
        cout << "4. Testy Prim" << endl;
        cout << "5. Testy wszystkie" << endl;
        cout << "6. Cofnij" << endl;
        cout << "===================================" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                choice = 6;
                testPerformer->BellmanFordTest();
                break;
            case 2:
                choice = 6;
                testPerformer->DijkstraTest();
                break;
            case 3:
                choice = 6;
                testPerformer->KruskalTest();
                break;
            case 4:
                choice = 6;
                testPerformer->PrimTest();
                break;
            case 5:
                choice =6;
                testPerformer -> BellmanFordTest();
                testPerformer -> DijkstraTest();
                testPerformer -> KruskalTest();
                testPerformer -> PrimTest();
                break;
            case 6:
                choice = 6;
                break;
        }
    } while (choice != 6);

}

void mainMenu() {
    using namespace std;
    int choice;
    do {
        cout << "===================================" << endl;
        cout << "1. Problem MST" << endl;
        cout << "2. Problem najkrotszej sciezki" << endl;
        cout << "3. Testy" << endl;
        cout << "4. Wyjdz" << endl;
        cout << "===================================" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                menuMST();
                break;
            case 2:
                menuSD();
                break;
            case 3:
                menuTest();
                break;
            case 4:
                choice = 4;
                break;
        }
    } while (choice != 4);
}

int main() {
    using namespace std;
    mainMenu();
    return 0;
}
