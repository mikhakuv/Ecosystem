#include "Wolf.h"
//Wolf::Wolf(int id, float x, float y)
//{
    //this->id = id;
    //this->x = x;
    //this->y = y;
    //health = max_health;
//}

bool Wolf::move(float dx, float dy)
{
    float length;
    float dh;
    length = pow(pow(dx, 2) + pow(dy, 2), 0.5);
    dh = health_per_length * length;
    if (length > max_length)
    {
        dx = dx * max_length / length;
        dy = dy * max_length / length;
        dh = health_per_length * max_length;
    }
    if (dh >= health)
    {
        dx = dx * (0.5 * health) / dh;
        dy = dy * (0.5 * health) / dh;
        dh = 0.5 * health;
    }
    x += dx;
    y += dy;
    health -= dh;
    return true;
}

bool Wolf::heal(float dh)
{
    if (health + dh > max_health)
    {
        dh = max_health - health;
    }
    health += dh;
    return true;
}