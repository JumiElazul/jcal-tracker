#include "glfw_callback_context.h"
#include "jcal_core/logger.h"
#include <memory>
#include <GLFW/glfw3.h>

namespace jumi
{

    class GLFWCallbackContextImpl
    {
    friend class GLFWCallbackContext;
    public:
        GLFWCallbackContextImpl();
        ~GLFWCallbackContextImpl();
        GLFWCallbackContextImpl(const GLFWCallbackContextImpl&) = delete;
        GLFWCallbackContextImpl& operator=(const GLFWCallbackContextImpl&) = delete;
        GLFWCallbackContextImpl(GLFWCallbackContextImpl&&) = delete;
        GLFWCallbackContextImpl& operator=(GLFWCallbackContextImpl&&) = delete;

        void init(GLFWwindow* window);
        void register_callbacks(GLFWwindow* window);

    private:
        static void error_callback(int error, const char* description);
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    };

    GLFWCallbackContext::GLFWCallbackContext()
    {
        _impl = std::make_unique<GLFWCallbackContextImpl>();
    }

    GLFWCallbackContextImpl::GLFWCallbackContextImpl()
    {

    }

    GLFWCallbackContext::~GLFWCallbackContext()
    {

    }

    GLFWCallbackContextImpl::~GLFWCallbackContextImpl()
    {

    }

    void GLFWCallbackContextImpl::register_callbacks(GLFWwindow* window)
    {
        glfwSetErrorCallback(error_callback);
        glfwSetKeyCallback(window, key_callback);
    }

    void GLFWCallbackContext::init(GLFWwindow* window) { _impl->init(window); }
    void GLFWCallbackContextImpl::init(GLFWwindow* window)
    {
        glfwSetWindowUserPointer(window, this);
        register_callbacks(window);
    }

    void GLFWCallbackContextImpl::error_callback(int error, const char* description)
    {
        JUMI_ERROR("GLFW error: {0} - {1}", error, description);
    }

    void GLFWCallbackContextImpl::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        JUMI_TRACE("Key {} was {}", key, action);
    }

}
