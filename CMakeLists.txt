# cmake_minimum_required(VERSION <specify CMake version here>)
project(ROBOT_POMPIER)

set(CMAKE_CXX_STANDARD 14)

add_executable(ROBOT_POMPIER exercice.c dispAllMap.c findFire.c findPathE.c fonctions.h loadMap.c robot.c robotVision.c)