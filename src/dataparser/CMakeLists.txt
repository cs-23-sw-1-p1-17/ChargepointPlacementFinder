add_library(dataparser
        csv_parser.c
        parse_debug.c
)

target_include_directories(dataparser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(dataparser PUBLIC graph)

configure_file(edge_list.csv ${CMAKE_BINARY_DIR}/src/dataparser/edge_list.csv COPYONLY)
configure_file(node_list.csv ${CMAKE_BINARY_DIR}/src/dataparser/node_list.csv COPYONLY)

# Apparently these are needed in the test directory as well
configure_file(edge_list.csv ${CMAKE_BINARY_DIR}/test/dataparser/edge_list.csv COPYONLY)
configure_file(node_list.csv ${CMAKE_BINARY_DIR}/test/dataparser/node_list.csv COPYONLY)
