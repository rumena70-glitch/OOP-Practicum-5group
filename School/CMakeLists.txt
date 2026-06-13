cmake_minimum_required(VERSION 4.2)
project(School)

set(CMAKE_CXX_STANDARD 26)

add_executable(School main.cpp
        Person.cpp
        Person.h
        UniversityWorker.cpp
        UniversityWorker.h
        Principal.cpp
        Principal.h
        Teacher.cpp
        Teacher.h
        Student.cpp
        Student.h
        Subject.cpp
        Subject.h)
