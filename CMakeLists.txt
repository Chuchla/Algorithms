cmake_minimum_required(VERSION 3.24)
project(Algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(Algorithms
        main.cpp
        Utils/RandomGraph/RandomGraph.cpp
        Utils/RandomGraph/RandomGraph.h
        Prim/PrimsAlgorithm.cpp
        Prim/PrimsAlgorithm.h
        Kruskal/KruskalAlgorithm.cpp
        Kruskal/KruskalAlgorithm.h
        Dijkstra/DijkstraAlgorithm.cpp
        Dijkstra/DijkstraAlgorithm.h
        BellmanFord/BellmanFordAlgorithm.cpp
        BellmanFord/BellmanFordAlgorithm.h Kruskal/UnionFind.h Utils/Test/TestPerformer.cpp Utils/Test/TestPerformer.h)
#add_executable(Algorithms main.cpp Utils/RandomGraph/RandomGraph.cpp Utils/RandomGraph/RandomGraph.h Utils/ReadFromFile/ReadFromFile.cpp Utils/ReadFromFile/ReadFromFile.h Kruskal/KruskalAlgorithm.cpp Kruskal/KruskalAlgorithm.h Prim/PrimsAlgorithm.cpp Prim/PrimsAlgorithm.h BellmanFord/BellmanFordAlgorithm.cpp BellmanFord/BellmanFordAlgorithm.h BellmanFord/BellmanFordAlgorithm.cpp BellmanFord/BellmanFordAlgorithm.h Dijkstra/DijkstraAlgorithm.cpp Dijkstra/DijkstraAlgorithm.h Dijkstra/DijkstraAlgorithm.cpp BellmanFord/BellmanFordAlgorithm.h BellmanFord/BellmanFordAlgorithm.cpp)
