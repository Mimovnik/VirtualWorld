cmake_minimum_required(VERSION 3.0.0)
project(virtualWorld VERSION 0.1.0)

add_library(
    SOURCE_FILES

    src/World.hpp
    src/World.cpp
)

add_executable(virtualWorld src/main.cpp)

target_link_libraries(${PROJECT_NAME} SOURCE_FILES)
