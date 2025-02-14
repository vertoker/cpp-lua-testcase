#include "API.hpp"
#include "../../debug/Logger.hpp"

static debug::Logger logger("lua");

static int l_logprint(const char* name)
{
    logger.print(name);
}
static int l_loginfo(const char* name)
{
    logger.info(name);
}
static int l_logwarning(const char* name)
{
    logger.warning(name);
}
static int l_logerror(const char* name)
{
    logger.error(name);
}
static int l_logdebug(const char* name)
{
    logger.debug(name);
}