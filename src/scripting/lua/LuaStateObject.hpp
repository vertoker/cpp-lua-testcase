#pragma once

#include <lua.hpp>

#include "LuaWrapper.hpp"

class LuaStateObject
{
    lua::State* state;

public:
    LuaStateObject();
    ~LuaStateObject();

    LuaStateObject(const LuaStateObject&) = delete;
    LuaStateObject(LuaStateObject&&);
    LuaStateObject& operator=(const LuaStateObject&) = delete;
    LuaStateObject& operator=(LuaStateObject&&);

    inline lua::State* getState() const { return state; }

private:
    void CreateLibs();
};
