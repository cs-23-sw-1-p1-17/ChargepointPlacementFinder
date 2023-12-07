# add sub dirs
add_subdirectory(dataparser)

# add different functiosn as library to main
add_library(functions graph_functions.c algorithm_functions.c)
target_link_libraries(functions PRIVATE csv_dataparser)
target_include_directories(functions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/dataparser)

# add graph functions as library
#add_library(graph_functions graph_functions.c)
#target_link_libraries(graph_functions PRIVATE dataparser)
#target_include_directories(graph_functions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# add algorithm functions as library
#add_library(algorithm_functions algorithm_functions.c)
#target_include_directories(algorithm_functions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# add main executable
add_executable(main main.c)
target_link_libraries(main PRIVATE functions)#graph_functions algorithm_functions)
