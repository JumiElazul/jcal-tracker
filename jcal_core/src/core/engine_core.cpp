#include "jcal_core/engine_core.h"
#include <iostream>

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
    }

}


