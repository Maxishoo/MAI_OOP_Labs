#include <NPC.h>

NPC::NPC(NpcType t, int _x, int _y, std::string name) : type(t), x(_x), y(_y), name(name) {}
NPC::NPC(NpcType t, std::istream &is)
{
    type = t;
    is >> x;
    is >> y;
}

void NPC::subscribe(std::shared_ptr<IFightObserver> observer)
{
    observers.push_back(observer);
}

void NPC::fight_notify(const std::shared_ptr<NPC> defender, bool win)
{
    for (auto &o : observers)
        o->on_fight(shared_from_this(), defender, win);
}

void NPC::save(std::ostream &os)
{
    os << type << std::endl;
    os << x << std::endl;
    os << y << std::endl;
}

bool NPC::is_close(const std::shared_ptr<NPC> &other, size_t distance)
{
    if (std::pow(x - other->x, 2) + std::pow(y - other->y, 2) <= std::pow(distance, 2))
        return true;
    else
        return false;
}

std::ostream &operator<<(std::ostream &os, NPC &npc)
{
    switch (npc.type)
    {
    case KnightErrantType:
        os<<"type: KnightErrant ";
        break;
    
    default:
        break;
    }
    os << "name: " << npc.name << "coords {x:" << npc.x << ", y:" << npc.y << "}";
    return os;
}

void NPC::print()
{
    std::cout << *this;
}