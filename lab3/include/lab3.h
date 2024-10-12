#include <Figure.h>
#include <Rectangle.h>
#include <Rhombus.h>
#include <Trapezoid.h>

std::ostream &print(std::ostream &os, Figure **arr, int size);
void input(Figure **arr, int count);
std::ostream &geomcenter(std::ostream &os, Figure **arr, int size);     // геом центр для каждой фигуры из массива
std::ostream &separate_areas(std::ostream &os, Figure **arr, int size); // вывод каждой площади по отдельности
double all_area(Figure **arr, int size);                                // сумарная площадь всех фигур массива
void del(Figure **arr, int size);