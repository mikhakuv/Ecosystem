#include "Wolf.h"
Wolf::Wolf(int id, float x, float y)
{
    this->id = id;
    this->x = x;
    this->y = y;
    health = max_health;
}

bool Wolf::move(float dx, float dy)
{
    float lenght;
    float dh;
    lenght = pow(pow(dx, 2) + pow(dy, 2), 0.5);
    dh = health_per_lenght * lenght;
    if (lenght > max_lenght || dh > health) { return false; }
    x += dx;
    y += dy;
    health -= dh;
    return true;
}

bool Wolf::heal(float dh)
{
    if (health + dh > max_health) { return false; }
    health += dh;
    return true;
}

//int Wolf::operator<=> (Wolf w1, Wolf w2)
//{
//    if (w1.health > w2.health) { return -1; }
//    if (w1.health = w2.health) { return 0; }
//    if (w1.health < w2.health) { return 1; }
//}