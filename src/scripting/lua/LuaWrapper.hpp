#pragma once

#include <lua.hpp>

#include "LuaState.hpp"

#include <string>

namespace lua
{
    inline void execute(const LuaState& state, const std::string& str)
    {
        luaL_dostring(state.getState(), str.c_str());
    }

    inline void getglobal(const LuaState& state, const char* str)
    {
        lua_getglobal(state.getState(), str);
    }
    
    inline bool isnil(const LuaState& state)
    {
        return lua_isnil(state.getState(), -1);
    }

    inline void pushnumber(const LuaState& state, lua::Number number)
    {
        return lua_pushnumber(state.getState(), number);
    }
    inline void pushinteger(const LuaState& state, lua::Integer integer)
    {
        return lua_pushinteger(state.getState(), integer);
    }
    inline void pushboolean(const LuaState& state, bool boolean)
    {
        return lua_pushboolean(state.getState(), boolean);
    }

    inline void call(const LuaState& state, int numArgs = 0, int numResults = 0)
    {
        lua_call(state.getState(), numArgs, numResults);
    }

    inline lua::Number tonumber(const LuaState& state, int stackIndex = -1)
    {
        return lua_tonumber(state.getState(), stackIndex);
    }
    inline lua::Integer tointeger(const LuaState& state, int stackIndex = -1)
    {
        return lua_tointeger(state.getState(), stackIndex);
    }
    inline bool toboolean(const LuaState& state, int stackIndex = -1)
    {
        return lua_toboolean(state.getState(), stackIndex);
    }

    inline void pop(const LuaState& state, int count = 1)
    {
        return lua_pop(state.getState(), count);
    }

} // namespace lua


