#include <NPC.h>

NPC::NPC(NpcType t, int _x, int _y, std::string name) : type(t), x(_x), y(_y), name(name) {}

NPC::NPC(NpcType t, std::istream &is)
{
    type = t;
    is >> x;
    is >> y;
    is >> name;
}

NpcType NPC::get_type() noexcept
{
    std::lock_guard<std::mutex> lck(mtx);
    return type;
}

std::pair<int, int> NPC::position() noexcept
{
    std::lock_guard<std::mutex> lck(mtx);
    return {x, y};
}

void NPC::subscribe(std::shared_ptr<IFightObserver> observer) noexcept
{
    observers.push_back(observer);
}

void NPC::fight_notify(std::shared_ptr<NPC> defender, bool win) noexcept
{
    for (auto &o : observers)
        o->on_fight(shared_from_this(), defender, win);
}

void NPC::save(std::ostream &os) noexcept
{
    os << type << ' ' << x << ' ' << y << ' ' << name << '\n';
}

std::ostream &operator<<(std::ostream &os, NPC &npc) noexcept
{
    switch (npc.type)
    {
    case KnightErrantType:
        os << "type: KnightErrant ";
        break;
    case PegasusType:
        os << "type: Pegasus ";
        break;
    case SquirrelType:
        os << "type: Squirrel ";
        break;

    default:
        break;
    }
    os << "name: " << npc.name << " coords {x:" << npc.x << ", y:" << npc.y << "}";
    return os;
}

void NPC::print() noexcept
{
    std::cout << *this;
}

bool NPC::is_alive() noexcept
{
    std::lock_guard<std::mutex> lck(mtx);
    return alive;
}

void NPC::must_die() noexcept
{
    std::lock_guard<std::mutex> lck(mtx);
    alive = false;
}