#pragma once
#include <Figure.h>
#include <Rectangle.h>
#include <Trapezoid.h>
#include <Rhombus.h>

template <class T>
class Array
{
public:
    Array() : _size(0), _array{nullptr}, _real_size{0} {}

    Array(const std::initializer_list<T> &t) noexcept
    {
        _array = std::shared_ptr<T[]>(new T[t.size()]);
        size_t i{0};
        for (auto &c : t)
            _array[i++] = c;
        _size = t.size();
        _real_size = t.size();
    }

    ~Array() = default;
    void input() noexcept // Из косоли считываются только double фигуры
    {
        for (int i = 0; i < _size; ++i)
        {
            std::cout << "Enter type of figure: r - rectangle, t - trapezoid, h - rhombus\n";
        }
    }

    std::ostream &print(std::ostream &os) noexcept
    {
        os << "Array contains:\n";
        for (int i = 0; i < _size; ++i)
        {
            os << "Figure " << i + 1 << '\n';
            os << _array[i];
        }
        return os;
    }

    std::ostream &geomcenter(std::ostream &os) noexcept // геом центр для каждой фигуры из массива
    {
        os << "Geometry centers:\n";
        for (int i = 0; i < _size; ++i)
        {
            os << "Figure " << i + 1 << '\n';
            Point<T> gc = _array[i].geomcenter();
            os << "(" << gc.x << ',' << gc.y << ')';
            os << '\n';
        }
        return os;
    }

    std::ostream &separate_areas(std::ostream &os) noexcept // вывод каждой площади по отдельности
    {
        os << "Separate centers:\n";
        for (int i = 0; i < _size; ++i)
        {
            double d = double(_array[i]);
            os << "Area of figure " << i + 1 << " is " << d << '\n';
        }
        return os;
    }

    double all_area() noexcept // сумарная площадь всех фигур массива
    {
        double sum = 0;
        for (int i = 0; i < _size; ++i)
        {
            sum += double(_array[i]);
        }
        return sum;
    }

    void push_back(T el) noexcept
    {
        if (_real_size < _size + 1)
        {
            std::shared_ptr<T[]> _array2;
            if (_real_size == 0)
            {
                _array2 = std::shared_ptr<T[]>(new T[1]);
                _real_size = 1;
            }
            else
            {
                _array2 = std::shared_ptr<T[]>(new T[_real_size * 2]);
                _real_size *= 2;
            }
            for (int i = 0; i < _size; ++i)
            {
                _array2[i] = std::move(_array[i]);
            }
            _array = _array2;
        }
        _array[_size] = el;
        _size += 1;
    }

    void del_ind(int ind) noexcept
    {
        if (ind < 0 && ind >= _size)
            return;

        if (_size - 1 <= _real_size / 2)
        {
            std::shared_ptr<T[]> _array2;
            _array2 = std::shared_ptr<T[]>(new T[_real_size / 2]);
            _real_size /= 2;
            int j = 0;
            for (int i = 0; i < _real_size; ++i)
            {
                if (i == ind)
                    ++j;
                _array2[i] = std::move(_array[j]);
                ++j;
            }
            _array = _array2;
        }
        else
        {
            int j = 0;
            for (int i = 0; i < _size - 1; ++i)
            {
                if (i == ind)
                    ++j;
                _array[i] = std::move(_array[j]);
                ++j;
            }
        }
        _size -= 1;
    }

private:
    size_t _size;
    size_t _real_size;
    std::shared_ptr<T[]> _array;
};

template <class T>
concept Pointable = std::is_pointer_v<T>;

template <Pointable T>
class Array<T>
{
public:
    Array() : _size(0), _array{nullptr}, _real_size{0} {}

    Array(const std::initializer_list<T> &t) noexcept
    {
        _array = std::shared_ptr<T[]>(new T[t.size()]);
        size_t i{0};
        for (auto &c : t)
            _array[i++] = c;
        _size = t.size();
        _real_size = t.size();
    }

    ~Array() = default;
    void input() noexcept // Из косоли считываются только double фигуры
    {
        for (int i = 0; i < _size; ++i)
        {
            std::cout << "Figure" << i + 1 << "\n";
        }
    }

    std::ostream &print(std::ostream &os) noexcept
    {
        os << "Array contains:\n";
        for (int i = 0; i < _size; ++i)
        {
            os << "Figure " << i + 1 << '\n';
            os << *_array[i];
        }
        return os;
    }

    std::ostream &geomcenter(std::ostream &os) noexcept // геом центр для каждой фигуры из массива
    {
        os << "Geometry centers:\n";
        for (int i = 0; i < _size; ++i)
        {
            os << "Figure " << i + 1 << '\n';
            Point<T> gc = _array[i]->geomcenter();
            os << "(" << gc.x << ',' << gc.y << ')';
            os << '\n';
        }
        return os;
    }

    std::ostream &separate_areas(std::ostream &os) noexcept // вывод каждой площади по отдельности
    {
        os << "Separate centers:\n";
        for (int i = 0; i < _size; ++i)
        {
            double d = double(*_array[i]);
            os << "Area of figure " << i + 1 << " is " << d << '\n';
        }
        return os;
    }

    double all_area() noexcept // сумарная площадь всех фигур массива
    {
        double sum = 0;
        for (int i = 0; i < _size; ++i)
        {
            sum += double(*_array[i]);
            // sum += double(_array[i]);
        }
        return sum;
    }

    void push_back(T el) noexcept
    {
        if (_real_size < _size + 1)
        {
            std::shared_ptr<T[]> _array2;
            if (_real_size == 0)
            {
                _array2 = std::shared_ptr<T[]>(new T[1]);
                _real_size = 1;
            }
            else
            {
                _array2 = std::shared_ptr<T[]>(new T[_real_size * 2]);
                _real_size *= 2;
            }
            for (int i = 0; i < _size; ++i)
            {
                _array2[i] = std::move(_array[i]);
            }
            _array = _array2;
        }
        _array[_size] = el;
        _size += 1;
    }

    void del_ind(int ind) noexcept
    {
        if (ind < 0 && ind >= _size)
            return;

        if (_size - 1 <= _real_size / 2)
        {
            std::shared_ptr<T[]> _array2;
            _array2 = std::shared_ptr<T[]>(new T[_real_size / 2]);
            _real_size /= 2;
            int j = 0;
            for (int i = 0; i < _real_size; ++i)
            {
                if (i == ind)
                    ++j;
                _array2[i] = std::move(_array[j]);
                ++j;
            }
            _array = _array2;
        }
        else
        {
            int j = 0;
            for (int i = 0; i < _size - 1; ++i)
            {
                if (i == ind)
                    ++j;
                _array[i] = std::move(_array[j]);
                ++j;
            }
        }
        _size -= 1;
    }

private:
    size_t _size;
    size_t _real_size;
    std::shared_ptr<T[]> _array;
};