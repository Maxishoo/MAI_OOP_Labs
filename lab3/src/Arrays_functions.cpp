#include <lab3.h>

std::ostream &print(std::ostream &os, Figure **arr, int size)
{
    os << "Array contains:\n";
    int i = 0;
    for (int i = 0; i < size; i++)
    {
        Figure *fig = arr[i];
        os << "Figure " << i + 1 << '\n';
        os << *fig;
    }
    return os;
}

void input(Figure **arr, int count)
{

    for (int i = 0; i < count; ++i)
    {
        std::cout << "Enter type of figure: r - rectangle, t - trapezoid, h - rhombus\n";
        char c = ' ';
        std::cin >> c;
        switch (c)
        {
        case 'r':
        {
            Rectangle *r = new Rectangle();
            std::cin >> *r; // Считываем данные для Rectangle
            arr[i] = r;     // Сохраняем указатель на Rectangle в массиве
            break;
        }
        case 't':
        {
            Trapezoid *t = new Trapezoid();
            std::cin >> *t; // Считываем данные для Trapezoid
            arr[i] = t;     // Сохраняем указатель на Trapezoid в массиве
            break;
        }
        case 'h':
        {
            Rhombus *h = new Rhombus();
            std::cin >> *h; // Считываем данные для Rhombus
            arr[i] = h;     // Сохраняем указатель на Rhombus в массиве
            break;
        }
        default:
            break;
        }
    }
}

std::ostream &geomcenter(std::ostream &os, Figure **arr, int size)
{
    os << "Geometry centers:\n";
    for (int i = 0; i < size; i++)
    {
        Figure *fig = arr[i];
        os << "Figure " << i + 1 << '\n';
        std::pair<double, double> gc = fig->geomcenter();
        os << "(" << gc.first << ',' << gc.second << ')';
        os << '\n';
    }
    return os;
}

std::ostream &separate_areas(std::ostream &os, Figure **arr, int size)
{
    os << "Separate centers:\n";
    for (int i = 0; i < size; i++)
    {
        Figure *fig = arr[i];
        double d = double(*fig);
        os << "Area of figure " << i + 1 << " is " << d << '\n';
    }
    return os;
}
double all_area(Figure **arr, int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        Figure *fig = arr[i];
        sum += double(*fig);
    }
    return sum;
}
void del(Figure **arr, int size)
{
    // Освобождение памяти
    for (int i = 0; i < size; ++i)
    {
        delete arr[i];
    }
    delete[] arr; // Освобождение самого массива
}