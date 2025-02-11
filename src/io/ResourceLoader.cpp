#include "ResourceLoader.hpp"

#include "../debug/Logger.hpp"

using namespace io;

static debug::Logger logger("io");

std::string ResourceLoader::LoadContent(const std::string& path)
{
    ifs.open("res/" + path);

    if (!ifs)
    {
        logger.error() << "Can't open resource by path: " << path;
        return "";
    }
    
    std::string buffer;
    ifs.seekg(0, std::ios::end);
    size_t size = ifs.tellg();
    buffer.reserve(size);
    ifs.seekg(0, std::ios::beg);
    ifs.read(&buffer[0], size);
    
    ifs.close();
    logger.info() << "load resource by path:" << path;
    return buffer;
}