#include "API.hpp"
#include "../../../debug/Logger.hpp"

#include "../../../io/ResourceLoader.hpp"
#include "../LuaWrapper.hpp"

static debug::Logger logger("script-lib");

static int l_loadscript(const char* name)
{
    std::stringstream ss;
    ss << name << ".lua";

    io::ResourceLoader loader;
    auto data = loader.LoadContent(ss.str());
    
    return 0;
}

const luaL_Reg scriptlib[] = {
    { NULL, NULL }
};