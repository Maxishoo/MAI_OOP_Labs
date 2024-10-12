#include <Figure.h>

class Rhombus : public Figure
{
public:
    using Figure::Figure;

    std::pair<double, double> geomcenter() override;
    explicit operator double();

    friend std::ostream &operator<<(std::ostream &os, Rhombus &f);
    friend std::istream &operator>>(std::istream &is, Rhombus &f);
};

std::ostream &operator<<(std::ostream &os, Rhombus &f);

std::istream &operator>>(std::istream &is, Rhombus &f);