cmake_minimum_required(VERSION 3.14)
project(Xwing VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Raylib embarqué dans le projet (dossier external/raylib)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

add_subdirectory(external/raylib)

add_executable(xwing src/main.cpp)
target_link_libraries(xwing PRIVATE raylib)
