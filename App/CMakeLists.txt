cmake_minimum_required(VERSION 3.5)
project(Editor
        LANGUAGES CXX
        VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
                src/main.cpp)

target_link_libraries(${PROJECT_NAME} NGine_Core  )
target_include_directories(${PROJECT_NAME} PRIVATE NGine_Core OpenGL::GL libglew_static)

