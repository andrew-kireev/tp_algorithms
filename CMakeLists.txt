cmake_minimum_required(VERSION 3.15)
project(tp_algorithms)

set(CMAKE_CXX_STANDARD 20)

include_directories(module_3/hw_1)

add_executable(tp_algorithms module_3/hw_1/ArcGraph.cpp
        module_3/hw_1/SetGraph.cpp module_3/hw_1/MatrixGraph.cpp
        module_3/hw_1/ListGraph.cpp module_3/hw_1/main.cpp)
