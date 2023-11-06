#include <stdlib.h>
#include<cmath>
#include<ctime>
#include<list>
#include<stdexcept>
using std::list;
#include"Area.h"
#include"Action.h"
#include"Nature.h"
#include"Wolf.h"
#include"Hare.h"
#include"Cabbage.h"

Area::Area(float x_size, float y_size, int wolves, int hares, int cabbages):
	step(0), x_size(x_size), y_size(y_size), wolves_amount(0), hares_amount(0), cabbages_amount(0), available_id(1)
{
	if (x_size <= 0.0 || y_size <= 0.0 || wolves_amount < 0 || hares_amount < 0 || cabbages_amount < 0)
		throw std::domain_error("wrong parameters");
	srand(time(0));
	for (int i=1; i<=wolves; i++)
	{
		float x = x_size * (rand() % 10000) / 10000.0;
		float y = y_size * (rand() % 10000) / 10000.0;
		Nature *w = new Wolf(available_id, x, y);
		add_object(w);
	}
	for (int i=1; i<=hares; i++)
	{
		float x = x_size * (rand() % 10000) / 10000.0;
		float y = y_size * (rand() % 10000) / 10000.0;
		Nature* h = new Hare(available_id, x, y);
		add_object(h);
	}
	for (int i=1; i<=cabbages; i++)
	{
		float x = x_size * (rand() % 10000) / 10000.0;
		float y = y_size * (rand() % 10000) / 10000.0;
		Nature* c = new Cabbage(available_id, x, y);
		add_object(c);
	}
}

void Area::show_area() const
{
	printf("+");
	for (int y = 0; y < (int)y_size; ++y)
		printf("-");
	printf("+\n");
	for (int x = 0; x < (int)x_size; ++x) {
		printf("|");
		for (int y = 0; y < (int)y_size; ++y) {
			bool obj_found = false;
			for (auto it = objects.begin(); it != objects.end(); ++it)
			{
				if (it->second->get_x()-x < 0.5 && it->second->get_y()-y < 0.5)
				{
					it->second->show();
					obj_found = true;
					break;
				}
			}
			if (!obj_found)
				printf(" ");
		}
		printf("|\n");
	}
	printf("+");
	for (int y = 0; y < (int)y_size; ++y)
		printf("-");
	printf("+\n");
}

void Area::print_info() const
{
	float wolves_health = 0.0;
	float hares_health = 0.0;
	float cabbages_health = 0.0;
	for (auto it = objects.begin(); it != objects.end(); ++it)
	{
		if (it->second->get_type() == 'w')
			wolves_health += it->second->get_health();
		if (it->second->get_type() == 'h')
			hares_health += it->second->get_health();
		if (it->second->get_type() == 'c')
			cabbages_health += it->second->get_health();
	}
	printf("Wolves amount: %d, mean health: %f", wolves_amount, (wolves_health/wolves_amount));
	printf("Hares amount: %d, mean health: %f", hares_amount, (hares_health/hares_amount));
	printf("Cabbages amount: %d, mean health: %f", cabbages_amount, (cabbages_health/cabbages_amount));
}

bool Area::add_object(Nature* obj)
{
	if (obj->get_x() < 0.0 || obj->get_x() > x_size || obj->get_y() < 0.0 || obj->get_y() > y_size)
	{
		printf("wrong parameters\n");
		return false;
	}
		
	if (objects.find(obj->get_id()) != objects.end())
	{
		printf("object already exists\n");
		return false;
	}

	//objects[obj->get_id()] = shared_ptr<Nature>(obj);
	objects[obj->get_id()] = shared_ptr<Nature>(get_object(obj->get_id()));

	if (obj->get_type() == 'w')
		wolves_amount++;
	if (obj->get_type() == 'h')
		hares_amount++;
	if (obj->get_type() == 'c')
		cabbages_amount++;
	available_id++;
	return true;
}

void Area::make_step()
{
	list<Action*> step_actions;
	for (auto it = objects.begin(); it != objects.end(); ++it)
	{
		list<Action*> obj_actions = it->second->propose_action(*this);
		step_actions.splice(step_actions.end(), obj_actions);
	}
	for (auto it = step_actions.begin(); it != step_actions.end(); ++it)
	{
		(*it)->perform(*this);
		delete (*it);
	}

	auto it = objects.begin();
	while (it != objects.end())
	{
		if (it->second->get_health()<=0)
		{
			it = objects.erase(it);
			if (it->second->get_type() == 'w')
				wolves_amount--;
			if (it->second->get_type() == 'h')
				hares_amount--;
			if (it->second->get_type() == 'c')
				cabbages_amount--;
		}
		else
		{
			++it;
		}
	}
	step++;
}