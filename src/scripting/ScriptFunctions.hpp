#pragma once

#include "Wrapper.hpp"

namespace script {

    lua::Number add(const LuaState& state, const lua::Number a, const lua::Number b);

} // namespace script
