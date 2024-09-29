#include <gtest/gtest.h>
#include "../include/seven.h"
// summ tests
TEST(test_01, basic_test_set)
{
    ASSERT_EQ(Seven{"1234"}.to_string(), "1234");
}

TEST(test_02, basic_test_set)
{
    ASSERT_EQ(Seven({'1', '2'}).to_string(), "12");
}

TEST(test_03, basic_test_set)
{
    Seven a{"111"};
    Seven b{"111"};
    ASSERT_EQ(a.add(b).to_string(), "222");
}

TEST(test_04, basic_test_set)
{
    Seven a{"0"};
    Seven b{"111"};
    ASSERT_EQ(a.add(b).to_string(), "111");
}

TEST(test_05, basic_test_set)
{
    Seven a{"111"};
    Seven b{"0"};
    ASSERT_EQ(a.add(b).to_string(), "111");
}

TEST(test_06, basic_test_set)
{
    Seven a{"66"};
    Seven b{"11"};
    ASSERT_EQ(a.add(b).to_string(), "110");
}
// sub tests
TEST(test_07, basic_test_set)
{
    Seven a{"66"};
    Seven b{"11"};
    ASSERT_EQ(a.sub(b).to_string(), "55");
}
TEST(test_08, basic_test_set)
{
    Seven a{"100"};
    Seven b{"66"};
    ASSERT_EQ(a.sub(b).to_string(), "1");
}
TEST(test_09, basic_test_set)
{
    Seven a{"600"};
    Seven b{"66"};
    ASSERT_EQ(a.sub(b).to_string(), "501");
}
TEST(test_10, basic_test_set)
{
    Seven a{"0"};
    Seven b{"100"};
    bool ok = false;
    try
    {
        Seven v = a.sub(b);
    }
    catch (std::exception ex)
    {
        ok = true;
    }
    ASSERT_EQ(ok, true);
}
TEST(test_11, basic_test_set)
{
    Seven a{"110"};
    Seven b{"45"};
    ASSERT_EQ(a.sub(b).to_string(), "32");
}

// Операторы сравнения
TEST(test_12, basic_test_set)
{
    Seven a{"110"};
    Seven b{"45"};
    ASSERT_EQ(a.eq(b), false);
}
TEST(test_13, basic_test_set)
{
    Seven a{"110"};
    Seven b{"120"};
    ASSERT_EQ(a.eq(b), false);
}
TEST(test_14, basic_test_set)
{
    Seven a{"0"};
    Seven b{"0"};
    ASSERT_EQ(a.eq(b), true);
}
TEST(test_15, basic_test_set)
{
    Seven a{"555555555"};
    Seven b{"555555555"};
    ASSERT_EQ(a.eq(b), true);
}
TEST(test_16, basic_test_set)
{
    Seven a;
    Seven b{"0"};
    ASSERT_EQ(a.eq(b), false);
}
TEST(test_17, basic_test_set)
{
    Seven a;
    Seven b = a;
    ASSERT_EQ(a.eq(b), true);
}
TEST(test_18, basic_test_set)
{
    Seven a{"12"};
    Seven b{"444"};
    ASSERT_EQ(a.lt(b), true);
}
TEST(test_19, basic_test_set)
{
    Seven a{"656"};
    Seven b{"666"};
    ASSERT_EQ(a.lt(b), true);
}
TEST(test_20, basic_test_set)
{
    Seven a{"656"};
    Seven b{"656"};
    ASSERT_EQ(a.lt(b), false);
}

TEST(test_21, basic_test_set)
{
    Seven a{"111"};
    Seven b{"111"};
    ASSERT_EQ(a.gt(b), false);
}
TEST(test_22, basic_test_set)
{
    Seven a{"1"};
    Seven b{"111"};
    ASSERT_EQ(a.gt(b), false);
}
TEST(test_23, basic_test_set)
{
    Seven a{"431"};
    Seven b{"421"};
    ASSERT_EQ(a.gt(b), true);
}

// исключение вдруг не 7-ая система
TEST(test_24, basic_test_set)
{
    bool ok = false;
    try
    {
        Seven a{"81"};
    }
    catch (std::exception ex)
    {
        ok = true;
    }
    ASSERT_EQ(ok, true);
}
TEST(test_25, basic_test_set)
{
    bool ok = false;
    try
    {
        Seven a({'7','1'});
    }
    catch (std::exception ex)
    {
        ok = true;
    }
    ASSERT_EQ(ok, true);
}
TEST(test_26, basic_test_set)
{
    Seven a;
    Seven b{"421"};
    ASSERT_EQ(a.add(b).to_string(), "421");
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}