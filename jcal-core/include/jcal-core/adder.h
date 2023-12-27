#pragma once
#include "core.h"

namespace jumi
{

    class JUMI_API Adder
    {
    public:
        Adder() = default;
        ~Adder() = default;

        int add(int a, int b);

    private:
    };

}
