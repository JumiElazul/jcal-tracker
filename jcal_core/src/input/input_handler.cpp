#include "jcal_core/input_handler.h"
#include "jcal_core/keycodes.h"
#include "jcal_core/logger.h"
#include <memory>
#include <GLFW/glfw3.h>

namespace jumi
{
    class InputHandlerImpl
    {
    friend class InputHandler;
    friend class GLFWCallbackContext;
    public:
        InputHandlerImpl()
        {

        }

        ~InputHandlerImpl()
        {

        }

        InputHandlerImpl(const InputHandlerImpl&) = delete;
        InputHandlerImpl& operator=(const InputHandlerImpl&) = delete;
        InputHandlerImpl(InputHandlerImpl&&) = delete;
        InputHandlerImpl& operator=(InputHandlerImpl&&) = delete;

        void poll_events() const;
        bool is_key_pressed(JUMI_KEYCODE keycode) const;

    private:
        void init();
        void on_key_callback(JUMI_KEYCODE keycode, JUMI_KEYACTION action);
        static const std::string _action_to_string[];
    };

    const std::string InputHandlerImpl::_action_to_string[] = { "released", "pressed", "repeated" };

    InputHandler::InputHandler() : _impl(std::make_unique<InputHandlerImpl>()) { }
    InputHandler::~InputHandler() { }

    void InputHandler::init() { _impl->init(); }
    void InputHandlerImpl::init()
    {
        JUMI_TRACE("InputHandlerImpl init()");
    }

    void InputHandler::on_key_callback(JUMI_KEYCODE keycode, JUMI_KEYACTION action) { _impl->on_key_callback(keycode, action); }
    void InputHandlerImpl::on_key_callback(JUMI_KEYCODE keycode, JUMI_KEYACTION action)
    {
        JUMI_TRACE("Key {} was {}", keycode, _action_to_string[action]);
    }

    void InputHandler::poll_events() const { _impl->poll_events(); }
    void InputHandlerImpl::poll_events() const
    {
        glfwPollEvents();
    }

    bool InputHandler::is_key_pressed() const { _impl->is_key_pressed(); }
    bool InputHandlerImpl::is_key_pressed(JUMI_KEYCODE keycode) const
    {

    }

}
