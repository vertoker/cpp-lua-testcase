#pragma once

#include <fstream>
#include <string>

namespace io
{
    class ResourceLoader
    {
        std::ifstream ifs;
        
    public:
        std::string LoadContent(const std::string& path);
    };
} // namespace io
