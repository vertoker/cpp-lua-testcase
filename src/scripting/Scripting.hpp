#pragma once

#include "Wrapper.hpp"

namespace scripting {
    extern lua::State* state;

    lua::Number add(lua::State* state, const lua::Number a, const lua::Number b);

    void initialize(lua::State* newState);
    void dispose();

} // namespace script
