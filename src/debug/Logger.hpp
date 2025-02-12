#pragma once

#include <mutex>
#include <fstream>
#include <sstream>

namespace debug
{
    enum class LogType {
        Print, Info, Warning, Error, Debug
    };

    class Logger;

    class LoggerStream
    {
        Logger* logger;
        LogType type;
        std::ostringstream ss;

    public:
        LoggerStream(Logger* logger, LogType type);
        ~LoggerStream();

        // rule of 5
        LoggerStream(const LoggerStream&) = default; // RVO in C++11 required
        LoggerStream(LoggerStream&&) = default;
        LoggerStream& operator=(const LoggerStream&) = default;
        LoggerStream& operator=(LoggerStream&&) = default;

        inline LogType getType() const noexcept { return type; }
        
        template <class T>
        inline LoggerStream& operator<<(const T& x)
        {
            ss << x;
            return *this;
        }
    };

    class Logger
    {
        static uint32_t nameWidth;

        std::string name;

    public:
        Logger(std::string name);

        void log(LogType type, const std::string& message) const;

        inline void print   (const std::string& message) const noexcept { log(LogType::Print,   message); }
        inline void info    (const std::string& message) const noexcept { log(LogType::Info,    message); }
        inline void warning (const std::string& message) const noexcept { log(LogType::Warning, message); }
        inline void error   (const std::string& message) const noexcept { log(LogType::Error,   message); }
        inline void debug   (const std::string& message) const noexcept { log(LogType::Debug,   message); }

        inline LoggerStream print()   noexcept { return LoggerStream(this, LogType::Print   ); }
        inline LoggerStream info()    noexcept { return LoggerStream(this, LogType::Info    ); }
        inline LoggerStream warning() noexcept { return LoggerStream(this, LogType::Warning ); }
        inline LoggerStream error()   noexcept { return LoggerStream(this, LogType::Error   ); }
        inline LoggerStream debug()   noexcept { return LoggerStream(this, LogType::Debug   ); }

        inline static uint32_t getNameWidth() noexcept { return nameWidth; }

        inline std::string getName() const noexcept { return name; }
    };
} // namespace debug