#include "Wrapper.hpp"

#include "../debug/Logger.hpp"
static debug::Logger logger("lua-wrapper");

bool lua::TryGetGlobal(lua::State* state, const std::string& name)
{
    lua::getglobal(state, name.c_str());
    if (lua::isnil(state))
    {
        logger.warning() << "Can't find global \"" << name << "\"";
        return false;
    }
    return true;
}