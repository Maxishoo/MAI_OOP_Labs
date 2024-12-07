#include <Game_functions.h>
#include <Visitors.h>

std::mutex PRINT_MUTEX;
std::mutex FILE_MUTEX;
std::shared_mutex ARRAY_MUTEX;
bool GAME_RUNNING;

print::~print()
{
    static std::mutex mtx;
    std::lock_guard<std::mutex> lck(PRINT_MUTEX);
    std::cout << this->str();
    std::cout.flush();
}

void generate_npc(std::set<std::shared_ptr<NPC>> &array, const int COUNT, const int MAX_X, const int MAX_Y) noexcept
{
    const std::vector<std::string> names = {
        "Aragorn", "Legolas", "Gimli", "Gandalf", "Frodo",
        "Samwise", "Merry", "Pippin", "Boromir", "Eowyn",
        "Faramir", "Galadriel", "Elrond", "Arwen", "Theoden",
        "Eomer", "Treebeard", "Sauron", "Saruman", "Gollum",
        "Thorin", "Bilbo", "Smaug", "Balin", "Dwalin",
        "Kili", "Fili", "Bofur", "Bombur", "Dori",
        "Nori", "Ori", "Oin", "Gloin", "Bifur",
        "Bard", "Thranduil", "Beorn", "Radagast", "Tauriel"};

    std::cout << "Generating " << COUNT << " elements..." << std::endl;
    for (size_t i = 0; i < COUNT; ++i)
    {
        std::lock_guard<std::shared_mutex> lock(ARRAY_MUTEX);
        array.insert(factory(NpcType(std::rand() % 3 + 1), std::rand() % MAX_X, std::rand() % MAX_Y, names[std::rand() % names.size()] + std::to_string(std::rand() % 3)));
    }

    std::cout << "Starting list:" << std::endl
              << array;
}

void play_game(std::set<std::shared_ptr<NPC>> &array, const int COUNT, const int MAX_X, const int MAX_Y, const int MAX_TIME) noexcept
{
    // в начале генерируем нпс
    if (COUNT)
        generate_npc(array, COUNT, MAX_X, MAX_Y);

    // create threads
    GAME_RUNNING = true;
    std::thread fight_thread(std::ref(FightManager::get()));

    std::thread move_thread([&array, MAX_X, MAX_Y]()
                            {
        while (GAME_RUNNING)
        {
            // move phase
            {
                std::shared_lock<std::shared_mutex> lock(ARRAY_MUTEX);
                for (std::shared_ptr<NPC> npc : array)
                {
                    if (npc->is_alive())
                    {
                        npc->move(MAX_X, MAX_Y);
                    }
                }
            }

            // fight phase
            {
                std::shared_lock<std::shared_mutex> lock(ARRAY_MUTEX);
                for (std::shared_ptr<NPC> npc : array)
                {
                    for (std::shared_ptr<NPC> other : array)
                    {
                        if (other != npc && npc->is_alive() && other->is_alive() && npc->is_close(other))
                        {
                            FightManager::get().add_event({npc, other});
                        }
                    }
                }
            }

            std::this_thread::sleep_for(50ms);
        } });

    int counter = MAX_TIME; // max game time = 30 seconds
    while (counter--)
    {
        const int grid{20}, step_x{MAX_X / grid}, step_y{MAX_Y / grid};
        {
            std::array<char, grid * grid> fields{0};
            {
                std::shared_lock<std::shared_mutex> lock(ARRAY_MUTEX);
                for (std::shared_ptr<NPC> npc : array)
                {
                    auto [x, y] = npc->position();
                    int i = x / step_x;
                    int j = y / step_y;

                    if (npc->is_alive())
                    {
                        switch (npc->get_type())
                        {
                        case PegasusType:
                            fields[i + grid * j] = 'P';
                            break;
                        case SquirrelType:
                            fields[i + grid * j] = 'S';
                            break;
                        case KnightErrantType:
                            fields[i + grid * j] = 'K';
                            break;
                        default:
                            break;
                        }
                    }
                    else
                    {
                        fields[i + grid * j] = '.';
                    }
                }
            }

            std::lock_guard<std::mutex> lck(PRINT_MUTEX);
            for (int j = 0; j < grid; ++j)
            {
                for (int i = 0; i < grid; ++i)
                {
                    char c = fields[i + j * grid];
                    if (c != 0)
                        std::cout << "[" << c << "]";
                    else
                        std::cout << "[ ]";
                }
                std::cout << std::endl;
            }
            std::cout << "Timer: " << counter << std::endl;
        }
        std::this_thread::sleep_for(1s);
    }
    GAME_RUNNING = false;
    move_thread.join();
    fight_thread.join();

    std::cout << "List of survivors:\n";
    {
        std::shared_lock<std::shared_mutex> lock(ARRAY_MUTEX);
        for (auto i : array)
        {
            if (i->is_alive())
                std::cout << *i << std::endl;
        }
    }

    return;
}

FightManager::FightManager() {}

FightManager &FightManager::get()
{
    static FightManager instance;
    return instance;
}

void FightManager::add_event(FightEvent &&event)
{
    std::lock_guard<std::shared_mutex> lock(mtx);
    events.push(event);
}

void FightManager::operator()()
{
    while (GAME_RUNNING)
    {
        {
            std::optional<FightEvent> event;
            {
                std::lock_guard<std::shared_mutex> lock(mtx);
                if (!events.empty())
                {
                    event = events.back();
                    events.pop();
                }
            }
            if (event)
            {
                if (event->attacker->is_alive())
                {
                    if (event->defender->is_alive())
                    {
                        NPCFighter fighter(event->attacker);

                        bool success = event->defender->accept(fighter);
                        if (success)
                            event->defender->must_die();
                    }
                }
            }
            else
                std::this_thread::sleep_for(5ms);
        }
    }
}

std::set<std::shared_ptr<NPC>> fight(std::set<std::shared_ptr<NPC>> &array, size_t distance) noexcept
{
    std::set<std::shared_ptr<NPC>> dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && (attacker->is_close(defender)))
            {
                NPCFighter fighter(attacker);

                bool success = defender->accept(fighter);
                if (success)
                    dead_list.insert(defender);
            }

    return dead_list;
}

std::ostream &operator<<(std::ostream &os, std::set<std::shared_ptr<NPC>> &array) noexcept
{
    int j = 0;
    for (auto i : array)
        os << ++j << ": " << (*i) << "\n";
    return os;
}

void save(const std::set<std::shared_ptr<NPC>> &array, const std::string &filename) noexcept
{
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (auto &n : array)
        n->save(fs);
    fs.flush();
    fs.close();
}

std::set<std::shared_ptr<NPC>> load(const std::string &filename) noexcept
{
    std::set<std::shared_ptr<NPC>> result;
    std::ifstream is(filename);
    if (is.good() && is.is_open())
    {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i)
            result.insert(factory(is));
        is.close();
    }
    else
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
    return result;
}

void add_NPC(std::set<std::shared_ptr<NPC>> &array, std::shared_ptr<NPC> npc) noexcept
{
    array.insert(npc);
}

void add_NPC(std::set<std::shared_ptr<NPC>> &array, NpcType type, int x, int y, std::string name) noexcept
{
    array.insert(factory(type, x, y, name));
}