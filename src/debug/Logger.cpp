#include "Logger.hpp"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace debug;

std::ofstream Logger::file;
std::mutex Logger::mutex;
std::string Logger::utcOffset = "";
unsigned Logger::moduleLen = 20;

Logger::Logger(const std::string& name) : name(std::move(name)) { }

Logger::~Logger() { }

void Logger::init(std::string filename)
{
    file.open(filename);

    time_t tm = std::time(nullptr);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&tm), "%z");
    utcOffset = ss.str();
}

void Logger::flush()
{
    std::lock_guard<std::mutex> lock(mutex);
    file.flush();
}

void Logger::log(LogType type, std::string message)
{
    
}