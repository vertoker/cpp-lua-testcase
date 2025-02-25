#pragma once

#include "lua/LuaWrapper.hpp"

namespace lua
{
    void GetGlobal(const LuaState& state, const std::string& name);
    
} // namespace lua
