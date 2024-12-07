#include <Squirrel.h>
#include <Visitors.h>

Squirrel::Squirrel(int x, int y, std::string name) : NPC(SquirrelType, x, y, name) {}
Squirrel::Squirrel(std::istream &is) : NPC(SquirrelType, is) {}

bool Squirrel::accept(Visitor &visitor) noexcept
{
    return visitor.visit(*this);
}

bool Squirrel::is_close(const std::shared_ptr<NPC> &other) noexcept
{
    if (std::pow(x - other->x, 2) + std::pow(y - other->y, 2) <= std::pow(5, 2))
        return true;
    else
        return false;
}

void Squirrel::move(int max_x, int max_y) noexcept
{
    std::lock_guard<std::mutex> lck(mtx);
    int shift_x, shift_y;
    if (std::rand() % 2 == 0)
        shift_x = -5;
    else
        shift_x = 5;
    if (std::rand() % 2 == 0)
        shift_y = -5;
    else
        shift_y = 5;

    if ((x + shift_x >= 0) && (x + shift_x <= max_x))
        x += shift_x;
    if ((y + shift_y >= 0) && (y + shift_y <= max_y))
        y += shift_y;
}
