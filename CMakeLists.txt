cmake_minimum_required(VERSION 3.28)
project(ap_3_dijkstra_s_algoritme_alialbonaser204)

set(CMAKE_CXX_STANDARD 14)

# executable zonder testbestanden
add_executable(ap_3_dijkstra_s_algoritme_alialbonaser204
        main.cpp
        source/CarStep.cpp
        source/Graph.cpp
        source/PlaneStep.cpp
        source/Station.cpp
        source/Step.cpp
        source/TrainStep.cpp
)
