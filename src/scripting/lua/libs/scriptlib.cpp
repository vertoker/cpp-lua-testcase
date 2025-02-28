#include "API.hpp"
#include "../../../debug/Logger.hpp"

#include "../../../io/ResourceLoader.hpp"
#include "../../Scripting.hpp"

static debug::Logger logger("script-lib");
io::ResourceLoader loader;

static int l_loadscript(lua_State* state)
{
    auto name = lua::tostring(state, 1);

    auto data = loader.LoadContent(name);
    lua::execute(scripting::state, std::move(data));
    
    return 0;
}

const luaL_Reg ScriptLib[] = {
    { "load", l_loadscript },
    { NULL, NULL }
};