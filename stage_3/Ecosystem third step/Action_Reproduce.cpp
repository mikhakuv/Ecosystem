#include "Action_Reproduce.h"
#include "Area.h"
#include "Nature.h"

bool Action_Reproduce::perform(Area &area)
{
	char reproduce_type = area.get_object(reproduce_id)->get_type();
	float reproduce_x = area.get_object(reproduce_id)->get_x();
	float reproduce_y = area.get_object(reproduce_id)->get_y();
	int free_id = area.free_id();
	if (reproduce_type == 'w')
	{
		Nature* w = new Wolf(free_id, reproduce_x, reproduce_y);
		area.add_object(w);
	}
	if (reproduce_type == 'h')
	{
		Nature* h = new Hare(free_id, reproduce_x, reproduce_y);
		area.add_object(h);
	}
	if (reproduce_type == 'c')
	{
		float x_shift = (rand() % 10000) / 10000.0;
		float y_shift = (rand() % 10000) / 10000.0;
		Nature* c = new Cabbage(free_id, reproduce_x+x_shift, reproduce_y+y_shift);
		area.add_object(c);
	}
	return true;
}