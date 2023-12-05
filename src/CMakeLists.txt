add_library(graph_functions graph_functions.c)
target_link_libraries(graph_functions m)
target_include_directories(graph_functions PUBLIC .)

add_library(algorithm_functions algorithm_functions.c)
target_link_libraries(algorithm_functions m)
target_include_directories(algorithm_functions PUBLIC .)

add_executable(main main.c)
target_link_libraries(main m)