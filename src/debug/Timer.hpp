#pragma once

#include <chrono>
#include <string>
#include <stdfloat>

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

        // https://en.wikipedia.org/wiki/Metric_prefix
        inline double nanoseconds_cast () noexcept { return std::chrono::duration_cast<Nanoseconds_t> (duration()).count(); }
        inline double microseconds_cast() noexcept { return std::chrono::duration_cast<Microseconds_t>(duration()).count(); }
        inline double milliseconds_cast() noexcept { return std::chrono::duration_cast<Milliseconds_t>(duration()).count(); }
        inline double seconds_cast     () noexcept { return std::chrono::duration_cast<Seconds_t>     (duration()).count(); }
        inline double minutes_cast     () noexcept { return std::chrono::duration_cast<Minutes_t>     (duration()).count(); }
        inline double hours_cast       () noexcept { return std::chrono::duration_cast<Hours_t>       (duration()).count(); }

        inline double nanoseconds () noexcept { return duration().count() / 1.0; }
        inline double microseconds() noexcept { return duration().count() / 1000.0; }
        inline double milliseconds() noexcept { return duration().count() / 1000000.0; }
        inline double seconds     () noexcept { return duration().count() / 1000000000.0; }
        inline double minutes     () noexcept { return duration().count() / 1000000000000.0; }
        inline double hours       () noexcept { return duration().count() / 1000000000000000.0; }

    private:
        TimePoint_t startTime;
        TimePoint_t stopTime;
    };
} // namespace debug