#pragma once
#include <lab6.h>
#include <NPC.h>

class Visitor;

class KnightErrant : public NPC
{
public:
    KnightErrant(int x, int y, std::string name);
    KnightErrant(std::istream &is);

    bool accept(Visitor &visitor) override;
};
