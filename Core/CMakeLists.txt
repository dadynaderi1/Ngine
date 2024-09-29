cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(NGine_Core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(TO_NATIVE_PATH "${STAGED_INSTALL_PREFIX}/lib/cmake/glfw3" glfw3_DIR)
file(TO_NATIVE_PATH "${STAGED_INSTALL_PREFIX}/lib/cmake/glew" GLEW_DIR)

message(STATUS "glfw3_DIR is... ${glfw3_DIR}")
message(STATUS "GLEW_DIR is... ${GLEW_DIR}")

find_package(glfw3 REQUIRED CONFIG)

set(GLEW_USE_STATIC_LIBS ON)
find_package(GLEW REQUIRED CONFIG)

include_directories(include)
include_directories({CMAKE_SOURCE_DIR}/build/stage/bin/build/stage/include)


set(SRCS
        src/main.cpp)

if(APPLE)

    add_executable(main MACOSX_BUNDLE src/main.cpp)

    
    set_target_properties(main PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
else()

    add_executable(main src/main.cpp
                     )
endif()

target_link_libraries(main PRIVATE GLEW::glew_s glfw)