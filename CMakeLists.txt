cmake_minimum_required(VERSION 3.6)
project(DataStructure)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp src/LoadGraph.cpp include/LoadGraph.h include/OutputGraph.h src/OutputGraph.cpp include/DataStructure/Graph.h include/TourGraph.h src/TourGraph.cpp include/MiniDistance.h src/MiniDistance.cpp include/DataStructure/Stack.h include/DataStructure/Queue.h include/Parking.h src/Parking.cpp include/TUI.h src/TUI.cpp src/MiniSpanTree.cpp include/MiniSpanTree.h src/SearchSpot.cpp include/SearchSpot.h include/Sort.h src/Sort.cpp include/DataStructure/Car.h)
add_executable(DataStructure ${SOURCE_FILES})