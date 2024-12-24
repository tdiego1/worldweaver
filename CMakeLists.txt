cmake_minimum_required(VERSION 3.16)

set(CMAKE_WARN_DEPRECATED OFF CACHE BOOL "" FORCE)

project(worldweaver VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(code)
add_subdirectory(lib)
