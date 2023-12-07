add_subdirectory(dataparser)

add_executable(test_runner test_main.c)

target_link_libraries(test_runner PRIVATE graph_functions algorithm_functions unity_framework)
target_include_directories(test_runner PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_test(NAME test_runner COMMAND test_runner)

