cmake_minimum_required(VERSION 3.24)
project(Miron)

set(CMAKE_CXX_STANDARD 20)

add_executable(Find_loop Graphs/Find_loop/find_loop.cpp)
add_executable(Find_loop_v2 Graphs/Find_loop/find_loop_v2.cpp)
add_executable(Find_loop_correct Graphs/Find_loop/find_loops_correct.cpp)
add_executable(Baobab Graphs/Baobab/Baobab.cpp)
add_executable(Shortest_path Graphs/Shortest_path/Shortest_path.cpp)
add_executable(Shortest_path_length Graphs/Shortest_path_length/Shortest_path_length.cpp)
add_executable(Solders Graphs/Solders/solders.cpp)
add_executable(Shortest_path_AB Graphs/Shortest_path_AB/shortes_path_ab.cpp)
add_executable(Shortest_path_AB_new Graphs/Shortest_path_AB/shortest_path_ab_new.cpp)
add_executable(Dijkstra_path Graphs/Dijkstra_path/dijkstra_path.cpp)
add_executable(Details Graphs/Details_engine/details.cpp)
add_executable(DFS Graphs/DFS/dfs.cpp)

add_executable(Floyd_1 Graphs/Floyd_Ford_Bellman/Floyd_1/floyd.cpp)
add_executable(The_longest_path Graphs/Floyd_Ford_Bellman/The_longest_path/longest_path.cpp)
add_executable(Transitive_closure Graphs/Floyd_Ford_Bellman/Transitive_closure/transitive_closure.cpp)
add_executable(Dangerous_path_test Graphs/Floyd_Ford_Bellman/Dangerous_path/test.cpp)
add_executable(Dangerous_path Graphs/Floyd_Ford_Bellman/Dangerous_path/dangerous_path.cpp)
add_executable(Ford_Bellman Graphs/Floyd_Ford_Bellman/Ford_Bellman/ford_bellman.cpp)
add_executable(Path_by_time Graphs/Floyd_Ford_Bellman/Paths_by_time/paths_by_time.cpp)
add_executable(Labyrinth Graphs/Floyd_Ford_Bellman/Labirint/labirint.cpp)

add_subdirectory(Graphs/Boruvka)
add_subdirectory(Binary_heap)
add_subdirectory(Polyakov-Eremin)
add_subdirectory(RMQ)
add_subdirectory(Decart_tree)
add_subdirectory(DynProg)

add_subdirectory(OOP)
