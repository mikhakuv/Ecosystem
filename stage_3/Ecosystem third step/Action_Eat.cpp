#include "Action_Eat.h"
#include "Area.h"
#include "Nature.h"

bool Action_Eat::perform(Area& area)
{
	area.get_object(eater_id)->heal(area.get_object(food_id)->get_health());
	area.get_object(food_id)->kill();
	return true;
}
