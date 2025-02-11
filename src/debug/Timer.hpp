#pragma once

#include <chrono>
#include <string>

namespace debug
{
    class Timer
    {
    public:
        typedef std::chrono::high_resolution_clock             Clock_t;
        typedef std::chrono::high_resolution_clock::time_point TimePoint_t;
        typedef std::chrono::high_resolution_clock::duration   Duration_t;

        typedef std::chrono::nanoseconds  Nanoseconds_t;
        typedef std::chrono::microseconds Microseconds_t;
        typedef std::chrono::milliseconds Milliseconds_t;
        typedef std::chrono::seconds      Seconds_t;
        typedef std::chrono::minutes      Minutes_t;
        typedef std::chrono::hours        Hours_t;
        
        void start();
        void stop ();
        void reset();
        
        inline TimePoint_t   startPoint() noexcept { return startTime;            }
        inline TimePoint_t   stopPoint () noexcept { return stopTime;             }
        inline Nanoseconds_t duration  () noexcept { return stopTime - startTime; }

        inline int64_t nanoseconds () noexcept { return std::chrono::duration_cast<Nanoseconds_t> (duration()).count(); }
        inline int64_t microseconds() noexcept { return std::chrono::duration_cast<Microseconds_t>(duration()).count(); }
        inline int64_t milliseconds() noexcept { return std::chrono::duration_cast<Milliseconds_t>(duration()).count(); }
        inline int64_t seconds     () noexcept { return std::chrono::duration_cast<Seconds_t>     (duration()).count(); }
        inline int64_t minutes     () noexcept { return std::chrono::duration_cast<Minutes_t>     (duration()).count(); }
        inline int64_t hours       () noexcept { return std::chrono::duration_cast<Hours_t>       (duration()).count(); }

    private:
        TimePoint_t startTime;
        TimePoint_t stopTime;
    };
} // namespace debug