#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>

class Seven
{
public:
    // Конструкторы
    Seven();
    Seven(const size_t &n, unsigned char t = 48);
    Seven(const std::initializer_list<unsigned char> &t);
    Seven(const std::string &t);
    Seven(const Seven &other);
    Seven(Seven &&other) noexcept;
    virtual ~Seven() noexcept;

    // Вывод
    std::ostream &print(std::ostream &os);
    std::string to_string();

    // Арифметические операции

    Seven add(const Seven &other);
    Seven sub(const Seven &other);

    // Операции сравнения

    bool eq(const Seven &other) const;
    bool lt(const Seven &other) const;
    bool gt(const Seven &other) const;

private:
    size_t _size;
    unsigned char *_array;
};