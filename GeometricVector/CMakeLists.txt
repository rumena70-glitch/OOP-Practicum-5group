cmake_minimum_required(VERSION 4.2)
project(GeometricVector)

set(CMAKE_CXX_STANDARD 23)

add_executable(GeometricVector main.cpp
        GeometricVector.cpp
        GeometricVector.h)
