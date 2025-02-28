#include "API.hpp"
#include "../../../debug/Logger.hpp"

static debug::Logger logger("log-lib");

int l_logprint(lua_State* state)
{
    auto text = lua::tostring(state, 1);
    logger.print(text);
    return 0;
}
int l_loginfo(lua_State* state)
{
    auto text = lua::tostring(state, 1);
    logger.info(text);
    return 0;
}
int l_logwarning(lua_State* state)
{
    auto text = lua::tostring(state, 1);
    logger.warning(text);
    return 0;
}
int l_logerror(lua_State* state)
{
    auto text = lua::tostring(state, 1);
    logger.error(text);
    return 0;
}
int l_logdebug(lua_State* state)
{
    auto text = lua::tostring(state, 1);
    logger.debug(text);
    return 0;
}

const luaL_Reg loglib[] = {
    { "print", l_logprint },
    { "info", l_loginfo },
    { "warning", l_logwarning },
    { "error", l_logerror },
    { "debug", l_logdebug },
    { NULL, NULL }
};