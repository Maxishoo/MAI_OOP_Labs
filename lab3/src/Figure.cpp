#include "../include/Figure.h"

Figure::Figure() // базовый класс создает пустой массив точек
{
    points = new std::pair<double, double>[cnt_vertex];
    for (int i = 0; i < cnt_vertex; ++i)
    {
        points[i] = {0, 0};
    }
}

Figure::Figure(const Figure &other)
{
    points = new std::pair<double, double>[cnt_vertex];
    for (int i = 0; i < cnt_vertex; ++i)
    {
        points[i] = other.points[i];
    }
}
Figure::Figure(const std::pair<double, double> *arr)
{
    points = new std::pair<double, double>[cnt_vertex];
    int i = 0;
    for (int i = 0; i < cnt_vertex; ++i)
    {
        points[i] = arr[i];
    }
}

Figure::~Figure()
{
    delete[] points;
}

Figure::operator double()
{
    return 0.0;
}

std::pair<double, double> Figure::geomcenter()
{
    return {0, 0};
}

bool Figure::operator==(const Figure &right) const
{
    for (int i = 0; i < cnt_vertex; ++i)
        if (fabs(points[i].first - right.points[i].first) > 0.00001 or fabs(points[i].second - right.points[i].second) > 0.00001)
            return false;
    return true;
}

std::ostream &operator<<(std::ostream &os, Figure &f)
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

std::istream &operator>>(std::istream &is, Figure &f)
{
    std::cout << "Enter the vertices {X,Y} of the figure in direct sequence." << '\n';
    for (int i = 0; i < f.cnt_vertex; ++i)
        is >> f.points[i].first >> f.points[i].second;
    return is;
}

Figure &Figure::operator=(const Figure &right_operand) // copy oper
{
    for (int i = 0; i < 4; ++i)
        points[i] = right_operand.points[i];
    return *this;
}

Figure &Figure::operator=(Figure &&right_operand) // move oper
{
    delete[] points;
    points = right_operand.points;
    right_operand.points = nullptr;
    return *this;
}

double Figure::pt_dist(std::pair<double, double> &point1, std::pair<double, double> &point2)
{
    double dx = point2.first - point1.first;
    double dy = point2.second - point1.second;
    double distanceSquared = dx * dx + dy * dy;
    return sqrt(distanceSquared);
}
