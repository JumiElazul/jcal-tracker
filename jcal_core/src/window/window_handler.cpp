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

    void WindowHandler::init(const int glfw_version_major, const int glfw_version_minor)
    {
        setup_window_hints(glfw_version_major, glfw_version_minor);
        create_window();
        glfwMakeContextCurrent(_window);
    }

    void WindowHandler::setup_window_hints(const int glfw_version_major, const int glfw_version_minor) const
    {
        JUMI_INFO("Setting up window hints");
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glfw_version_major);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glfw_version_minor);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
        glfwWindowHint(GLFW_SAMPLES, 2);
    }

    void WindowHandler::create_window()
    {
        JUMI_INFO("Creating window");
        _window = glfwCreateWindow(800, 500, "jcal-tracker", nullptr, nullptr);

        if (!_window)
        {
            throw std::runtime_error("Failed to create GLFW window");
        }
    }

    void WindowHandler::show_window(bool show) const
    {
        show ? JUMI_INFO("Showing window") : JUMI_INFO("Hiding window");
        show ? glfwShowWindow(_window) : glfwHideWindow(_window);
    }

}
