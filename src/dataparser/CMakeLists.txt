add_library(dataparser
        csv_parser.c)

target_link_libraries(dataparser PRIVATE graph_functions)
