#pragma once
#include <KnightErrant.h>
#include <Pegasus.h>
#include <Squirrel.h>
#include <Observer.h>

// Фабрики -----------------------------------
std::shared_ptr<NPC> factory(std::istream &is) noexcept;

std::shared_ptr<NPC> factory(NpcType type, int x, int y, std::string name) noexcept;