#include "../include/Stack.h"
struct AB
{
    int a;
    int b;
};
int main()
{
    CustomMemoryResource customResource(500);

    // создаем аллокаторы и стеки для разных типов данных
    std::pmr::polymorphic_allocator<int> allocator1(&customResource);
    std::pmr::polymorphic_allocator<char> allocator2(&customResource);
    std::pmr::polymorphic_allocator<AB> allocator3(&customResource);

    Stack<int, std::pmr::polymorphic_allocator<int>> stack1(allocator1);
    Stack<char, std::pmr::polymorphic_allocator<char>> stack2(allocator2);
    Stack<AB, std::pmr::polymorphic_allocator<AB>> stack3(allocator3);

    // добавляем разные элементы в разные стеки
    stack1.push(10);
    stack1.push(20);

    stack2.push('a');
    stack2.push('b');

    stack3.push({101, 202});
    stack3.push({303, 404});

    // через итераторы выводим результат
    std::cout << "Stack1:\n";
    for (auto it = stack1.begin(); it != stack1.end(); ++it)
    {
        std::cout << *it << '\n';
    }
    std::cout << "Stack2:\n";
    for (auto it = stack2.begin(); it != stack2.end(); ++it)
    {
        std::cout << *it << '\n';
    }
    std::cout << "Stack3:\n";
    for (auto it = stack3.begin(); it != stack3.end(); ++it)
    {
        std::cout << (*it).a << ' ' << (*it).b << '\n';
    }
    std::cout << "End!\n";
}
