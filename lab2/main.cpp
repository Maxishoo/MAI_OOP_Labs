#include "include/seven.h"

int main()
{
    std::cout << std::boolalpha;
    std::string s1, s2;
    char op;
    std::cout << "Введите первое число:";
    std::cin >> s1;
    std::cout << "Введите второе число:";
    std::cin >> s2;
    std::cout << "Введите операцию из [+,-,>,<,=]:";
    std::cin >> op;
    std::cout << "\nAnswer: ";
    switch (op)
    {
    case '+':
        std::cout << Seven(s1).add(Seven(s2)).to_string();
        break;
    case '-':
        std::cout << Seven(s1).sub(Seven(s2)).to_string();
        break;
    case '=':
        std::cout << Seven(s1).eq(Seven(s2));
        break;
    case '<':
        std::cout << Seven(s1).lt(Seven(s2));
        break;
    case '>':
        std::cout << Seven(s1).gt(Seven(s2));
        break;
    default:
        break;
    }
    std::cout << '\n';
}