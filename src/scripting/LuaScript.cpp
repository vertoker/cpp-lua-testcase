#include "LuaScript.hpp"

#include "../debug/Logger.hpp"

using namespace io;

static debug::Logger logger("lua");

LuaScript::LuaScript(std::string name, std::string script)
    : name(std::move(name)), script(std::move(script))
{
    state = luaL_newstate();
    luaL_openlibs(state); // open standard Lua libs
}
LuaScript::~LuaScript()
{
    lua_close(state);
}

void LuaScript::execute()
{
    logger.info() << "execute Lua script: " << name;
    luaL_dostring(state, script.c_str()); // execute Lua code
}
