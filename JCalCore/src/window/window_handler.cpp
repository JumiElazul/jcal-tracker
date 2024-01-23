#include "window/window_handler.h"
#include <GLFW/glfw3.h>

WindowHandler::~WindowHandler()
{
    if (_main_window)
    {
        glfwDestroyWindow(_main_window);
    }
}

void WindowHandler::init(const Vec2& window_size)
{
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_VERSION_MINOR, 6);

    _main_window = glfwCreateWindow(window_size.x, window_size.y, "JCal-Tracker", nullptr, nullptr);
    glfwMakeContextCurrent(_main_window);
}

GLFWwindow* WindowHandler::get_window() const { return _main_window; }

void WindowHandler::show_window(bool show) const
{
    if (show)
        glfwShowWindow(_main_window);
    else
        glfwHideWindow(_main_window);
}
