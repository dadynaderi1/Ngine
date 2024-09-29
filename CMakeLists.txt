cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(NGine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(ExternalProject)
# Deps
set_property(DIRECTORY PROPERTY EP_BASE ${CMAKE_SOURCE_DIR}/Deps)

set(STAGED_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/stage)
set(EP_SOURCE_DIR_PREFIX ${CMAKE_BINARY_DIR}/Deps/Source)

add_subdirectory(ThirdParty)



ExternalProject_Add(${PROJECT_NAME}_Core
        DEPENDS GLFW_internal GLEW_internal 
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Core
        CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DSTAGED_INSTALL_PREFIX=${STAGED_INSTALL_PREFIX}
        CMAKE_CACHE_ARGS
        -DCMAKE_PREFIX_PATH:PATH=${CMAKE_PREFIX_PATH}
        BUILD_ALWAYS ON
        INSTALL_COMMAND ""
)
############################################################
