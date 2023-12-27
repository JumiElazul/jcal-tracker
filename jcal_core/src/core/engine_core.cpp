#include "jcal_core/engine_core.h"
#include "jcal_core/window_handler.h"
#include <iostream>
#include <memory>

namespace jumi
{

    EngineCore::EngineCore() { }
    EngineCore::~EngineCore() { }

    EngineCore& EngineCore::instance()
    {
        static EngineCore instance;
        return instance;
    }

    void EngineCore::init()
    {
        std::cout << "EngineCore::init()\n";
        _window_handler = std::make_unique<WindowHandler>();
        _window_handler->init();
    }

}


