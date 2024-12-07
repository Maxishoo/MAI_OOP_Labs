#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <set>
#include <math.h>
#include <exception>
#include <cstring>
#include <cerrno>

#include <shared_mutex>
#include <thread>
#include <mutex>
#include <chrono>
#include <queue>
#include <optional>
#include <array>
#include <sstream>

using namespace std::chrono_literals;

extern std::mutex PRINT_MUTEX;

enum NpcType
{
    KnightErrantType = 1,
    SquirrelType = 2,
    PegasusType = 3
};