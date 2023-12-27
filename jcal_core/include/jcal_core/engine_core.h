#pragma once
#include <jcal_core/core.h>

namespace jumi
{
    class JUMI_API EngineCore
    {
    public:
        EngineCore();
        ~EngineCore();
        EngineCore(const EngineCore&) = delete;
        EngineCore& operator=(const EngineCore&) = delete;
        EngineCore(EngineCore&&) = delete;
        EngineCore& operator=(EngineCore&&) = delete;

        static EngineCore& instance();
        void init();

    private:
    };
}
