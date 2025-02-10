#pragma once

#include <mutex>
#include <fstream>
#include <sstream>

namespace debug
{
    enum LogType {
        Info, Warning, Error, Debug
    };

    class Logger
    {
        static std::mutex mutex;
        static std::string utcOffset;
        static std::ofstream file;
        static unsigned moduleLen;

        std::string name;

        static void log(LogType type, const std::string& name, const std::string& message);
    public:
        static void init(std::string filename);
        static void flush();

        Logger(const std::string& name);
        ~Logger();

        void log(LogType type, std::string message);
    };
}