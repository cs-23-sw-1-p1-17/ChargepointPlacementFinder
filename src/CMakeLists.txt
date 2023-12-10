# General library
add_subdirectory(graph)

# Dataparser utility (dependent on graph)
add_subdirectory(dataparser)

# Sample networks hardcoded (dependent on graph)
add_subdirectory(sample_network)

# Algorithm library (dependent on graph)
add_subdirectory(algorithm)

# add main executable
add_executable(main main.c)
target_link_libraries(main PRIVATE algorithm)
