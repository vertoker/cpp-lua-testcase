#include "debug/Logger.hpp"
#include "debug/Timer.hpp"
#include "io/ResourceLoader.hpp"

#include "scripting/ScriptFunctions.hpp"
//#include "scripting/lua/LuaCommon.hpp"

#include <iostream>

static debug::Logger logger("main");

void runScript(lua::State* state);

int main()
{
    debug::Timer timer;
    logger.info("Start LuaCpp");
    timer.start();
    
    io::ResourceLoader loader;
    auto data = loader.LoadContent("main.lua");

    LuaStateObject stateObject;
    lua::State* state = stateObject.getState();
    lua::execute(state, std::move(data));

    script::onInitialize(state);
    runScript(state);
    script::onDispose(state);
    
    timer.stop();
    logger.info("End LuaCpp");

    logger.info() << "Time (microseconds): " << timer.microseconds(); // μs
    logger.info() << "Time (milliseconds): " << timer.milliseconds(); // ms
    logger.info() << "Time (seconds): " << timer.seconds(); // s

    return 0;
}

void runScript(lua::State* state)
{
    logger.info() << script::add(state, 4, 5);
}
