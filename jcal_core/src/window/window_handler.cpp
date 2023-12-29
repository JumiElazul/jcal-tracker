#include "jcal_core/window_handler.h"
#include "jcal_core/logger.h"
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <memory>

namespace jumi
{

    class JUMI_API WindowHandlerImpl
    {
    friend class WindowHandler;
    public:
        WindowHandlerImpl()
        {
            JUMI_TRACE("WindowHandler constructed");
        }

        ~WindowHandlerImpl()
        {
            JUMI_TRACE("WindowHandler destructed");
            JUMI_INFO("glfwTerminate() called");
        }

        WindowHandlerImpl(const WindowHandlerImpl&) = delete;
        WindowHandlerImpl& operator=(const WindowHandlerImpl&) = delete;
        WindowHandlerImpl(WindowHandlerImpl&&) = delete;
        WindowHandlerImpl& operator=(WindowHandlerImpl&&) = delete;

        void init(const int glfw_version_major, const int glfw_version_minor)
        {
            setup_window_hints(glfw_version_major, glfw_version_minor);
            create_window();
            glfwMakeContextCurrent(_window);
        }

        void show_window(bool show = true) const
        {
            show ? JUMI_INFO("Showing window") : JUMI_INFO("Hiding window");
            show ? glfwShowWindow(_window) : glfwHideWindow(_window);
        }

    private:
        GLFWwindow* _window = nullptr;

        void setup_window_hints(const int glfw_version_major, const int glfw_version_minor) const
        {
            JUMI_INFO("Setting up window hints");
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glfw_version_major);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glfw_version_minor);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
            glfwWindowHint(GLFW_SAMPLES, 2);
        }

        void create_window()
        {
            JUMI_INFO("Creating window");
            _window = glfwCreateWindow(800, 500, "jcal-tracker", nullptr, nullptr);

            if (!_window)
            {
                throw std::runtime_error("Failed to create GLFW window");
            }
        }
    };

    WindowHandler::WindowHandler() : _impl(std::make_unique<WindowHandlerImpl>())
    {

    }

    WindowHandler::~WindowHandler() 
    {

    }

    void WindowHandler::init(const int glfw_version_major, const int glfw_version_minor)
    {
        _impl->init(glfw_version_major, glfw_version_minor);
    }

    void WindowHandler::show_window(bool show) const
    {
        _impl->show_window(show);
    }

    void WindowHandler::setup_window_hints(const int glfw_version_major, const int glfw_version_minor) const
    {
        _impl->setup_window_hints(glfw_version_major, glfw_version_minor);
    }

    void WindowHandler::create_window()
    {
        _impl->create_window();
    }
}
