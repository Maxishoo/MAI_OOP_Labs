#pragma once
#include <Factory.h>

// Game func
std::set<std::shared_ptr<NPC>> fight(std::set<std::shared_ptr<NPC>> &array, size_t distance);
std::ostream &operator<<(std::ostream &os, std::set<std::shared_ptr<NPC>> &array);

void add_NPC(std::set<std::shared_ptr<NPC>> &array, std::shared_ptr<NPC> npc);
void add_NPC(std::set<std::shared_ptr<NPC>> &array, NpcType type, int x, int y, std::string name);

//File funcs
void save(const std::set<std::shared_ptr<NPC>> &array, const std::string &filename);
std::set<std::shared_ptr<NPC>> load(const std::string &filename);