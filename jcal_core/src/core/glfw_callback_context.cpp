#include "glfw_callback_context.h"
#include "jcal_core/keycodes.h"
#include "jcal_core/logger.h"
#include "jcal_core/input_handler.h"
#include "jcal_core/window_handler.h"
#include <iostream>
#include <memory>
#include <GLFW/glfw3.h>

namespace jumi
{
    class WindowHandler;
    class InputHandler;

    class GLFWCallbackContextImpl
    {
    friend class GLFWCallbackContext;
    public:
        GLFWCallbackContextImpl(WindowHandler& window_handler, InputHandler& input_handler);
        ~GLFWCallbackContextImpl();
        GLFWCallbackContextImpl(const GLFWCallbackContextImpl&) = delete;
        GLFWCallbackContextImpl& operator=(const GLFWCallbackContextImpl&) = delete;
        GLFWCallbackContextImpl(GLFWCallbackContextImpl&&) = delete;
        GLFWCallbackContextImpl& operator=(GLFWCallbackContextImpl&&) = delete;

        void init();
        void register_callbacks(GLFWwindow* window);

    private:
        WindowHandler& _window_handler;
        InputHandler& _input_handler;

        static void error_callback(int error, const char* description);
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    };

    GLFWCallbackContext::GLFWCallbackContext(WindowHandler& window_handler, InputHandler& input_handler)
    {
        _impl = std::make_unique<GLFWCallbackContextImpl>(window_handler, input_handler);
    }

    GLFWCallbackContextImpl::GLFWCallbackContextImpl(WindowHandler& window_handler, InputHandler& input_handler)
        : _window_handler(window_handler), _input_handler(input_handler)
    {

    }

    GLFWCallbackContext::~GLFWCallbackContext()
    {

    }

    GLFWCallbackContextImpl::~GLFWCallbackContextImpl()
    {

    }

    void GLFWCallbackContext::init() { _impl->init(); }
    void GLFWCallbackContextImpl::init()
    {
        GLFWwindow* window = _window_handler.window();
        glfwSetWindowUserPointer(window, this);
        register_callbacks(window);
    }

    void GLFWCallbackContextImpl::register_callbacks(GLFWwindow* window)
    {
        glfwSetErrorCallback(error_callback);
        glfwSetKeyCallback(window, key_callback);
    }

    void GLFWCallbackContextImpl::error_callback(int error, const char* description)
    {
        JUMI_ERROR("GLFW error: {0} - {1}", error, description);
    }

    void GLFWCallbackContextImpl::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
		JUMI_KEYCODE keycode = KeyCodeConverter::glfw_to_jumi_keycode(key);
		JUMI_KEYACTION keyaction = KeyCodeConverter::glfw_to_jumi_keyaction(action);
        GLFWCallbackContextImpl* context = static_cast<GLFWCallbackContextImpl*>(glfwGetWindowUserPointer(window));
        if (context == nullptr)
        {
            JUMI_WARN("GLFWCallbackContextImpl::key_callback() context is null");
            return;
        }
        context->_input_handler.on_key_callback(keycode, keyaction);
    }

}
