#pragma once

#include <string>

#include <lua.hpp>

namespace io
{
    class LuaScript
    {
        std::string script;
        lua_State* state;

    public:
        LuaScript(std::string script);
        ~LuaScript();

        LuaScript(const LuaScript&) = default;
        LuaScript(LuaScript&&) = default;
        LuaScript& operator=(const LuaScript&) = default;
        LuaScript& operator=(LuaScript&&) = default;

        void execute();
    };
} // namespace io
