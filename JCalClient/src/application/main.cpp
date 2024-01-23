#include "JCalCore/core/app_core.h"
#include "JCalCore/core/keycodes.h"
#include <fmt/format.h>

int main()
{
    AppCore& core = AppCore::instance();
    core.show_window(true);
    core.set_clear_color({ 1.0f, 0.0f, 0.0f });

    while (!core.should_quit())
    {
        core.poll_events();
        core.clear_color();
        core.draw_gui();
        core.swap_buffers();
    }
}
