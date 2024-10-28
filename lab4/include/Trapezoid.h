#pragma once
#include <Figure.h>

template <Scalar T>
class Trapezoid : public Figure<T>
{
public:
    using Figure<T>::Figure;
    Point<T> geomcenter() noexcept override
    {
        if (is_parallel(this->points[0], this->points[1], this->points[2], this->points[3]))
        {
            Point<T> s1 = {(this->points[1].x - this->points[0].x) / 2 + this->points[0].x,
                           (this->points[1].y - this->points[0].y) / 2 + this->points[0].y};
            Point<T> s2 = {(this->points[2].x - this->points[3].x) / 2 + this->points[3].x,
                           (this->points[2].y - this->points[3].y) / 2 + this->points[3].y};
            Point<T> ans = {(s1.x - s2.x) / 2 + s2.x,
                            (s1.y - s2.y) / 2 + s2.y};
            return ans;
        }
        else if (is_parallel(this->points[0], this->points[3], this->points[2], this->points[1]))
        {
            Point<T> s1 = {(this->points[3].x - this->points[0].x) / 2 + this->points[0].x, (this->points[3].y - this->points[0].y) / 2 + this->points[0].y};
            Point<T> s2 = {(this->points[2].x - this->points[1].x) / 2 + this->points[1].x, (this->points[2].y - this->points[1].y) / 2 + this->points[1].y};
            return {(s1.x - s2.x) / 2 + s2.x, (s1.y - s2.y) / 2 + s2.y};
        }
        else
            return {0, 0};
    }

    explicit operator double() noexcept
    {
        if (is_parallel(this->points[0], this->points[1], this->points[2], this->points[3]))
        {
            double base1 = this->pt_dist(this->points[0], this->points[1]);
            double base2 = this->pt_dist(this->points[2], this->points[3]);

            // Вычисляем высоту трапеции
            double k = (this->points[1].y - this->points[0].y) / (this->points[1].x - this->points[0].x);
            if (fabs(this->points[1].x - this->points[0].x) < Eps) // k=inf
            {
                return fabs(this->points[1].x - this->points[3].x) * (base1 + base2) * 1 / 2;
            }
            double b1 = this->points[0].y - k * this->points[0].x;
            double b2 = this->points[2].y - k * this->points[2].x;
            // Вычисляем площадь трапеции
            return fabs(b2 - b1) * (sqrt(k * k + 1)) * (base1 + base2) * 1 / 2;
        }
        else if (is_parallel(this->points[0], this->points[3], this->points[2], this->points[1]))
        {
            double base1 = this->pt_dist(this->points[0], this->points[3]);
            double base2 = this->pt_dist(this->points[1], this->points[2]);

            // Вычисляем высоту трапеции
            double k = (this->points[3].y - this->points[0].y) / (this->points[3].x - this->points[0].x);
            if (fabs(this->points[3].x - this->points[0].x) < Eps) // k=inf
            {
                return fabs(this->points[1].x - this->points[3].x) * (base1 + base2) * 1 / 2;
            }
            double b1 = this->points[0].y - k * this->points[0].x;
            double b2 = this->points[1].y - k * this->points[1].x;
            // Вычисляем площадь трапеции
            return fabs(b2 - b1) * (sqrt(k * k + 1)) * (base1 + base2) * 1 / 2;
        }
        else
            return 0.0;
    }

    template <Scalar D>
    friend std::ostream &operator<<(std::ostream &os, Trapezoid<D> &f) noexcept;

    template <Scalar D>
    friend std::istream &operator>>(std::istream &is, Trapezoid<D> &f) noexcept;

private:
    bool is_parallel(Point<T> p1, Point<T> p2, Point<T> p3, Point<T> p4) noexcept
    {
        double k1 = (p2.y - p1.y) / (p2.x - p1.x);
        double k2 = (p4.y - p3.y) / (p4.x - p3.x);

        if (fabs(p2.x - p1.x) < Eps or fabs(p4.x - p3.x) < Eps)
            return true;
        return fabs(k1 - k2) < Eps;
    }
};

template <Scalar T>
std::ostream &operator<<(std::ostream &os, Trapezoid<T> &f) noexcept
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
std::istream &operator>>(std::istream &is, Trapezoid<T> &f) noexcept
{
    std::cout << "Enter the vertices {X,Y} of the figure in direct sequence." << '\n';
    for (int i = 0; i < f.cnt_vertex; ++i)
        is >> f.points[i].x >> f.points[i].y;
    return is;
}