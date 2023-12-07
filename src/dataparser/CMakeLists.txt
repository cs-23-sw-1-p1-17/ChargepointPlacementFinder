add_library(csv_dataparser csv_parser.c)
target_include_directories(csv_dataparser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
