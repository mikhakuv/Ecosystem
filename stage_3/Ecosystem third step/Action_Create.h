#pragma once
#include "Action.h"
class Nature;
class Action_Create :
    public Action
{
    Nature* n;
public:
    Action_Create(Nature* n) : n(n) {} //конструктор
    bool perform(Area& area); //создание существа
};


