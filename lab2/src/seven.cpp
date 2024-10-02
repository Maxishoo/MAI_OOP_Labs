#include "../include/seven.h"

// Конструкторы
Seven::Seven() : _size(0), _array{nullptr} {}

Seven::Seven(const size_t &n, unsigned char t)
{
    if (!(t <= '6' and '0' <= t))
        throw std::range_error("calculation system error");
    _array = new unsigned char[n];
    _size = n;
    for (size_t i = 0; i < _size; ++i)
        _array[_size - i - 1] = t;
}

Seven::Seven(const std::initializer_list<unsigned char> &t)
{
    _array = new unsigned char[t.size()];
    _size = t.size();
    size_t i{_size};
    for (auto &c : t)
    {
        if (!(c <= '6' and '0' <= c))
            throw std::range_error("calculation system error");
        _array[--i] = c;
    }
}

Seven::Seven(const std::string &t)
{
    _array = new unsigned char[t.size()];
    _size = t.size();
    for (size_t i = 0; i < _size; ++i)
    {
        if (!(t[_size - i - 1] <= '6' and '0' <= t[_size - i - 1]))
            throw std::range_error("calculation system error");
        _array[i] = t[_size - i - 1];
    }
}

Seven::Seven(const Seven &other) // конструктор копировния
{
    _size = other._size;
    _array = new unsigned char[_size];
    for (size_t i = 0; i < _size; ++i)
        _array[_size - i - 1] = other._array[_size - i - 1];
}

Seven::Seven(Seven &&other) noexcept // конструктор перемещения(move)
{
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

Seven::~Seven() noexcept
{
    if (_size > 0)
    {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

// Вывод
std::ostream &Seven::print(std::ostream &os)
{
    for (size_t i = 0; i < _size; ++i)
        os << _array[_size - i - 1];
    os << '\n';
    return os;
}

std::string Seven::to_string()
{
    std::string ss = "";
    for (size_t i = 0; i < _size; ++i)
    {
        ss += _array[_size - i - 1];
    }
    return ss;
}

// Арифметические операции
Seven Seven::add(const Seven &other)
{
    size_t max_l = std::max(this->_size, other._size);
    unsigned char *ans = new unsigned char[max_l];
    size_t i = 0;
    int mem = 0;
    while (i < this->_size || i < other._size)
    {
        int c1 = (i < this->_size) ? this->_array[i] - '0' : 0;
        int c2 = (i < other._size) ? other._array[i] - '0' : 0;
        ans[i] = (c1 + c2 + mem) % 7 + '0';
        if (c1 + c2 + mem > 6)
            mem = 1;
        else
            mem = 0;
        ++i;
    }
    Seven c;
    if (mem == 1)
    {
        unsigned char *ans2 = new unsigned char[max_l + 1];
        for (size_t j = 0; j < max_l; ++j)
            ans2[j] = ans[j];
        ans2[max_l] = '1';
        c._array = ans2;
        c._size = max_l + 1;
        delete [] ans;
    }
    else
    {
        c._array = ans;
        c._size = max_l;
    }
    return c;
}

Seven Seven::sub(const Seven &other)
{
    if (other._size > this->_size)
        throw std::range_error("a - b < 0");

    unsigned char *ans = new unsigned char[this->_size];
    size_t i = 0;
    int mem = 0;
    while (i < this->_size)
    {
        int c1 = this->_array[i] - '0';
        int c2 = (i < other._size) ? other._array[i] - '0' : 0;
        if (c1 - c2 - mem >= 0)
        {
            ans[i] = (c1 - c2 - mem) + '0';
            mem = 0;
        }
        else
        {
            if (i + 1 == this->_size)
                throw std::range_error("a - b < 0");
            ans[i] = (c1 + 7 - c2 - mem) + '0';
            mem = 1;
        }
        ++i;
    }
    // удаляем ведущие нули
    size_t ans_size = this->_size;
    for (size_t i = 0; i < this->_size; i++)
    {
        if (ans[this->_size - i - 1] == '0' && this->_size != i + 1)
            --ans_size;
        else
            break;
    }
    unsigned char *ans2 = new unsigned char[ans_size];
    for (size_t j = 0; j < ans_size; ++j)
        ans2[j] = ans[j];
    delete[] ans;
    Seven c;
    c._array = ans2;
    c._size = ans_size;
    return c;
}

// Операции сравнения

bool Seven::eq(const Seven &other) const
{
    if (this->_size != other._size)
        return false;
    if (this->_size == 0)
        return true;

    for (size_t i = 0; i < other._size; i++)
        if (this->_array[i] != other._array[i])
            return false;
    return true;
}

bool Seven::lt(const Seven &other) const
{
    if (this->_size < other._size)
        return true;
    else if (this->_size > other._size)
        return false;
    if (this->_size == 0)
        return false;

    size_t i = other._size - 1;
    while (i > 0 and this->_array[i] == other._array[i])
        --i;
    if (this->_array[i] < other._array[i])
        return true;
    else
        return false;
}
bool Seven::gt(const Seven &other) const
{
    if (this->_size > other._size)
        return true;
    else if (this->_size < other._size)
        return false;
    if (this->_size == 0)
        return false;

    size_t i = other._size - 1;
    while (i > 0 and this->_array[i] == other._array[i])
        --i;
    if (this->_array[i] > other._array[i])
        return true;
    else
        return false;
}