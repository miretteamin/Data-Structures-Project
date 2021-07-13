cmake_minimum_required(VERSION 3.19)
project(Data_Structures_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(Project)

add_executable(Data_Structures_Project
        Project/List.cpp
        Project/List.h
        Project/main.cpp
        Project/User.cpp
        Project/TreapTree.cpp)
