// var 18
#include <Game_functions.h>

int main()
{
    std::set<std::shared_ptr<NPC>> array;
    add_NPC(array,factory(KnightErrantType,1,2,"oleg"));
    add_NPC(array,factory(KnightErrantType,4,4,"peppa"));
    add_NPC(array,factory(KnightErrantType,5,6,"olesh"));

    std::cout<<array;
    auto dead_list = fight(array,10);
    for(auto i:dead_list)
        std::cout<<i<<std::endl;
    return 0;
}