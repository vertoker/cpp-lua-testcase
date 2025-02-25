#include "LuaState.hpp"

LuaState::LuaState()
{
    state = luaL_newstate();
    luaL_openlibs(state); // open standard Lua libs
}
LuaState::~LuaState()
{
    lua_close(state);
}
