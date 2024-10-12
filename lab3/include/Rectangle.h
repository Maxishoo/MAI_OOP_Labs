#include <Figure.h>

class Rectangle : public Figure
{
public:
    using Figure::Figure;

    std::pair<double, double> geomcenter() override;
    explicit operator double();
    friend std::ostream &operator<<(std::ostream &os, Rectangle &f);
    friend std::istream &operator>>(std::istream &is, Rectangle &f);
};

std::ostream &operator<<(std::ostream &os, Rectangle &f);

std::istream &operator>>(std::istream &is, Rectangle &f);