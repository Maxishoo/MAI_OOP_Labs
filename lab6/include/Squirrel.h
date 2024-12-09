#pragma once
#include <NPC.h>

class Visitor;

class Squirrel : public NPC
{
public:
    Squirrel(int x, int y, std::string name);
    Squirrel(std::istream &is);

    bool accept(Visitor &visitor) noexcept override;
};
