#pragma once
#include "Action.h"
class Action_Move :
    public Action
{
    int id; //параметры движущегося объекта
    float x;
    float y;
public:
    Action_Move(int id, int x, int y): id(id), x(x), y(y) {} //конструктор
    bool perform(Area &area); //передвижение объекта
};

