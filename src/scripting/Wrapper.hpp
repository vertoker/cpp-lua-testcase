#pragma once

#include "lua/LuaStateObject.hpp"

namespace lua
{
    bool TryGetGlobal(lua::State* state, const std::string& name);
    
} // namespace lua
