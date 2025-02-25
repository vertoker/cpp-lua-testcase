#pragma once

#include <lua.hpp>

#include "LuaCommon.hpp"

class LuaState
{
    lua::State* state;

public:
    LuaState();
    ~LuaState();

    LuaState(const LuaState&) = default;
    LuaState(LuaState&&) = default;
    LuaState& operator=(const LuaState&) = default;
    LuaState& operator=(LuaState&&) = default;

    inline lua::State* getState() const { return state; }
};
