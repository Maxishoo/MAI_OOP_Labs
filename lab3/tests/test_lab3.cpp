#include <gtest/gtest.h>
#include "../include/lab3.h"
// Rect
TEST(test_01, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rectangle r(arr);
    ASSERT_TRUE(fabs(double(r) - 1) < 0.0001);
}
TEST(test_02, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rectangle r(arr);

    std::pair<double, double> arr2[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rectangle r2(arr2);
    ASSERT_TRUE(r == r2);
}
TEST(test_03, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rectangle r(arr);

    std::pair<double, double> arr2[4] = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    Rectangle r2(arr2);
    ASSERT_TRUE(r != r2);
}
TEST(test_04, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rectangle r(arr);
    Rectangle r2 = r;
    ASSERT_TRUE(r == r2);
}
TEST(test_05, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rectangle r(arr);
    Rectangle r2(r);
    ASSERT_TRUE(r == r2);
}
TEST(test_06, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    Rectangle r(arr);
    std::pair<double, double> p = {1, 1};
    ASSERT_TRUE(r.geomcenter() == p);
}
TEST(test_07, basic_test_set)
{
    std::pair<double, double> arr[4] = {{2, 0}, {2, 2}, {0, 2}, {0, 0}};
    Rectangle r(arr);
    std::pair<double, double> p = {1, 1};
    ASSERT_TRUE(r.geomcenter() == p);
}

// Trapezoid
TEST(test_08, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {4, 0}, {3, 1.5}, {1, 1.5}};
    Trapezoid r(arr);
    ASSERT_TRUE(fabs(double(r) - 4.5) < 0.0001);
}
TEST(test_09, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {4, 0}, {3, 1.5}, {1, 1.5}};
    Trapezoid r(arr);

    std::pair<double, double> arr2[4] = {{0, 0}, {4, 0}, {3, 1.5}, {1, 1.5}};
    Trapezoid r2(arr2);
    ASSERT_TRUE(r == r2);
}
TEST(test_10, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {4, 0}, {3, 1.5}, {1, 1.5}};
    Trapezoid r(arr);

    std::pair<double, double> arr2[4] = {{0, 0}, {4, 0}, {3, 2}, {1, 2}};
    Trapezoid r2(arr2);
    ASSERT_TRUE(r != r2);
}
TEST(test_11, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {4, 0}, {3, 1.5}, {1, 1.5}};
    Trapezoid r(arr);
    Trapezoid r2 = r;
    ASSERT_TRUE(r == r2);
}
TEST(test_12, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {4, 0}, {3, 1.5}, {1, 1.5}};
    Trapezoid r(arr);
    Trapezoid r2(r);
    ASSERT_TRUE(r == r2);
}
TEST(test_13, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {4, 0}, {3, 1.5}, {1, 1.5}};
    Trapezoid r(arr);
    std::pair<double, double> p = {2, 0.75};
    std::pair<double, double> o = r.geomcenter();
    ASSERT_TRUE(r.geomcenter() == p);
}
TEST(test_14, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {0, 4}, {1.5, 1}, {1.5, 3}};
    Trapezoid r(arr);
    ASSERT_TRUE(fabs(double(r) - 4.5) < 0.0001);
}
TEST(test_15, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {0, 4}, {1.5, 1}, {1.5, 3}};
    Trapezoid r(arr);
    std::pair<double, double> p = {0.75, 2};
    ASSERT_TRUE(r.geomcenter() == p);
}

// Romb
TEST(test_16, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {1, 1}, {0, 2}, {-1, 1}};
    Rhombus r(arr);
    ASSERT_TRUE(fabs(double(r) - 2) < 0.0001);
}
TEST(test_17, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {3, 4}, {6, 0}, {3, -4}};
    Rhombus r(arr);
    ASSERT_TRUE(fabs(double(r) - 24) < 0.0001);
}
TEST(test_18, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {1, 1}, {0, 2}, {-1, 1}};
    Rhombus r(arr);
    std::pair<double, double> p = {0, 1};
    ASSERT_TRUE(r.geomcenter() == p);
}
TEST(test_19, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rhombus r(arr);

    std::pair<double, double> arr2[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rhombus r2(arr2);
    ASSERT_TRUE(r == r2);
}
// All array
TEST(test_20, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rectangle r(arr);

    std::pair<double, double> arr2[4] = {{0, 0}, {3, 4}, {6, 0}, {3, -4}};
    Rhombus r2(arr2);

    std::pair<double, double> arr3[4] = {{0, 0}, {4, 0}, {3, 1.5}, {1, 1.5}};
    Trapezoid r3(arr3);
    Figure *arr4[]{&r, &r2, &r3};
    double ans = all_area(arr4, 3);
    ASSERT_TRUE(fabs(ans - (1 + 24 + 4.5)) < 0.00001);
}
TEST(test_21, basic_test_set)
{
    std::pair<double, double> arr[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rectangle r(arr);

    std::pair<double, double> arr3[4] = {{0, 0}, {4, 0}, {3, 1.5}, {1, 1.5}};
    Trapezoid r3(arr3);
    ASSERT_TRUE(r != r3);
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}