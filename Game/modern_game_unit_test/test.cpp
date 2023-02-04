#include "pch.h"
#include "../modern_cpp_game/constants.h"


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(GameWindowSize, GameWindowSizeGreaterThanZeroPix) {
	EXPECT_GT(constants::window_height, 0);
	EXPECT_GT(constants::window_width, 0);
}

TEST(BallVelocity, BallVelocGreaterThanZero) {
	EXPECT_GT(constants::ballSpeed, 0);	
}