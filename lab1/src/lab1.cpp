#include "../include/lab1.h"

int check_day(std::string day, int n)
{
    if (day == "Понедельник")
        return (n == 12) ? 1 : 0;
    else if (day == "Вторник")
        return (n > 95) ? 1 : 0;
    else if (day == "Среда")
        return (n == 34) ? 1 : 0;
    else if (day == "Четверг")
        return (n == 0) ? 1 : 0;
    else if (day == "Пятница")
        return (n % 2 == 0) ? 1 : 0;
    else if (day == "Суббота")
        return (n == 56) ? 1 : 0;
    else if (day == "Воскресенье")
        return (n == 666 || n == -666) ? 1 : 0;
}