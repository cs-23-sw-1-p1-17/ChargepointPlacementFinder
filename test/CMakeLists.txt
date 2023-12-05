add_executable(
        test_runner
        test_main.c
        ../external/unity.c # unity test framework
)

target_link_libraries(test_runner m)

add_test(NAME test_runner COMMAND test_runner)

add_subdirectory(dataparser)