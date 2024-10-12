#include "../include/lab3.h"

bool Trapezoid::is_parallel(std::pair<double, double> p1, std::pair<double, double> p2, std::pair<double, double> p3, std::pair<double, double> p4)
{
    double k1 = (p2.second - p1.second) / (p2.first - p1.first);
    double k2 = (p4.second - p3.second) / (p4.first - p3.first);

    if (fabs(p2.first - p1.first) < 0.000001 or fabs(p4.first - p3.first) < 0.000001)
        return true;
    return fabs(k1 - k2) < 0.00001;
}
Trapezoid::operator double()
{
    if (is_parallel(points[0], points[1], points[2], points[3]))
    {
        double base1 = pt_dist(points[0], points[1]);
        double base2 = pt_dist(points[2], points[3]);

        // Вычисляем высоту трапеции
        double k = (points[1].second - points[0].second) / (points[1].first - points[0].first);
        if (fabs(points[1].first - points[0].first) < 0.00001) // k=inf
        {
            return fabs(points[1].first - points[3].first) * (base1 + base2) * 1 / 2;
        }
        double b1 = points[0].second - k * points[0].first;
        double b2 = points[2].second - k * points[2].first;
        // Вычисляем площадь трапеции
        return fabs(b2 - b1) * (sqrt(k * k + 1)) * (base1 + base2) * 1 / 2;
    }
    else if (is_parallel(points[0], points[3], points[2], points[1]))
    {
        double base1 = pt_dist(points[0], points[3]);
        double base2 = pt_dist(points[1], points[2]);

        // Вычисляем высоту трапеции
        double k = (points[3].second - points[0].second) / (points[3].first - points[0].first);
        if (fabs(points[3].first - points[0].first) < 0.00001) // k=inf
        {
            return fabs(points[1].first - points[3].first) * (base1 + base2) * 1 / 2;
        }
        double b1 = points[0].second - k * points[0].first;
        double b2 = points[1].second - k * points[1].first;
        // Вычисляем площадь трапеции
        return fabs(b2 - b1) * (sqrt(k * k + 1)) * (base1 + base2) * 1 / 2;
    }
    else
        return 0.0;
}

std::pair<double, double> Trapezoid::geomcenter()
{
    if (is_parallel(points[0], points[1], points[2], points[3]))
    {
        std::pair<double, double> s1 = {(points[1].first - points[0].first) / 2 + points[0].first,
                                        (points[1].second - points[0].second) / 2 + points[0].second};
        std::pair<double, double> s2 = {(points[2].first - points[3].first) / 2 + points[3].first,
                                        (points[2].second - points[3].second) / 2 + points[3].second};
        std::pair<double, double> ans = {(s1.first - s2.first) / 2 + s2.first,
                                         (s1.second - s2.second) / 2 + s2.second};
        return ans;
    }
    else if (is_parallel(points[0], points[3], points[2], points[1]))
    {
        std::pair<double, double> s1 = {(points[3].first - points[0].first) / 2 + points[0].first, (points[3].second - points[0].second) / 2 + points[0].second};
        std::pair<double, double> s2 = {(points[2].first - points[1].first) / 2 + points[1].first, (points[2].second - points[1].second) / 2 + points[1].second};
        return std::make_pair((s1.first - s2.first) / 2 + s2.first, (s1.second - s2.second) / 2 + s2.second);
    }
    else
        return {0, 0};
}

std::ostream &operator<<(std::ostream &os, Trapezoid &f)
{
    for (int i = 0; i < f.cnt_vertex; ++i)
    {
        os << "(" << f.points[i].first << ',' << f.points[i].second << ')';
        if (i != f.cnt_vertex - 1)
            os << ", ";
    }
    os << '\n';
    return os;
}

std::istream &operator>>(std::istream &is, Trapezoid &f)
{
    std::cout << "Enter the vertices {X,Y} of the figure in direct sequence." << '\n';
    for (int i = 0; i < f.cnt_vertex; ++i)
        is >> f.points[i].first >> f.points[i].second;
    return is;
}