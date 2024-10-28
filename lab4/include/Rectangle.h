#pragma once
#include <Figure.h>

template <Scalar T>
class Rectangle : public Figure<T>
{
public:
    using Figure<T>::Figure;

    Point<T> geomcenter() noexcept override
    {
        return {(this->points[0].x - this->points[2].x) / 2 + this->points[2].x,
                (this->points[0].y - this->points[2].y) / 2 + this->points[2].y};
    }

    explicit operator double() noexcept
    {
        return this->pt_dist(this->points[0], this->points[1]) * this->pt_dist(this->points[1], this->points[2]);
    }

    template <Scalar D>
    friend std::ostream &operator<<(std::ostream &os, Rectangle<D> &f) noexcept;

    template <Scalar D>
    friend std::istream &operator>>(std::istream &is, Rectangle<D> &f) noexcept;
};

template <Scalar T>
std::ostream &operator<<(std::ostream &os, Rectangle<T> &f) noexcept
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
std::istream &operator>>(std::istream &is, Rectangle<T> &f) noexcept
{
    std::cout << "Enter the vertices {X,Y} of the figure in direct sequence." << '\n';
    for (int i = 0; i < f.cnt_vertex; ++i)
        is >> f.points[i].x >> f.points[i].y;
    return is;
}