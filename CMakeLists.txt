cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED_ON)


project(hello VERSION 1.0)

add_library(canvas STATIC src/canvas.cpp)
target_include_directories(canvas PUBLIC src/)


add_executable(raytracer src/main.cpp)
target_link_libraries(raytracer PRIVATE canvas)


