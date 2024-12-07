#pragma once
#include <lab7.h>
#include <NPC.h>

class Visitor;

class KnightErrant : public NPC
{
public:
    KnightErrant(int x, int y, std::string name);
    KnightErrant(std::istream &is);

    bool accept(Visitor &visitor) noexcept override;

    virtual bool is_close(const std::shared_ptr<NPC> &other) noexcept override;
    virtual void move(int max_x, int max_y) noexcept override;
};
