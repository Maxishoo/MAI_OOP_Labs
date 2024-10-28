#pragma once
#include <iostream>
#include <memory>
#include <concepts>
#include <cmath>

const double Eps = 0.000001;
// Определяем концепт скалярного типа
template <class T>
concept Scalar = std::is_arithmetic_v<T>;

// Класс точка
template <Scalar T>
class Point
{
public:
    T x, y;

    Point() : x(0), y(0) {}
    Point(T x, T y) : x(x), y(y) {}

    bool operator==(const Point<T> &right) const noexcept
    {
        return x == right.x and y == right.y;
    }
    template <Scalar D>
    requires std::is_floating_point_v<D>
    bool operator==(const Point<D> &right) const noexcept
    {
        return std::fabs(x - right.x) <= Eps && std::fabs(y - right.y) <= Eps;
    }
};
