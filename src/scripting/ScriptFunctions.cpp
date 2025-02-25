#include "ScriptFunctions.hpp"

#include "../debug/Logger.hpp"
static debug::Logger logger("functions");

lua::Number script::add(const LuaState& state, const lua::Number a, const lua::Number b)
{
    lua::GetGlobal(state, "add");
    
    
    /*logger.info() << "process functions in Lua script: " << name;
    lua_getglobal(state, "add");
    lua_pushnumber(state, 10);
    lua_pushnumber(state, 20);
    lua_call(state, 2, 1);
    logger.info() << lua_tonumber(state, -1);
    lua_pop(state, 1);*/
}
