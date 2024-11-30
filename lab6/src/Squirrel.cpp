#include <Squirrel.h>
#include <Visitors.h>

Squirrel::Squirrel(int x, int y, std::string name) : NPC(SquirrelType, x, y, name) {}
Squirrel::Squirrel(std::istream &is) : NPC(SquirrelType, is) {}

bool Squirrel::accept(Visitor &visitor) noexcept
{
    return visitor.visit(*this);
}