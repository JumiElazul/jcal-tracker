#include "jcal_core/engine_core.h"
#include "jcal_core/window_handler.h"

int main()
{
    jumi::EngineCore& core = jumi::EngineCore::instance();
    jumi::EngineConfig config{ 4, 2 };
    core.init(config);

    const jumi::WindowHandler& window = core.window();

    window.show_window();

    double time = core.time();
    while (time < 4.0)
    {
        time = core.time();
    }

    return 0;
}
