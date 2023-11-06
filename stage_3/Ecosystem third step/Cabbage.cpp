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
    list<Action*> proposition;
    proposition.push_back(new Action_Grow(get_id()));
    return proposition;
}