#include "Action_Grow.h"
#include "Area.h"
#include "Nature.h"

bool Action_Grow::perform(Area &area)
{
	char grow_type = area.get_object(grow_id)->get_type();
	if (grow_type == 'w')
	{
		area.get_object(grow_id)->heal(area.get_object(grow_id)->get_health_refill());
	}
	if (grow_type == 'h')
	{
		area.get_object(grow_id)->heal(area.get_object(grow_id)->get_health_refill());
	}
	if (grow_type == 'c')
	{
		area.get_object(grow_id)->heal(area.get_object(grow_id)->get_health_refill());
	}
	return true;
}