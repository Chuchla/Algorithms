cmake_minimum_required(VERSION 3.24)
project(Algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(Algorithms main.cpp Utils/RandomGraph/RandomGraph.cpp Utils/RandomGraph/RandomGraph.h Utils/ReadFromFile/ReadFromFile.cpp Utils/ReadFromFile/ReadFromFile.h)
