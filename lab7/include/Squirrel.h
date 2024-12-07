#pragma once
#include <lab7.h>
#include <NPC.h>

class Visitor;

class Squirrel : public NPC
{
public:
    Squirrel(int x, int y, std::string name);
    Squirrel(std::istream &is);

    bool accept(Visitor &visitor) noexcept override;

    virtual bool is_close(const std::shared_ptr<NPC> &other) noexcept override;
    virtual void move(int max_x, int max_y) noexcept override;
};
