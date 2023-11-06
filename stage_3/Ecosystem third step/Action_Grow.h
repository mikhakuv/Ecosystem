#pragma once
#include "Action.h"
class Action_Grow :
    public Action
{
    int grow_id;
public:
    Action_Grow(int grow_id) : grow_id(grow_id) {}
    bool perform(Area &area);
};

