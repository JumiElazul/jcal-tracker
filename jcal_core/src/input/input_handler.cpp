#include "jcal_core/input_handler.h"
#include "jcal_core/logger.h"
#include <memory>
#include <GLFW/glfw3.h>

namespace jumi
{
    class InputHandlerImpl
    {
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

        void init()
        {
            JUMI_TRACE("InputHandlerImpl init()");
        }

    private:

    };

    InputHandler::InputHandler() : _impl(std::make_unique<InputHandlerImpl>()) { }
    InputHandler::~InputHandler() { }

    void InputHandler::init()
    {
        _impl->init();
    }
}
