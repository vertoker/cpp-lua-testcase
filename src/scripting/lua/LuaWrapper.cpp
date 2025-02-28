#include "LuaWrapper.hpp"

void lua::openlib(lua::State* state, const std::string& name, const luaL_Reg* lib)
{
    createtable(state);
    setfuncs(state, lib);
    setglobal(state, name.c_str());
}