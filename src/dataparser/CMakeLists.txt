add_library(dataparser
        csv_parser.c
)

target_include_directories(dataparser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(dataparser PUBLIC graph)