#include <Visitors.h>
#include <KnightErrant.h>
#include <Squirrel.h>
#include <Pegasus.h>

bool try_kill()
{
    int attack_power = std::rand() % 6;
    int deffence_power = std::rand() % 6;

    return attack_power > deffence_power;
}

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
        return try_kill();
    }
    element.fight_notify(attacker, false);
    return false;
}

bool NPCFighter::visit(Pegasus &element) noexcept
{
    if (attacker->type == SquirrelType)
    {
        element.fight_notify(attacker, true); // убивает белка
        return try_kill();
    }
    element.fight_notify(attacker, false);
    return false;
}
