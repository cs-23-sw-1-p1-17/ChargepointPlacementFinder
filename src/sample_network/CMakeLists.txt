add_library(sample_network
        sample_network.c
)

target_include_directories(sample_network PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(dataparser PUBLIC graph)
