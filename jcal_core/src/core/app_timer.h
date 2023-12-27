#pragma once

namespace jumi
{
    namespace timers
    {
        class AppTimer
        {
        friend class EngineCore;

        public:
            AppTimer();
            ~AppTimer();

            double time_since_init();

        private:
            double _current_time = 0.0;
            double _delta_time = 0.0;

            void advance_frame();
        };
    }
}
