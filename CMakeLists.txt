cmake_minimum_required(VERSION 3.16)
project(ChargepointPlacementFinder C)

set(CMAKE_C_STANDARD 11)

# add src dir
add_subdirectory(src)
# add test dirs and enable testing
enable_testing()
add_subdirectory(external)
add_subdirectory(test)