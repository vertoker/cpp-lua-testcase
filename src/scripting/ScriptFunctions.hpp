#pragma once

#include "Wrapper.hpp"

namespace script {

    lua::Number add(lua::State* state, const lua::Number a, const lua::Number b);

    void onInitialize(lua::State* state);
    void onDispose(lua::State* state);

} // namespace script
