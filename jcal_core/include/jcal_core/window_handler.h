#pragma once
#include "jcal_core/core.h"

struct GLFWwindow;

namespace jumi
{
    class JUMI_API WindowHandler
    {
    public:
        WindowHandler();
        ~WindowHandler();

        void init();

    private:

        GLFWwindow* _window = nullptr;
    };
}
