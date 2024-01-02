#pragma once
#include "jcal_core/core.h"
#include <memory>

struct GLFWwindow;

namespace jumi
{
    class WindowHandlerImpl;

    class JUMI_API WindowHandler
    {
    friend class EngineCore;

    public:
        WindowHandler();
        ~WindowHandler();
        WindowHandler(const WindowHandler&) = delete;
        WindowHandler& operator=(const WindowHandler&) = delete;
        WindowHandler(WindowHandler&&) = delete;
        WindowHandler& operator=(WindowHandler&&) = delete;

        void show_window(bool show = true) const;
        void swap_buffers() const;
        bool should_close() const;
        void close_window() const;
        GLFWwindow* window() const;

    private:
        std::unique_ptr<WindowHandlerImpl> _impl;

        void init(const int glfw_version_major, const int glfw_version_minor);
        void setup_window_hints(const int glfw_version_major, const int glfw_version_minor) const;
        void create_window();
    };
}
