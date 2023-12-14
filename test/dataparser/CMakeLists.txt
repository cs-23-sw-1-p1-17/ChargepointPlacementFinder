add_executable(test_csv_parser test_csv_parser.c)
target_link_libraries(test_csv_parser PUBLIC dataparser unity_framework)
add_test(NAME test_csv_parser COMMAND test_csv_parser)

configure_file(test_edges.csv ${CMAKE_BINARY_DIR}/test/dataparser/test_edges.csv COPYONLY)
configure_file(test_nodes.csv ${CMAKE_BINARY_DIR}/test/dataparser/test_nodes.csv COPYONLY)
