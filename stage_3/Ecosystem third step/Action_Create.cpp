#include "Action_Create.h"
#include "Area.h"

bool Action_Create::perform(Area& area)
{
	area.add_object(n);
	return true;
}