cmake_minimum_required(VERSION 3.16)
project(ChargepointPlacementFinder C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(src)
enable_testing()
add_subdirectory(test)