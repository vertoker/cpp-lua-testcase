#include "LuaState.hpp"

#include "../debug/Logger.hpp"

static debug::Logger logger("lua-state");

LuaState::LuaState(std::string name, std::string script)
    : name(std::move(name)), script(std::move(script))
{
    state = lua::newstate();
    luaL_openlibs(state); // open standard Lua libs
}
LuaState::~LuaState()
{
    lua::close(state);
}

void LuaState::Execute()
{
    logger.info() << "execute Lua script: " << name;
    luaL_dostring(state, script.c_str()); // execute Lua code
}
void LuaState::ProcessFunctions()
{
    logger.info() << "process functions in Lua script: " << name;
    lua_getglobal(state, "add");
    lua_pushnumber(state, 10);
    lua_pushnumber(state, 20);
    lua_call(state, 2, 1);
    logger.info() << lua_tonumber(state, -1);
    lua_pop(state, 1);
}
