add_library(algorithm
        algorithm_functions.c
)

target_include_directories(algorithm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(algorithm PUBLIC graph)