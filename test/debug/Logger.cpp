#include <gtest/gtest.h>

#include "debug/Logger.hpp"

TEST(Debug, Logger_Variables) {
    std::string name = "123";
    debug::Logger logger(name);

    EXPECT_EQ(logger.getName(), name);
    EXPECT_TRUE(logger.getNameWidth() > 0);
}

TEST(Debug, Logger_Stream) {
    std::string name = "321";
    debug::Logger logger(std::move(name));

    auto stream1 = logger.print();
    auto stream2 = logger.info();
    auto stream3 = logger.warning();
    auto stream4 = logger.error();
    auto stream5 = logger.debug();

    EXPECT_EQ(stream1.getType(), debug::LogType::Print);
    EXPECT_EQ(stream2.getType(), debug::LogType::Info);
    EXPECT_EQ(stream3.getType(), debug::LogType::Warning);
    EXPECT_EQ(stream4.getType(), debug::LogType::Error);
    EXPECT_EQ(stream5.getType(), debug::LogType::Debug);
}

TEST(Debug, Logger_Print) {
    std::string name = "321";
    debug::Logger logger(std::move(name));

    logger.print("print");
    logger.info("info");
    logger.warning("warning");
    logger.error("error");
    logger.debug("debug");

    logger.print() << "stream print";
    logger.info() << "stream info";
    logger.warning() << "stream warning";
    logger.error() << "stream error";
    logger.debug() << "stream debug";
}