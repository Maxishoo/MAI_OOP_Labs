#pragma once
#include <lab6.h>

class KnightErrant;

class Visitor
{
public:
    virtual bool visit(KnightErrant &element) = 0;
};

class NPCFighter : public Visitor
{
public:
    std::shared_ptr<NPC> attacker;

    NPCFighter(std::shared_ptr<NPC> attacker) : attacker(attacker) {}

    bool visit(KnightErrant &element) override
    {
        if (attacker->type == KnightErrantType)
            return false;

        return true;
    }
};
