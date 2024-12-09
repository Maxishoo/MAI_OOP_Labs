#include<Array.h>

int main()
{
    Point<double> arr1[4] = {{0, 0}, {3, 4}, {6, 0}, {3, -4}};
    Rhombus<double> r(arr1);
    Rectangle<double> r2,r3,r4;
    std::cin>>r2>>r3>>r4;

    Array<Figure<double>> lst{r2,r3,r4};
    lst.print(std::cout);
    lst.push_back(r);
    lst.print(std::cout);

    lst.del_ind(0);
    lst.print(std::cout);
}