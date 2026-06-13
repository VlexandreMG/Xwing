cmake_minimum_required(VERSION 3.15)
project(Xwing VERSION 1.0 LANGUAGES CXX)

# Force l'utilisation de C++17 (très bien pour la SFML)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Trouver la SFML installée sur ton Linux
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# 2. Détecter automatiquement tous les fichiers .cpp dans src/
file(GLOB_RECURSIVE SOURCES "src/*.cpp")

# 3. Définir le nom de ton exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# 4. Dire à CMake où chercher les fichiers .hpp (pour l'instant dans src)
target_include_directories(${PROJECT_NAME} PUBLIC inculde)

# 5. Lier la SFML à ton jeu
target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-window sfml-system)