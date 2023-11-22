cmake_minimum_required(VERSION 3.26)
project(sem_proj_1 C)
cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_STANDARD 11)

add_subdirectory(src)
enable_testing()
add_subdirectory(test)