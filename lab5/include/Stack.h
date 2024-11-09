#pragma once
#include <CustomMemoryResource.h>
#include <Stack_Iterator.h>

template <class T, class allocator_type>
    requires std::is_default_constructible_v<T> && std::is_same_v<allocator_type, std::pmr::polymorphic_allocator<T>>
class Stack
{
private:
    allocator_type allocator;
    T *data;
    size_t capacity;
    size_t size;

public:
    Stack(allocator_type alloc = {}) noexcept : allocator(alloc), data(nullptr), capacity(0), size(0) {}

    Stack(size_t sz, allocator_type alloc = {}) noexcept : allocator(alloc), data(allocator.allocate(sz)), capacity(sz), size(0) {}

    Stack(Stack<T, allocator_type> &other) noexcept
    {
        allocator = other.allocator;
        size = other.size;
        capacity = other.capacity;
        data = allocator.allocate(capacity);
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }
    bool operator==(Stack<T, allocator_type> &right) noexcept
    {
        if (!size == right.size)
            return false;
        for (int i = 0; i < size; ++i)
            if (data[i] != right.data[i])
                return false;
        return true;
    }

    ~Stack()
    {
        if constexpr (std::is_destructible_v<T>)
            for (size_t i = 0; i < capacity; ++i)
                std::allocator_traits<allocator_type>::destroy(allocator, data + i);
        allocator.deallocate(data, capacity);
    }

    void push(const T &value) noexcept
    {
        if (size == capacity)
        {
            T *new_data;
            if (capacity == 0)
            {
                data = allocator.allocate(1);
                capacity = 1;
            }
            else
            {
                new_data = allocator.allocate(2 * capacity);
                for (int i = 0; i < size; ++i)
                {
                    new_data[i] = std::move(data[i]);
                }
                allocator.deallocate(data, capacity);
                data = new_data;
                capacity *= 2;
            }
        }
        data[size++] = value;
    }

    template <typename... Args>
    void emplace(Args &&...args) noexcept
    {
        T val(std::forward<Args>(args)...);
        this->push(val);
    }

    T pop()
    {
        if (size == 0)
        {
            throw std::underflow_error("Stack underflow");
        }
        return data[--size];
    }

    T top() const
    {
        if (size == 0)
        {
            throw std::underflow_error("Stack underflow");
        }
        return data[size - 1];
    }

    bool empty() const noexcept
    {
        return size == 0;
    }

    size_t get_size() const noexcept
    {
        return size;
    }

    StackIterator<T, Stack<T, allocator_type>> begin() noexcept // первый элемент стека
    {
        return StackIterator<T, Stack<T, allocator_type>>(this);
    }

    StackIterator<T, Stack<T, allocator_type>> end() noexcept // обозначим концом стека нулевой указатель
    {
        return StackIterator<T, Stack<T, allocator_type>>(nullptr);
    }
};