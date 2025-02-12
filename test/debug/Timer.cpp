#include <gtest/gtest.h>

#include "debug/Timer.hpp"

using namespace debug;

uint64_t* num = nullptr;

TEST(Debug, Timer) {
    Timer timer;
    Timer::TimePoint_t zero;

    EXPECT_EQ(timer.startPoint(), zero);
    EXPECT_EQ(timer.stopPoint(), zero);
    EXPECT_EQ(timer.duration().count(), 0LL);

    timer.start();

    // Not optimized some easy work, -O3 not work here
    num = static_cast<uint64_t*>(malloc(sizeof(uint64_t)));
    *num = 123;
    free(num);

    timer.stop();

    EXPECT_TRUE(timer.duration().count() > 0);

    timer.reset();

    EXPECT_EQ(timer.startPoint(), zero);
    EXPECT_EQ(timer.stopPoint(), zero);
    EXPECT_EQ(timer.duration().count(), 0LL);
}