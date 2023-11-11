#pragma once
#include "Action.h"
class Action_Reproduce :
    public Action
{
    int reproduce_id; //id размножаемого объекта
public:
    Action_Reproduce(int reproduce_id) : reproduce_id(reproduce_id) {} //конструктор
    bool perform(Area &area); //размножение
};

