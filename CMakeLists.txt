cmake_minimum_required(VERSION 3.5)
project(NGine
        LANGUAGES CXX
        VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(App)
add_subdirectory(Engine)