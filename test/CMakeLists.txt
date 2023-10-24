add_executable(test_runner test_main.c)
target_link_libraries(test_runner m)

add_test(NAME test_runner COMMAND test_runner)