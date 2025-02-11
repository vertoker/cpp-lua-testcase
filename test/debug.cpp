#include "debug/Logger.hpp"
#include "debug/Timer.hpp"

static debug::Logger logger("main");

int main()
{
    debug::Timer timer;
    timer.start();
    logger.info("Start LuaCpp");
    timer.stop();

    logger.info() << "nanoseconds: " << timer.nanoseconds();
    logger.info() << "microseconds: " << timer.microseconds();
    logger.info() << "milliseconds: " << timer.milliseconds();
    logger.info() << "seconds: " << timer.seconds();
    logger.info() << "minutes: " << timer.minutes();
    logger.info() << "hours: " << timer.hours();

    return 0;
}