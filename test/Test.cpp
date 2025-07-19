#include "../src/emulator.hpp"

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

// class EmulatorTester : public testing::Test
// {

//     Emulator& testEmulator = Emulator::getInstance();

    

// };

TEST(cc, bb)
{
    Emulator& testEmulator = Emulator::getInstance();
    testEmulator.run("../inputs/multi-ops/test-01.txt");

    EXPECT_NE(&testEmulator.getRegisterBank(), nullptr);
}