#include "glfw_callback_context.h"
#include "jcal_core/logger.h"
#include <memory>
#include <GLFW/glfw3.h>

namespace jumi
{

    class GLFWCallbackContextImpl
    {
    public:
        GLFWCallbackContextImpl()
        {
            register_callbacks();
        }

        ~GLFWCallbackContextImpl()
        {

        }

        GLFWCallbackContextImpl(const GLFWCallbackContextImpl&) = delete;
        GLFWCallbackContextImpl& operator=(const GLFWCallbackContextImpl&) = delete;
        GLFWCallbackContextImpl(GLFWCallbackContextImpl&&) = delete;
        GLFWCallbackContextImpl& operator=(GLFWCallbackContextImpl&&) = delete;

    private:
        void register_callbacks()
        {
            //glfwSetErrorCallback(error_callback);
        }


    };

    void GLFWCallbackContext::error_callback(int error, const char* description)
    {
        JUMI_CRITICAL("GLFW error {}: {}", error, description);
    }

    GLFWCallbackContext::GLFWCallbackContext()
    {
        _impl = std::make_unique<GLFWCallbackContextImpl>();
    }

    GLFWCallbackContext::~GLFWCallbackContext()
    {

    }

}
