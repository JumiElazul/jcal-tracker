#include "jcal_core/keycodes.h"
#include "jcal_core/engine_core.h"
#include "jcal_core/window_handler.h"
#include "jcal_core/input_handler.h"

int main()
{
    jumi::EngineCore& core = jumi::EngineCore::instance();
    jumi::EngineConfig config{ 4, 2 };
    core.init(config);

    const jumi::WindowHandler& window = core.window();
    const jumi::InputHandler& input = core.input();

    window.show_window();

    double time = 0.0;
    while (!window.should_close())
    {
        time = core.time();
        input.poll_events();

        if (time > 3.0)
        {
            window.close_window();
        }

        window.swap_buffers();
    }

    return 0;
}
