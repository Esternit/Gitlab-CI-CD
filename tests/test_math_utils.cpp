#include <gtest/gtest.h>
#include "math_utils.h"

TEST(MathUtilsTest, AdditionTest)
{
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(-2, -3), -5);
    EXPECT_EQ(add(0, 0), 0);
}

TEST(MathUtilsTest, SubtractionTest)
{
    EXPECT_EQ(subtract(7, 4), 3);
    EXPECT_EQ(subtract(0, 5), -5);
    EXPECT_EQ(subtract(-3, -7), 4);
}

TEST(MathUtilsTest, MultiplicationTest)
{
    EXPECT_EQ(multiply(6, 3), 18);
    EXPECT_EQ(multiply(-2, 4), -8);
    EXPECT_EQ(multiply(0, 100), 0);
}

TEST(MathUtilsTest, DivisionTest)
{
    EXPECT_DOUBLE_EQ(divide(8, 2), 4.0);
    EXPECT_DOUBLE_EQ(divide(-6, 3), -2.0);
}

TEST(MathUtilsTest, DivisionByZero)
{
    EXPECT_THROW(divide(8, 0), std::invalid_argument);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
