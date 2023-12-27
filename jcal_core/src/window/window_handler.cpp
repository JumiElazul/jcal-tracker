#include "jcal_core/window_handler.h"
#include <iostream>
#include <GLFW/glfw3.h>

namespace jumi
{

    WindowHandler::WindowHandler() { }

    WindowHandler::~WindowHandler()
    {
        std::cout << "WindowHandler::~WindowHandler()\n";
        glfwTerminate();
    }

    void WindowHandler::init()
    {
        std::cout << "WindowHandler::init()\n";

        if (!glfwInit())
        {
            throw std::runtime_error("Failed to initialize GLFW");
        }
        else
        {
            std::cout << "Glfw initialized\n";
        }
    }

}
