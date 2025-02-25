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

} // namespace lua


