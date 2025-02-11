#include "Timer.hpp"

using namespace debug;

void Timer::start()
{
    startTime = Timer::Clock_t::now();
}
void Timer::stop()
{
    stopTime = Timer::Clock_t::now();
}
void Timer::reset()
{
    startTime = Timer::TimePoint_t(Timer::Duration_t::duration::zero());
    stopTime = Timer::TimePoint_t(Timer::Duration_t::duration::zero());
}
