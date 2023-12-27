#include "app_timer.h"
#include "jcal_core/logger.h"
#include <GLFW/glfw3.h>

namespace jumi
{
    namespace timers
    {

        AppTimer::AppTimer()
        {
            JUMI_TRACE("AppTimer constructed");
        }

        AppTimer::~AppTimer()
        {
            JUMI_TRACE("AppTimer destructed");
        }

        void AppTimer::advance_frame()
        {
            JUMI_TRACE("AppTimer advance_frame()");
            // TODO: Once I figure out where the main loop will be, I'll need to calculate delta time here
        }

        double AppTimer::time_since_init()
        {
            _current_time = glfwGetTime();
            return _current_time;
        }

    }
}
