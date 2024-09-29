#include "include/lab1.h"

int main()
{
    std::string st;
    int num;
    std::cout << "Введите день недели и число в формате: '<string> <int>'" << std::endl;
    std::cin >> st >> num;
    std::cout << "Answer: " << check_day(st, num) << std::endl;
}