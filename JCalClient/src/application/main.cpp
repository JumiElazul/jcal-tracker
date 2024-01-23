#include "JCalCore/core/app_core.h"
#include <fmt/format.h>

int main()
{
    AppCore& core = AppCore::instance();
    core.show_window(true);

    while (!core.should_quit())
    {
        core.poll_events();

        core.swap_buffers();
    }
}
