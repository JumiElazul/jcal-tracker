#include "jcal_core/window_handler.h"
#include "jcal_core/logger.h"
#include <GLFW/glfw3.h>
#include <stdexcept>

namespace jumi
{

    WindowHandler::WindowHandler()
    {
        JUMI_TRACE("WindowHandler constructed");
    }

    WindowHandler::~WindowHandler()
    {
        JUMI_TRACE("WindowHandler destructed");
        JUMI_INFO("glfwTerminate() called");

        glfwTerminate();
    }

    void WindowHandler::init()
    {
        if (!glfwInit())
        {
            throw std::runtime_error("Failed to initialize GLFW");
        }
    }

}
