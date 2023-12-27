#pragma once
#include "jcal_core/core.h"

struct GLFWwindow;

namespace jumi
{
    class JUMI_API WindowHandler
    {
    public:
        WindowHandler();
        ~WindowHandler();

        void init(const int glfw_version_major, const int glfw_version_minor);
        void show_window(bool show = true) const;

    private:
        GLFWwindow* _window = nullptr;

        void setup_window_hints(const int glfw_version_major, const int glfw_version_minor) const;
        void create_window();
    };
}
