#include "Cabbage.h"
#include "Area.h"
#include "Action.h"
#include<list>
using std::list;

bool Cabbage::heal(float dh)
{
    if (health + dh > max_health)
    {
        dh = max_health - health;
    }
    health += dh;
    return true;
}

list<Action*> Cabbage::propose_action(const Area& area)
{
    //нужно просто сидеть и расти
    //но если достигнут максимальный запас сил, то нужно размножиться
    list<Action*> proposition;
    if (health == max_health)
    {
        proposition.push_back(new Action_Reproduce(get_id()));
        return proposition;
    }
    else
    {
        proposition.push_back(new Action_Grow(get_id()));
        return proposition;
    }
}