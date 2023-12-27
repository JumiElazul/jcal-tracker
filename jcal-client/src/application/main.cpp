#include <iostream>
#include "adder.h"

int main()
{
    jumi::Adder adder;
    std::cout << adder.add(2, 7) << '\n';

    return 0;
}
