#include "API.hpp"
#include "../../../debug/Logger.hpp"

static debug::Logger logger("lib-log");

static int l_logprint(const char* name)
{
    logger.print(name);
    return 1;
}
static int l_loginfo(const char* name)
{
    logger.info(name);
    return 1;
}
static int l_logwarning(const char* name)
{
    logger.warning(name);
    return 1;
}
static int l_logerror(const char* name)
{
    logger.error(name);
    return 1;
}
static int l_logdebug(const char* name)
{
    logger.debug(name);
    return 1;
}