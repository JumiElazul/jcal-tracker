#pragma once
#include <memory>

namespace jumi
{

    class InputHandlerImpl;

    class InputHandler
    {
    friend class EngineCore;
    public:
        InputHandler();
        ~InputHandler();
        InputHandler(const InputHandler&) = delete;
        InputHandler& operator=(const InputHandler&) = delete;
        InputHandler(InputHandler&&) = delete;
        InputHandler& operator=(InputHandler&&) = delete;

    private:
        std::unique_ptr<InputHandlerImpl> _impl;

        void init();
    };

}
