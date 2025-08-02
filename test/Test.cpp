#include "../src/emulator.hpp"
#include "state_test_utils.hpp"
#include <gtest/gtest.h>

TEST(EmulatorE2ETests, Test01)
{
    Emulator& testEmulator = Emulator::getInstance();
    testEmulator.run("../inputs/multi-ops/test-02.txt");

    RegisterBank rb {};
    Memory mem {};

    StateTestUtils::loadStateFromFile("../test/resources/expected_00.csv", rb, mem);

    // todo figure out a better way to show fail points

    EXPECT_NE(&testEmulator.getRegisterBank(), nullptr);
    EXPECT_TRUE(StateTestUtils::areRegisterBanksEqual(rb, testEmulator.getRegisterBank()));
    EXPECT_TRUE(StateTestUtils::areMemoryBanksEqual(mem, testEmulator.getMemory()));
}