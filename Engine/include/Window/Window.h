//
// Created by dav3n on 10/1/2024.
//

#ifndef NGINE_WINDOW_H
#define NGINE_WINDOW_H
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
namespace EngineCore
{
    class Window
    {
    public:
        Window(int width,int height, const char* windowTitle);
        ~Window();

        static void initWindow();

    private:
        const int Width;
        const int Height;
        const char* Title;
    };

}


#endif //NGINE_WINDOW_H
