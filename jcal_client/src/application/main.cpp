#include "jcal_core/engine_core.h"

int main()
{
    jumi::EngineCore& core = jumi::EngineCore::instance();
    core.init();

    return 0;
}
