#include <gtest/gtest.h>
#include <Game_functions.h>
#include <Visitors.h>

TEST(test_01, basic_test_set)
{
    std::set<std::shared_ptr<NPC>> array;

    array.insert(factory(KnightErrantType, 0, 0, "Bob"));
    array.insert(factory(SquirrelType, 49, 49, "Homa"));

    play_game(array, 0, 50, 50, 10);

    int alive_count = 0;
    int dead_count = 0;
    std::for_each(array.begin(), array.end(), [&alive_count, &dead_count](const std::shared_ptr<NPC> &npc)
                  {
        if (npc->is_alive())
        {
            ++alive_count;
        }
        else
        {
            ++dead_count;
        } });

    ASSERT_TRUE(alive_count == 1 and dead_count == 1);
}
TEST(test_02, basic_test_set)
{
    std::set<std::shared_ptr<NPC>> array;

    array.insert(factory(KnightErrantType, 0, 0, "Bob"));
    array.insert(factory(KnightErrantType, 50, 50, "Homa"));
    array.insert(factory(KnightErrantType, 10, 10, "Homa2"));

    play_game(array, 0, 100, 100, 10);

    int alive_count = 0;
    int dead_count = 0;
    std::for_each(array.begin(), array.end(), [&alive_count, &dead_count](const std::shared_ptr<NPC> &npc)
                  {
        if (npc->is_alive())
        {
            ++alive_count;
        }
        else
        {
            ++dead_count;
        } });

    ASSERT_TRUE(alive_count == 3 and dead_count == 0);
}
TEST(test_03, basic_test_set)
{
    std::set<std::shared_ptr<NPC>> array;

    play_game(array, 50, 200, 200, 10);

    int alive_count = 0;
    int dead_count = 0;
    std::for_each(array.begin(), array.end(), [&alive_count, &dead_count](const std::shared_ptr<NPC> &npc)
                  {
        if (npc->is_alive())
        {
            ++alive_count;
        }
        else
        {
            ++dead_count;
        } });

    ASSERT_TRUE(alive_count + dead_count == 50);
}
TEST(test_04, basic_test_set)
{
    std::set<std::shared_ptr<NPC>> array;

    auto a = factory(SquirrelType, 0, 0, "Bob");
    auto b = factory(KnightErrantType, 1, 1, "Bobik");
    array.insert(a);
    array.insert(b);

    play_game(array, 0, 20, 20, 10);

    ASSERT_TRUE(!a->is_alive());
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}