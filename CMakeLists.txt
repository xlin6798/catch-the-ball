cmake_minimum_required(VERSION 3.10)

project(Spring-22-Game-Engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DOR})

add_subdirectory(Engine)
add_subdirectory(Game)
add_subdirectory(glfw)
