cmake_minimum_required(VERSION 3.10)
project(tetris)

find_package(fmt REQUIRED)
find_package(SDL2 REQUIRED)

add_executable(tetris main.cpp src/renderer.cpp)
target_link_libraries(tetris fmt::fmt ${SDL2_LIBRARIES})
include_directories(tetris ${SDL2_INCLUDE_DIRS})