cmake_minimum_required(VERSION 3.6)
project(DE_implementation)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES sources/main.cpp sources/DifferentialEvolution.cpp headers/DifferentialEvolution.h sources/VectorOperations.cpp headers/VectorOperations.h sources/TrigonometryOperations.cpp headers/TrigonometryOperations.h)
add_executable(DE_implementation ${SOURCE_FILES})