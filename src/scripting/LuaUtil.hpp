#pragma once

#include <lua.hpp>

#include "LuaCommon.hpp"

namespace lua
{
    inline State* newstate()
    {
        return luaL_newstate();
    }
    inline void close(State* state)
    {
        return lua_close(state);
    }

    inline bool isstring(State* L, int idx) {
        return lua_type(L, idx) == LUA_TSTRING;
    }

    inline const char* require_string(State* L, int idx)
    {
        if (!isstring(L, idx))
            throw luaerror("string expected at " + std::to_string(idx));
        return lua_tostring(L, idx);
    }
} // namespace lua


