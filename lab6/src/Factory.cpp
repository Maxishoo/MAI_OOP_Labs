#include<../include/Factory.h>
std::shared_ptr<NPC> factory(std::istream &is)
{
    std::shared_ptr<NPC> result;
    int type{0};
    if (is >> type)
    {
        switch (type)
        {
        case KnightErrantType:
            result = std::make_shared<KnightErrant>(is);
            break;
        }
    }
    else
        std::cerr << "unexpected NPC type:" << type << std::endl;

    if (result)
        result->subscribe(TextObserver::get());

    return result;
}

std::shared_ptr<NPC> factory(NpcType type, int x, int y, std::string name)
{
    std::shared_ptr<NPC> result;
    switch (type)
    {
    case KnightErrantType:
        result = std::make_shared<KnightErrant>(x, y, name);
        break;
    default:
        break;
    }
    if (result)
        result->subscribe(TextObserver::get());

    return result;
}