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
    float length;
    float dh;
    length = pow(pow(dx, 2) + pow(dy, 2), 0.5);
    dh = health_per_length * length;
    if (length > max_length || dh > health) { return false; }
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

int Wolf::operator<=> (Wolf &w2)
{
    if (this->health > w2.health) { return -1; }
    if (this->health = w2.health) { return 0; }
    if (this->health < w2.health) { return 1; }
}