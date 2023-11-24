add_executable(main main.c
        graph_functions.h
        graph_functions.c)
target_link_libraries(main m)

add_subdirectory(dataparser)