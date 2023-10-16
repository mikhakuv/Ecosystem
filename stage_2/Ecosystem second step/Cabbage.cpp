#include "Cabbage.h"

//Cabbage::Cabbage(int id, float x, float y)
//{
//    this->id = id;
//    this->x = x;
//    this->y = y;
//    health = start_health;
//}

bool Cabbage::heal(float dh)
{
    if (health + dh > max_health)
    {
        dh = max_health - health;
    }
    health += dh;
    return true;
}