#pragma once

#include <memory>

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

    private:
        std::unique_ptr<GLFWCallbackContextImpl> _impl;

        static void error_callback(int error, const char* description);
    };

}
