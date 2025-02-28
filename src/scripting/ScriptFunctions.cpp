#include "ScriptFunctions.hpp"

#include "../debug/Logger.hpp"
static debug::Logger logger("functions");

lua::Number script::add(const LuaState& state, const lua::Number a, const lua::Number b)
{
    if (!lua::TryGetGlobal(state, "add")) return 0;
    
    lua::pushnumber(state, a);
    lua::pushnumber(state, b);
    lua::call(state, 2, 1);

    auto result = lua::tonumber(state);
    lua::pop(state);
    return result;
}

void script::onInitialize(const LuaState& state)
{
    if (lua::TryGetGlobal(state, "onInitialize"))
        lua::call(state);
}
void script::onDispose(const LuaState& state)
{
    if (lua::TryGetGlobal(state, "onDispose"))
        lua::call(state);
}
