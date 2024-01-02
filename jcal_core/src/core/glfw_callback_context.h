#pragma once

#include <memory>

struct GLFWwindow;

namespace jumi
{
    class GLFWCallbackContextImpl;

    class GLFWCallbackContext
    {
    public:
        GLFWCallbackContext();
        ~GLFWCallbackContext();
        GLFWCallbackContext(const GLFWCallbackContext&) = delete;
        GLFWCallbackContext& operator=(const GLFWCallbackContext&) = delete;
        GLFWCallbackContext(GLFWCallbackContext&&) = delete;
        GLFWCallbackContext& operator=(GLFWCallbackContext&&) = delete;

        void init(GLFWwindow* window);

    private:
        std::unique_ptr<GLFWCallbackContextImpl> _impl;
    };

}
