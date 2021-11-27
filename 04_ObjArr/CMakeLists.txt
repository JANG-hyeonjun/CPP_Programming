cmake_minimum_required(VERSION 3.20)
project(04_ObjArr)

set(CMAKE_CXX_STANDARD 14)

add_executable(04_ObjArr main.cpp)
include_directories(/Users/janghyeonjun/Desktop/CPP_Programming/04_ObjArr/Include)
target_link_libraries(04_ObjArr /Users/janghyeonjun/Desktop/CPP_Programming/04_ObjArr/lib/x64/Debug/OpenMeshCored.lib)
target_link_libraries(04_ObjArr /Users/janghyeonjun/Desktop/CPP_Programming/04_ObjArr/lib/x64/Debug/OpenMeshToolsd.lib)