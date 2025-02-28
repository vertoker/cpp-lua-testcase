#include "Scripting.hpp"

#include "../debug/Logger.hpp"
static debug::Logger logger("functions");

lua::State* scripting::state = nullptr;

lua::Number scripting::add(lua::State* state, const lua::Number a, const lua::Number b)
{
    if (!lua::TryGetGlobal(state, "add")) return 0;
    
    lua::pushnumber(state, a);
    lua::pushnumber(state, b);
    lua::call(state, 2, 1);

    auto result = lua::tonumber(state);
    lua::pop(state);
    return result;
}

void scripting::initialize(lua::State* newState)
{
    state = newState;
    if (lua::TryGetGlobal(state, "onInitialize"))
        lua::call(state);
}
void scripting::dispose()
{
    if (lua::TryGetGlobal(state, "onDispose"))
        lua::call(state);
    state = nullptr;
}
