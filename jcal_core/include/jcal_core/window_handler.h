#pragma once
#include "jcal_core/core.h"
#include <memory>

struct GLFWwindow;

namespace jumi
{
    class WindowHandlerImpl;

    class JUMI_API WindowHandler
    {
    public:
        WindowHandler();
        ~WindowHandler();

        void init(const int glfw_version_major, const int glfw_version_minor);
        void show_window(bool show = true) const;

    private:
        std::unique_ptr<WindowHandlerImpl> _impl;

        void setup_window_hints(const int glfw_version_major, const int glfw_version_minor) const;
        void create_window();
    };
}
