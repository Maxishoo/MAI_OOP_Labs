#pragma once
#include <CustomMemoryResource.h>

template <class ItemT, class StackT>
class StackIterator
{
private:
    StackT *stack;

public:
    StackIterator(StackT *value) : stack(value){};

    StackIterator<ItemT, StackT> &operator++()
    {
        if (!stack->empty())
            stack->pop();
        return *this;
    }

    bool operator==(const StackIterator<ItemT, StackT> &other) const
    {
        if (stack->empty() and (other.stack == nullptr or other.stack->empty()))
            return true;
        if (stack->empty() or (other.stack == nullptr or other.stack->empty()))
            return false;
        return stack == other.stack;
    }

    ItemT operator*() const
    {
        return stack->top();
    }

    ItemT operator->() const
    {
        return stack->top();
    }
};
