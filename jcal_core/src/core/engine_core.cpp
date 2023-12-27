#include "jcal_core/engine_core.h"
#include "jcal_core/window_handler.h"
#include "jcal_core/logger.h"
#include <memory>

namespace jumi
{

    EngineCore::EngineCore()
    {
        Logger::init();
        JUMI_TRACE("EngineCore constructed");
    }

    EngineCore::~EngineCore()
    {
        JUMI_TRACE("EngineCore destructed");
    }

    EngineCore& EngineCore::instance()
    {
        static EngineCore instance;
        JUMI_TRACE("EngineCore instance()");
        return instance;
    }

    void EngineCore::init()
    {
        JUMI_TRACE("EngineCore init()");

        _window_handler = std::make_unique<WindowHandler>();
        _window_handler->init();
    }

}


