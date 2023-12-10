add_library(graph
        graph_functions.c
)

target_include_directories(graph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})