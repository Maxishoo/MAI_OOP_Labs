#pragma once
#include <lab6.h>
#include <../include/KnightErrant.h>
#include <Observer.h>

// Фабрики -----------------------------------
std::shared_ptr<NPC> factory(std::istream &is);

std::shared_ptr<NPC> factory(NpcType type, int x, int y, std::string name);