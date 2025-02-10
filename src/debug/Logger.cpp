#include "Logger.hpp"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace debug;

Logger::Logger(const std::string& name) : name(std::move(name)) { }

Logger::~Logger() { }

void Logger::log(LogType type, const std::string& message)
{
    if (type == LogType::Print)
    {
        std::cout << "[" << name << "] - " << message << std::endl;
        return;
    }

    std::stringstream ss;
    switch (type)
    {
        case LogType::Info:
            ss << "[I]";
            break;
        case LogType::Warning:
            ss << "[W]";
            break;
        case LogType::Error:
            ss << "[E]";
            break;
        case LogType::Debug:
#ifdef NDEBUG
            return;
#endif
            ss << "[D]";
            break;
    }

    ss << " - " << message;

    auto str = ss.str();
    std::cout << str << std::endl;
}