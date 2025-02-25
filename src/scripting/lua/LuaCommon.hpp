#pragma once

#include <lua.hpp>

#include <stdexcept>
#include <string>

namespace lua
{
    typedef lua_State State;
    typedef lua_Number Number;
    typedef lua_Integer Integer;

    class luaerror : std::runtime_error
    {
    public:
        luaerror(const std::string& message) : std::runtime_error(message) { }
    };
} // namespace lua
