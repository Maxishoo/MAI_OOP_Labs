#include <Visitors.h>
#include <KnightErrant.h>
#include <Squirrel.h>
#include <Pegasus.h>

NPCFighter::NPCFighter(std::shared_ptr<NPC> attacker) : attacker(attacker) {}

bool NPCFighter::visit(KnightErrant &element) noexcept
{
    element.fight_notify(attacker, false);
    return false;
}

bool NPCFighter::visit(Squirrel &element) noexcept
{
    if (attacker->type == KnightErrantType)
    {
        element.fight_notify(attacker, true); // убивает рыцарь
        return true;
    }
    element.fight_notify(attacker, false);
    return false;
}

bool NPCFighter::visit(Pegasus &element) noexcept
{
    if (attacker->type == SquirrelType)
    {
        element.fight_notify(attacker, true); // убивает белка
        return true;
    }
    element.fight_notify(attacker, false);
    return false;
}
