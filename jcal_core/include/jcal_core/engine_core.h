#pragma once
#include <jcal_core/core.h>
#include <memory>

namespace jumi
{
    class WindowHandler;

    class JUMI_API EngineCore
    {
    public:
        EngineCore();
        ~EngineCore();
        EngineCore(const EngineCore&) = delete;
        EngineCore& operator=(const EngineCore&) = delete;
        EngineCore(EngineCore&&) = delete;
        EngineCore& operator=(EngineCore&&) = delete;

        static std::unique_ptr<WindowHandler> create_window_handler();
        static EngineCore& instance();
        void init();

    private:
        std::unique_ptr<WindowHandler> _window_handler;
    };
}
