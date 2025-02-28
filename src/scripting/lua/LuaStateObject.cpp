#include "LuaStateObject.hpp"

#include "libs/API.hpp"

LuaStateObject::LuaStateObject()
{
    state = luaL_newstate();
    CreateLibs();
}
LuaStateObject::~LuaStateObject()
{
    lua_close(state);
}

LuaStateObject::LuaStateObject(LuaStateObject&& other) : state{other.state}
{
    other.state = nullptr;
}
LuaStateObject& LuaStateObject::operator=(LuaStateObject&& other)
{
    if (&other == this) return *this;

    lua_close(state);
    state = other.state;
    other.state = nullptr;
    return *this;
}

void LuaStateObject::CreateLibs()
{
    luaL_openlibs(state);
    lua::openlib(state, "log", loglib);
    lua::openlib(state, "script", scriptlib);
}
