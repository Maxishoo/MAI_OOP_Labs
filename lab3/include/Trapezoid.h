#include <Figure.h>

class Trapezoid : public Figure
{
public:
    using Figure::Figure;
    std::pair<double, double> geomcenter() override;
    explicit operator double();
    friend std::ostream &operator<<(std::ostream &os, Trapezoid &f);
    friend std::istream &operator>>(std::istream &is, Trapezoid &f);

private:
    bool is_parallel(std::pair<double, double> p1, std::pair<double, double> p2, std::pair<double, double> p3, std::pair<double, double> p4);
};

std::ostream &operator<<(std::ostream &os, Trapezoid &f);

std::istream &operator>>(std::istream &is, Trapezoid &f);