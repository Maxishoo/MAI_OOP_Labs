#pragma once
#include <NPC.h>

class Visitor;

class Pegasus : public NPC
{
public:
    Pegasus(int x, int y, std::string name);
    Pegasus(std::istream &is);

    bool accept(Visitor &visitor) noexcept override;

    virtual bool is_close(const std::shared_ptr<NPC> &other) noexcept override;
    virtual void move(int max_x, int max_y) noexcept override;
};
