cmake_minimum_required(VERSION 3.10)  # Minimum required CMake version (adjust if needed)
project(Tetris-with-SDL2)

# Find SDL2 library
find_package(SDL2 REQUIRED)

# Include directories
include_directories(BEFORE header)

# Define your executable
add_executable(Sandtris src/main.cpp)

# Link with SDL2 libraries
target_link_libraries(Sandtris PUBLIC SDL2main SDL2 SDL2_image SDL2_mixer SDL2_ttf)
