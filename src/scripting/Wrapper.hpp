#pragma once

#include "lua/LuaWrapper.hpp"

namespace lua
{
    bool TryGetGlobal(const LuaState& state, const std::string& name);
    
} // namespace lua
