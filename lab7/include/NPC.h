#pragma once
#include <lab7.h>

class Visitor;
class NPC;

struct IFightObserver
{
    virtual void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) = 0;
};

class NPC : public std::enable_shared_from_this<NPC>
{
public:
    std::mutex mtx;
    NpcType type;
    std::string name;
    bool alive{true};
    int x{0};
    int y{0};
    std::vector<std::shared_ptr<IFightObserver>> observers;

    NPC(NpcType t, int _x, int _y, std::string name);
    NPC(NpcType t, std::istream &is);

    std::pair<int, int> position() noexcept;
    NpcType get_type() noexcept;

    void subscribe(std::shared_ptr<IFightObserver> observer) noexcept;
    void fight_notify(const std::shared_ptr<NPC> defender, bool win) noexcept;

    virtual void save(std::ostream &os) noexcept;
    virtual bool is_close(const std::shared_ptr<NPC> &other) = 0;
    virtual bool accept(Visitor &visitor) = 0;

    virtual void print() noexcept;

    friend std::ostream &operator<<(std::ostream &os, NPC &npc) noexcept;

    virtual void move(int max_x, int max_y) = 0;

    bool is_alive() noexcept;
    void must_die() noexcept;
};
