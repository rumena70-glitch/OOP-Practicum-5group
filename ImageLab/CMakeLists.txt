cmake_minimum_required(VERSION 4.2)
project(ImageLab)

set(CMAKE_CXX_STANDARD 26)

add_executable(ImageLab main.cpp
        Image.cpp
        Image.h
        PGMImage.cpp
        PGMImage.h
        PPMImage.cpp
        PPMImage.h
        PBMImage.cpp
        PBMImage.h)
