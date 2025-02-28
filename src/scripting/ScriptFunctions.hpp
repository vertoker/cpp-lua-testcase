#pragma once

#include "Wrapper.hpp"

namespace script {

    lua::Number add(const LuaState& state, const lua::Number a, const lua::Number b);

    void onInitialize(const LuaState& state);
    void onDispose(const LuaState& state);

} // namespace script
