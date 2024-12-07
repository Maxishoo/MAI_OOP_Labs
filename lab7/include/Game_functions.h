#pragma once
#include <Factory.h>
#include <lab7.h>

// Game func
struct print : std::stringstream
{
    ~print();
};

struct FightEvent
{
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class FightManager
{
private:
    std::queue<FightEvent> events;
    std::shared_mutex mtx;

    FightManager();

public:
    static FightManager &get();

    void add_event(FightEvent &&event);

    void operator()();
};

void generate_npc(std::set<std::shared_ptr<NPC>> &array, const int COUNT, const int MAX_X, const int MAX_Y) noexcept;
void play_game(std::set<std::shared_ptr<NPC>> &array, const int COUNT, const int MAX_X, const int MAX_Y, const int MAX_TIME) noexcept;

std::set<std::shared_ptr<NPC>> fight(std::set<std::shared_ptr<NPC>> &array, size_t distance) noexcept;
std::ostream &operator<<(std::ostream &os, std::set<std::shared_ptr<NPC>> &array) noexcept;

// Objects func
void add_NPC(std::set<std::shared_ptr<NPC>> &array, std::shared_ptr<NPC> npc) noexcept;
void add_NPC(std::set<std::shared_ptr<NPC>> &array, NpcType type, int x, int y, std::string name) noexcept;

// File funcs
void save(const std::set<std::shared_ptr<NPC>> &array, const std::string &filename) noexcept;
std::set<std::shared_ptr<NPC>> load(const std::string &filename) noexcept;