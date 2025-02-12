#include "debug/Logger.hpp"
#include "debug/Timer.hpp"
#include "io/ResourceLoader.hpp"

#include "scripting/LuaScript.hpp"

#include <iostream>

static debug::Logger logger("main");

int main()
{
    debug::Timer timer;
    logger.info("Start LuaCpp");
    timer.start();
    
    io::ResourceLoader loader;
    auto data = loader.LoadContent("test.lua");
    io::LuaScript script("test", std::move(data));
    script.execute();
    
    timer.stop();
    logger.info("End LuaCpp");

    logger.info() << "Time (microseconds): " << timer.microseconds(); // μs
    logger.info() << "Time (milliseconds): " << timer.milliseconds(); // ms
    logger.info() << "Time (seconds): " << timer.seconds(); // s

    return 0;
}