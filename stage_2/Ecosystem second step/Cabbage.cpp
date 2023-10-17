#include "Cabbage.h"

bool Cabbage::heal(float dh)
{
    if (health + dh > max_health)
    {
        dh = max_health - health;
    }
    health += dh;
    return true;
}