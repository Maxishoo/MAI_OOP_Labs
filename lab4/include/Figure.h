#pragma once
#include <Point.h>

template <Scalar T>
class Figure
{
public:
    Figure() noexcept
    {
        std::make_unique<int[]>(1024);
        points = std::make_unique<Point<T>[]>(cnt_vertex);
        for (int i = 0; i < cnt_vertex; ++i)
        {
            points[i] = {0, 0};
        }
    }
    Figure(const Figure<T> &other) noexcept
    {
        points = std::make_unique<Point<T>[]>(cnt_vertex);
        for (int i = 0; i < cnt_vertex; ++i)
        {
            points[i] = other.points[i];
        }
    }
    Figure(Point<T> *arr) noexcept
    {
        points = std::make_unique<Point<T>[]>(cnt_vertex);
        for (int i = 0; i < cnt_vertex; ++i)
        {
            points[i] = arr[i];
        }
    }
    ~Figure() = default;

    virtual explicit operator double() noexcept
    {
        return 0.0;
    }
    virtual Point<T> geomcenter() noexcept
    {
        return {0, 0};
    }

    bool operator==(const Figure<T> &right) const noexcept
    {
        for (int i = 0; i < cnt_vertex; ++i)
            if (points[i] != right.points[i])
                return false;
        return true;
    }
    Figure<T> &operator=(const Figure<T> &right_operand) noexcept
    {
        for (int i = 0; i < 4; ++i)
            points[i] = right_operand.points[i];
        return *this;
    }
    Figure<T> &operator=(Figure<T> &&right_operand) noexcept
    {
        points = std::move(right_operand.points);
        right_operand.points = nullptr;
        return *this;
    }

    double pt_dist(Point<T> &point1, Point<T> &point2) noexcept
    {
        Point<double> dpoint{double(point2.x - point1.x), double(point2.y - point1.y)};
        double distanceSquared = dpoint.x * dpoint.x + dpoint.y * dpoint.y;
        return sqrt(distanceSquared);
    }

protected:
    std::unique_ptr<Point<T>[]> points;
    int cnt_vertex = 4;

    template <Scalar D>
    friend std::ostream &operator<<(std::ostream &os, Figure<D> &f) noexcept;

    template <Scalar D>
    friend std::istream &operator>>(std::istream &is, Figure<D> &f) noexcept;
};

template <Scalar T>
std::ostream &operator<<(std::ostream &os, Figure<T> &f) noexcept
{
    for (int i = 0; i < f.cnt_vertex; ++i)
    {
        os << "(" << f.points[i].x << ',' << f.points[i].y << ')';
        if (i != f.cnt_vertex - 1)
            os << ", ";
    }
    os << '\n';
    return os;
}

template <Scalar T>
std::istream &operator>>(std::istream &is, Figure<T> &f) noexcept
{
    std::cout << "Enter the vertices {X,Y} of the figure in direct sequence." << '\n';
    for (int i = 0; i < f.cnt_vertex; ++i)
        is >> f.points[i].x >> f.points[i].y;
    return is;
}