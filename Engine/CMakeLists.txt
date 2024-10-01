cmake_minimum_required(VERSION 3.7)
project(NGine_Core
        LANGUAGES CXX
        VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#adding 3rd party libs

add_subdirectory(external/glfw)
add_subdirectory(external/glm)
add_subdirectory(external/spdlog)

if (NOT CMAKE_VERSION VERSION_LESS 3.7.0)
    message(STATUS "Using module to find Vulkan")
    find_package(Vulkan)
endif()
message(STATUS "Path to Vulkan lib: ${Vulkan_LIBRARIES}")
message(STATUS "Path to Vulkan include: ${Vulkan_INCLUDE_DIR}")



add_library(${PROJECT_NAME} src/Engine.cpp src/Window.cpp)



target_include_directories(${PROJECT_NAME}
        PUBLIC
        include
        Vulkan_LIBRARIES

        glfw
        glm)



target_link_libraries(${PROJECT_NAME}
        PUBLIC
        glm
        Vulkan::Vulkan
        glfw



)
