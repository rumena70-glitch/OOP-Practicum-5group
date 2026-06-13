cmake_minimum_required(VERSION 3.26)
project(OOP_Practicum_5group)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-std=c++23)  # Force Homebrew LLVM to use C++23

add_executable(OOP_Practicum_5group
    task3.cpp
        task1.cpp
        task2.cpp
)