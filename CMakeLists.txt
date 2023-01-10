cmake_minimum_required(VERSION 3.24)
project(Rubiks_cube)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rubiks_cube main.cpp RubiksCube.cpp RubiksCube.h DFS_SOLVER.h)
