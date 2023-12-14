add_library(console_output
        print_function.c
)

target_include_directories(console_output PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(console_output PUBLIC algorithm)