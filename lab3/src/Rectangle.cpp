#include "../include/lab3.h"

Rectangle::operator double()
{
    return pt_dist(points[0], points[1]) * pt_dist(points[1], points[2]);
}

std::pair<double, double> Rectangle::geomcenter()
{
    return {(points[0].first - points[2].first) / 2 + points[2].first,
            (points[0].second - points[2].second) / 2 + points[2].second};
}

std::ostream &operator<<(std::ostream &os, Rectangle &f)
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

std::istream &operator>>(std::istream &is, Rectangle &f)
{
    std::cout << "Enter the vertices {X,Y} of the figure in direct sequence." << '\n';
    for (int i = 0; i < f.cnt_vertex; ++i)
        is >> f.points[i].first >> f.points[i].second;
    return is;
}