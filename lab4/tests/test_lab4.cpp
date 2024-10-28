#include <gtest/gtest.h>
#include "../include/lab4.h"
// Rect
TEST(test_01, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rectangle<double> r(arr);
    ASSERT_TRUE(fabs(double(r) - 1) < Eps);
}
TEST(test_02, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rectangle<double> r(arr);

    Point<double> arr2[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rectangle<double> r2(arr2);
    ASSERT_TRUE(r == r2);
}
TEST(test_03, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rectangle<double> r(arr);

    Point<double> arr2[4] = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    Rectangle<double> r2(arr2);
    ASSERT_TRUE(r != r2);
}
TEST(test_04, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rectangle<double> r(arr);
    Rectangle<double> r2 = r;
    ASSERT_TRUE(r == r2);
}
TEST(test_05, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rectangle<double> r(arr);
    Rectangle<double> r2(r);
    ASSERT_TRUE(r == r2);
}
TEST(test_06, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    Rectangle<double> r(arr);
    Point<double> p = {1, 1};
    ASSERT_TRUE(r.geomcenter() == p);
}
TEST(test_07, basic_test_set)
{
    Point<double> arr[4] = {{2, 0}, {2, 2}, {0, 2}, {0, 0}};
    Rectangle<double> r(arr);
    Point<double> p = {1, 1};
    ASSERT_TRUE(r.geomcenter() == p);
}

// Trapezoid
TEST(test_08, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {4, 0}, {3, 1.5}, {1, 1.5}};
    Trapezoid<double> r(arr);
    ASSERT_TRUE(fabs(double(r) - 4.5) < Eps);
}
TEST(test_09, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {4, 0}, {3, 1.5}, {1, 1.5}};
    Trapezoid<double> r(arr);

    Point<double> arr2[4] = {{0, 0}, {4, 0}, {3, 1.5}, {1, 1.5}};
    Trapezoid<double> r2(arr2);
    ASSERT_TRUE(r == r2);
}
TEST(test_10, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {4, 0}, {3, 1.5}, {1, 1.5}};
    Trapezoid<double> r(arr);

    Point<double> arr2[4] = {{0, 0}, {4, 0}, {3, 2}, {1, 2}};
    Trapezoid<double> r2(arr2);
    ASSERT_TRUE(r != r2);
}
TEST(test_11, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {4, 0}, {3, 1.5}, {1, 1.5}};
    Trapezoid<double> r(arr);
    Trapezoid<double> r2 = r;
    ASSERT_TRUE(r == r2);
}
TEST(test_12, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {4, 0}, {3, 1.5}, {1, 1.5}};
    Trapezoid<double> r(arr);
    Trapezoid<double> r2(r);
    ASSERT_TRUE(r == r2);
}
TEST(test_13, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {4, 0}, {3, 1.5}, {1, 1.5}};
    Trapezoid<double> r(arr);
    Point<double> p = {2, 0.75};
    Point<double> o = r.geomcenter();
    ASSERT_TRUE(r.geomcenter() == p);
}
TEST(test_14, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {0, 4}, {1.5, 1}, {1.5, 3}};
    Trapezoid<double> r(arr);
    ASSERT_TRUE(fabs(double(r) - 4.5) < Eps);
}
TEST(test_15, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {0, 4}, {1.5, 1}, {1.5, 3}};
    Trapezoid<double> r(arr);
    Point<double> p = {0.75, 2};
    ASSERT_TRUE(r.geomcenter() == p);
}

// Romb
TEST(test_16, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {1, 1}, {0, 2}, {-1, 1}};
    Rhombus<double> r(arr);
    ASSERT_TRUE(fabs(double(r) - 2) < Eps);
}
TEST(test_17, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {3, 4}, {6, 0}, {3, -4}};
    Rhombus<double> r(arr);
    ASSERT_TRUE(fabs(double(r) - 24) < Eps);
}
TEST(test_18, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {1, 1}, {0, 2}, {-1, 1}};
    Rhombus<double> r(arr);
    Point<double> p = {0, 1};
    ASSERT_TRUE(r.geomcenter() == p);
}
TEST(test_19, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rhombus<double> r(arr);

    Point<double> arr2[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rhombus<double> r2(arr2);
    ASSERT_TRUE(r == r2);
}
// All array
TEST(test_20, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rectangle<double> r(arr);

    Point<double> arr2[4] = {{0, 0}, {3, 4}, {6, 0}, {3, -4}};
    Rhombus<double> r2(arr2);

    Point<double> arr3[4] = {{0, 0}, {4, 0}, {3, 1.5}, {1, 1.5}};
    Trapezoid<double> r3(arr3);

    Array<Figure<double>*> arr4{&r, &r2, &r3};
    double ans = arr4.all_area();
    ASSERT_TRUE(fabs(ans - (1 + 24 + 4.5)) < Eps);
}
TEST(test_21, basic_test_set)
{
    Point<double> arr[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rectangle<double> r(arr);

    Point<double> arr3[4] = {{0, 0}, {4, 0}, {3, 1.5}, {1, 1.5}};
    Trapezoid<double> r3(arr3);
    ASSERT_TRUE(r != r3);
}
TEST(test_22, basic_test_set)
{
    Point<int> arr[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rectangle<int> r(arr);
    ASSERT_TRUE(fabs(double(r) - 1) < Eps);
}
TEST(test_23, basic_test_set)
{
    Point<long> arr[4] = {{0, 0}, {4, 0}, {4, 4}, {0, 4}};
    Rectangle<long> r(arr);
    ASSERT_TRUE(fabs(double(r) - 16) < Eps);
}
TEST(test_24, basic_test_set)
{
    Point<double> arr1[4] = {{0, 0}, {3, 4}, {6, 0}, {3, -4}};
    Rhombus<double> r(arr1);
    Rhombus<double> r2(r);
    Rhombus<double> r3(r);
    Rhombus<double> r4(r);

    Array<Rhombus<double>> arr4{r, r2, r3, r4};
    double ans = arr4.all_area();
    ASSERT_TRUE(fabs(ans - (24 * 4)) < Eps);
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}