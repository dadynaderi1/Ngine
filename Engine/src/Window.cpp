//
// Created by dav3n on 10/1/2024.
//

#include "Window/Window.h"
#include <cstdio>
namespace EngineCore
{
    Window::Window(int width,int height,const char* title) : Height(height),Width(height),Title(title)
    {
        initWindow();

    }
    void Window::initWindow() {

        if (glfwInit() == GLFW_TRUE && glfwVulkanSupported() == GLFW_TRUE) {

        }
    }
    Window::~Window() {};

}
