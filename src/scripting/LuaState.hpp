#pragma once

#include <string>

#include <lua.hpp>

#include "LuaUtil.hpp"

class LuaState
{
    std::string name;
    std::string script;
    lua::State* state;

public:
    LuaState(std::string name, std::string script);
    ~LuaState();

    LuaState(const LuaState&) = default;
    LuaState(LuaState&&) = default;
    LuaState& operator=(const LuaState&) = default;
    LuaState& operator=(LuaState&&) = default;

    void Execute();
    void ProcessFunctions();
};