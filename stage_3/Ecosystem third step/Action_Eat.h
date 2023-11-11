#pragma once
#include "Action.h"
class Action_Eat :
    public Action
{
    int food_id; //id пищи и того, кто её съел
    int eater_id;
public:
    Action_Eat(int food_id, int eater_id) : food_id(food_id), eater_id(eater_id) {}//конструктор
    bool perform(Area &area); //потребление
};

