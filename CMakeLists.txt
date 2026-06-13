cmake_minimum_required(VERSION 3.14)
project(Xwing VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(xwing
    src/main.cpp
    src/Fenetre.cpp
    src/SceneAccueil.cpp
    src/Jeu.cpp
)
target_include_directories(xwing PRIVATE src)
target_link_libraries(xwing PRIVATE sfml-system sfml-window sfml-graphics)
