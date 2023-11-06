#include "Action_Move.h"
#include "Area.h"
#include "Nature.h"

bool Action_Move::perform(Area &area)
{
	area.get_object(id)->move(x, y);

	float current_x = area.get_object(id)->get_x();
	float current_y = area.get_object(id)->get_y();
	if (current_x > area.x_size)
		area.get_object(id)->teleport(current_x - area.x_size, current_y);
	if (current_x < 0)
		area.get_object(id)->teleport(current_x + area.x_size, current_y);
	if (current_y > area.y_size)
		area.get_object(id)->teleport(current_x, current_y - area.y_size);
	if (current_y < 0)
		area.get_object(id)->teleport(current_x, current_y + area.y_size);
	return true;
}