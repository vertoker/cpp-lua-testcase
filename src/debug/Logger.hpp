#pragma once

#include <mutex>
#include <fstream>
#include <sstream>

namespace debug
{
    enum class LogType {
        Print, Info, Warning, Error, Debug
    };

    class Logger
    {
        std::string name;

    public:
        Logger(const std::string& name);
        ~Logger();

        void log(LogType type, const std::string& message);
    };
}