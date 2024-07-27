
#include "sg_logging.hpp"
#include <cstdio>

int main()
{
    initLogging("logs/snowglobe.log");

    for (int i = 0; i < 5; i++)
    {
        logInfo("Hello, World {}", i);
        logWarn("Hello, World {}", i);
        logError("Hello, World {}", i);
    }

    logBacktrace();
}
