#include <Pegasus.h>
#include <Visitors.h>

Pegasus::Pegasus(int x, int y, std::string name) : NPC(PegasusType, x, y, name) {}
Pegasus::Pegasus(std::istream &is) : NPC(PegasusType, is) {}

bool Pegasus::accept(Visitor &visitor) noexcept
{
    return visitor.visit(*this);
}

bool Pegasus::is_close(const std::shared_ptr<NPC> &other) noexcept
{
    if (std::pow(x - other->x, 2) + std::pow(y - other->y, 2) <= std::pow(10, 2))
        return true;
    else
        return false;
}

void Pegasus::move(int max_x, int max_y) noexcept
{
    std::lock_guard<std::mutex> lck(mtx);
    int shift_x, shift_y;
    if (std::rand() % 2 == 0)
        shift_x = -30;
    else
        shift_x = 30;
    if (std::rand() % 2 == 0)
        shift_y = -30;
    else
        shift_y = 30;

    if ((x + shift_x >= 0) && (x + shift_x <= max_x))
        x += shift_x;
    if ((y + shift_y >= 0) && (y + shift_y <= max_y))
        y += shift_y;
}