#include "debug/Logger.hpp"
#include "debug/Timer.hpp"
#include "io/ResourceLoader.hpp"

#include "scripting/LuaWrapper.hpp"

#include <iostream>

static debug::Logger logger("main");

int main()
{
    debug::Timer timer;
    logger.info("Start LuaCpp");
    timer.start();
    
    io::ResourceLoader loader;
    auto data = loader.LoadContent("main.lua");

    LuaState state;
    lua::execute(state, data);
    
    
    timer.stop();
    logger.info("End LuaCpp");

    logger.info() << "Time (microseconds): " << timer.microseconds(); // μs
    logger.info() << "Time (milliseconds): " << timer.milliseconds(); // ms
    logger.info() << "Time (seconds): " << timer.seconds(); // s

    return 0;
}