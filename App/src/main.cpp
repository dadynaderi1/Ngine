

#include "Window/Window.h"
#include <iostream>
    int main() {
        EngineCore::Window window = EngineCore::Window(600,800,"Davood");
        while (window.shouldClose()== false)
        {
            glfwPollEvents();
        }

        return 0;
    }
