#pragma once
#include "jcal_core/core.h"
#include "jcal_core/keycodes.h"
#include <memory>

namespace jumi
{
    class InputHandlerImpl;
    class GLFWCallbackContext;

    class JUMI_API InputHandler
    {
    friend class EngineCore;
    public:
        InputHandler();
        ~InputHandler();
        InputHandler(const InputHandler&) = delete;
        InputHandler& operator=(const InputHandler&) = delete;
        InputHandler(InputHandler&&) = delete;
        InputHandler& operator=(InputHandler&&) = delete;

        void poll_events() const;
        bool is_key_pressed(JUMI_KEYCODE keycode) const;
        void on_key_callback(JUMI_KEYCODE keycode, JUMI_KEYACTION action);

    private:
        std::unique_ptr<InputHandlerImpl> _impl;
        void init();
    };

}
