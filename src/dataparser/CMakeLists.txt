add_library(dataparser
        csv_parser.c)

target_link_libraries(dataparser graph_functions m)
target_include_directories(dataparser PUBLIC .)
