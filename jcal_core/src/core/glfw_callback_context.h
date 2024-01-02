#pragma once

#include <memory>

struct GLFWwindow;

namespace jumi
{
    class GLFWCallbackContextImpl;
    class WindowHandler;
    class InputHandler;

    class GLFWCallbackContext
    {
    public:
        GLFWCallbackContext(WindowHandler& window_handler, InputHandler& input_handler);
        ~GLFWCallbackContext();
        GLFWCallbackContext(const GLFWCallbackContext&) = delete;
        GLFWCallbackContext& operator=(const GLFWCallbackContext&) = delete;
        GLFWCallbackContext(GLFWCallbackContext&&) = delete;
        GLFWCallbackContext& operator=(GLFWCallbackContext&&) = delete;

        void init();

    private:
        std::unique_ptr<GLFWCallbackContextImpl> _impl;
    };

}
