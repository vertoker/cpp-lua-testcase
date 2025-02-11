#include "Logger.hpp"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace debug;

unsigned Logger::nameWidth = 10;

// LoggerStream

debug::LoggerStream::LoggerStream(Logger *logger, LogType type)
    : logger(logger), type(type) { }

debug::LoggerStream::~LoggerStream()
{
    logger->log(type, ss.str());
}

// Logger

Logger::Logger(std::string name) : name(std::move(name)) {}

void Logger::log(LogType type, const std::string& message)
{
    std::stringstream ss;
    switch (type)
    {
        case LogType::Info:
            ss << "[I] ";
            break;
        case LogType::Warning:
            ss << "[W] ";
            break;
        case LogType::Error:
            ss << "[E] ";
            break;
        case LogType::Debug:
#ifdef NDEBUG
            return;
#endif
            ss << "[D] ";
            break;
    }

    ss << "[";
    ss << std::setfill(' ') << std::setw(nameWidth) << name;
    ss << "] - ";
    ss << message;

    auto str = ss.str();
    std::cout << str << std::endl;
}