#pragma once

#include <lua.hpp>

#include "LuaCommon.hpp"

#include <string>

namespace lua
{
    inline void execute(lua::State* state, const std::string& str)
        { luaL_dostring(state, str.c_str()); }

    inline void getglobal(lua::State* state, const char* str)
        { lua_getglobal(state, str); }
    inline void setglobal(lua::State* state, const char* str)
        { lua_setglobal(state, str); }
    
    inline bool isnil(lua::State* state)
        { return lua_isnil(state, -1); }

    inline void pushnumber(lua::State* state, lua::Number number)
        { return lua_pushnumber(state, number); }
    inline void pushinteger(lua::State* state, lua::Integer integer)
        { return lua_pushinteger(state, integer); }
    inline void pushboolean(lua::State* state, bool boolean)
        { return lua_pushboolean(state, boolean); }

    inline void call(lua::State* state, int numArgs = 0, int numResults = 0)
        { lua_call(state, numArgs, numResults); }

    inline lua::Number tonumber(lua::State* state, int stackIndex = -1)
        { return lua_tonumber(state, stackIndex); }
    inline lua::Integer tointeger(lua::State* state, int stackIndex = -1)
        { return lua_tointeger(state, stackIndex); }
    inline bool toboolean(lua::State* state, int stackIndex = -1)
        { return lua_toboolean(state, stackIndex); }
    inline const char* tostring(lua::State* L, int stackIndex = -1)
        { return lua_tostring(L, stackIndex); }

    inline void pop(lua::State* state, int count = 1)
        { return lua_pop(state, count); }

    inline void createtable(lua::State* state, int narr = 0, int nrec = 0)
        { lua_createtable(state, narr, nrec); }
    inline void setfuncs(lua::State* state, const luaL_Reg* lib, int nup = 0)
        { luaL_setfuncs(state, lib, nup); }

    inline void openlibs(lua::State* state)
        { luaL_openlibs(state); }
    void openlib(lua::State* state, const std::string& name, const luaL_Reg* lib);

} // namespace lua


