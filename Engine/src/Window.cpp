//
// Created by dav3n on 10/1/2024.
//

#include "Window/Window.h"

namespace EngineCore
{
    Window::Window(int width,int height,const char* title) : Height(height),Width(height),Title(title)
    {
        initWindow(Width,Height,Title);

    }

    void Window::initWindow(int width, int height, const char *window_t)
    {
        if (glfwInit() == GLFW_TRUE && glfwVulkanSupported() == GLFW_TRUE) {
        spdlog::info("GLFW3 and VULKAN initialised successfully...");
        }else{
        spdlog::error("Initialising failed!");
             }
        glfwWindowHint(GLFW_CLIENT_API,GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);
        window = glfwCreateWindow(width,height,window_t, nullptr, nullptr);
        if(!window){
            spdlog::error("Window creation failed...");
            glfwTerminate();
        } else{
            spdlog::info("Window created successfully...");
        }

        Window::shouldClose();



    }

    void Window::createWindowSurface(VkInstance *instance, VkSurfaceKHR *surface) {
        if(glfwCreateWindowSurface(*instance,window, nullptr,surface) != VK_SUCCESS){
            spdlog::error("Failed to create Vulkan surface");
        }
    }



    Window::~Window() {
        spdlog::warn("Deconstruct requested! Terminating GLFW");
        glfwDestroyWindow(window);
        glfwTerminate();
    }



}

