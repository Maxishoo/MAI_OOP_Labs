#include <gtest/gtest.h>
#include <Game_functions.h>
#include <Visitors.h>

TEST(test_01, basic_test_set)
{
    std::set<std::shared_ptr<NPC>> array;

    array.insert(factory(KnightErrantType, 0, 0, "Bob"));
    array.insert(factory(KnightErrantType, 100, 100, "Petr"));
    array.insert(factory(SquirrelType, 5, 5, "Homa"));
    array.insert(factory(PegasusType, 20, 20, "Peppa"));

    auto dead_list = fight(array, 10);

    ASSERT_TRUE(dead_list.size() == 1);
}
TEST(test_02, basic_test_set)
{
    std::set<std::shared_ptr<NPC>> array;

    array.insert(factory(KnightErrantType, 0, 0, "Bob"));
    array.insert(factory(KnightErrantType, 100, 100, "Petr"));
    array.insert(factory(SquirrelType, 5, 5, "Homa"));
    array.insert(factory(PegasusType, 20, 20, "Peppa"));

    auto dead_list = fight(array, 25);

    ASSERT_TRUE(dead_list.size() == 2);
}
TEST(test_03, basic_test_set)
{
    std::set<std::shared_ptr<NPC>> array;
    auto b = factory(SquirrelType, 5, 5, "Homa");
    array.insert(factory(KnightErrantType, 0, 0, "Bob"));
    array.insert(b);

    auto dead_list = fight(array, 10);

    ASSERT_TRUE(dead_list.contains(b) == true);
}
TEST(test_04, basic_test_set)
{
    std::set<std::shared_ptr<NPC>> array;
    auto b = factory(SquirrelType, 5, 5, "Homa");
    array.insert(factory(SquirrelType, 0, 0, "Bob"));
    array.insert(b);

    auto dead_list = fight(array, 10);

    ASSERT_TRUE(dead_list.contains(b) == false);
}
TEST(test_05, basic_test_set)
{
    std::set<std::shared_ptr<NPC>> array;
    auto b = factory(PegasusType, 5, 5, "Homa");
    array.insert(factory(SquirrelType, 100, 100, "Bob"));
    array.insert(b);

    auto dead_list = fight(array, 10);

    ASSERT_TRUE(dead_list.contains(b) == false);
}
TEST(test_06, basic_test_set)
{
    std::set<std::shared_ptr<NPC>> array;
    auto b = factory(PegasusType, 5, 5, "Homa");
    array.insert(factory(SquirrelType, 100, 100, "Bob"));
    array.insert(b);

    auto dead_list = fight(array, 150);

    ASSERT_TRUE(dead_list.contains(b) == true);
}
TEST(test_07, basic_test_set)
{
    std::set<std::shared_ptr<NPC>> array;
    auto b = factory(KnightErrantType, 5, 5, "Homa");
    array.insert(factory(PegasusType, 100, 100, "Bob"));
    array.insert(b);

    auto dead_list = fight(array, 100);

    ASSERT_TRUE(dead_list.size() == 0);
}

// Trapezoid
TEST(test_08, basic_test_set)
{
    auto a = factory(SquirrelType, 5, 5, "Kn");
    auto b = factory(KnightErrantType, 5, 5, "Sq");
    NPCFighter fighter(b);

    ASSERT_TRUE(a->accept(fighter));
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}