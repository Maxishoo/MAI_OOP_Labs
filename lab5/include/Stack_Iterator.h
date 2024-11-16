#pragma once
#include <CustomMemoryResource.h>

template <class ItemT, class StackT>
class StackIterator
{
private:
    StackT *stack;
    int index;

public:
    StackIterator(StackT *value, int index) : stack(value), index(index) {};

    StackIterator<ItemT, StackT> &operator++()
    {
        --index;
        return *this;
    }

    bool operator==(const StackIterator<ItemT, StackT> &other) const
    {
        if (index == other.index and stack == other.stack)
            return true;
        return false;
    }

    ItemT operator*() const
    {
        if (index < 0)
            throw std::out_of_range("Index out of range");
        return stack->data[index];
    }

    ItemT operator->() const
    {
        if (index <= 0)
            throw std::out_of_range("Index out of range");
        return stack->data[index];
    }
};
