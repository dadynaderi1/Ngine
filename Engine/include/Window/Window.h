//
// Created by dav3n on 10/1/2024.
//

#ifndef NGINE_WINDOW_H
#define NGINE_WINDOW_H
#define GLFW_INCLUDE_VULKAN
#include <spdlog/spdlog.h>

#include <GLFW/glfw3.h>
namespace EngineCore
{
    class Window
    {
    public:
        Window(int width,int height, const char* windowTitle);
        ~Window();
        void initWindow(int width,int height,const char* window_t);
        bool shouldClose(){ return glfwWindowShouldClose(window);}

    private:
        const int Width;
        const int Height;
        const char* Title;
        GLFWwindow *window;
        bool Running = false;

        void createWindowSurface(VkInstance *instance, VkSurfaceKHR *surface);
    };

}


#endif //NGINE_WINDOW_H
