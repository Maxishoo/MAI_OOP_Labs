#include <gtest/gtest.h>
#include "../include/lab1.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(check_day("Понедельник", 7) == 0);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(check_day("Понедельник", 12) == 1);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(check_day("Вторник", 23) == 0);
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(check_day("Вторник", 96) == 1);
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(check_day("Среда", 1) == 0);
}

TEST(test_06, basic_test_set)
{
    ASSERT_TRUE(check_day("Среда", 34) == 1);
}

TEST(test_07, basic_test_set)
{
    ASSERT_TRUE(check_day("Четверг", 100000000) == 0);
}

TEST(test_08, basic_test_set)
{
    ASSERT_TRUE(check_day("Четверг", 0) == 1);
}

TEST(test_09, basic_test_set)
{
    ASSERT_TRUE(check_day("Пятница", 1) == 0);
}

TEST(test_10, basic_test_set)
{
    ASSERT_TRUE(check_day("Пятница", 34) == 1);
}

TEST(test_11, basic_test_set)
{
    ASSERT_TRUE(check_day("Суббота", 51) == 0);
}

TEST(test_12, basic_test_set)
{
    ASSERT_TRUE(check_day("Суббота", 56) == 1);
}

TEST(test_13, basic_test_set)
{
    ASSERT_TRUE(check_day("Воскресенье", -32423) == 0);
}

TEST(test_14, basic_test_set)
{
    ASSERT_TRUE(check_day("Воскресенье", 666) == 1);
}

TEST(test_15, basic_test_set)
{
    ASSERT_TRUE(check_day("Воскресенье", 332423) == 0);
}

TEST(test_16, basic_test_set)
{
    ASSERT_TRUE(check_day("Воскресенье", -666) == 1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}