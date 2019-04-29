set(CMAKE_CXX_FLAGS "-std=c++11")

project(Emp)
add_executable(maze buildMaze.cpp DisjSets.cpp maze.cpp)