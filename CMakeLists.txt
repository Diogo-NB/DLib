cmake_minimum_required(VERSION 3.22.1)
project(DLib)

set (FullOutputDir "${CMAKE_SOURCE_DIR}/bin")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static libs")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")

include_directories(src/list_lib src/graph_lib src/avl_tree_lib src/key_value_lib)
include_directories(src)

add_library(list_lib src/list_lib/list.c src/list_lib/stack.c src/list_lib/queue.c)
target_include_directories(list_lib PRIVATE src/list_lib)

add_library(graph_lib src/graph_lib/graph.c src/graph_lib/vertices.c src/graph_lib/edges.c src/graph_lib/dijkstra_alg.c src/graph_lib/vertices.c src/graph_lib/graph_traversal.c)
target_include_directories(graph_lib PRIVATE src/graph_lib)
target_link_libraries(graph_lib list_lib)

add_library(avl_tree_lib src/avl_tree_lib/avl_tree.c src/avl_tree_lib/avl_tree_traversal.c)
target_include_directories(avl_tree_lib PRIVATE src/avl_tree_lib)
target_link_libraries(avl_tree_lib list_lib)

add_library(key_value_lib src/key_value_lib/key_value.c src/key_value_lib/kv_sort.c)
target_include_directories(key_value_lib PRIVATE src/key_value_lib)