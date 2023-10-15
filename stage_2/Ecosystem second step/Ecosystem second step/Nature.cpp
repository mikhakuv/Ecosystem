#include "Nature.h"

Nature::Nature(int id, float x, float y)
{
    this->id = id;
    this->x = x;
    this->y = y;
}

int Nature::operator<=> (Nature& w2)
{
    if (this->health > w2.health) { return -1; }
    if (this->health == w2.health) { return 0; }
    if (this->health < w2.health) { return 1; }
}