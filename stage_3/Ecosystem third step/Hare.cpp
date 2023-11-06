#include "Hare.h"
#include "Area.h"
#include "Action.h"
#include<list>
using std::list;

bool Hare::move(float dx, float dy)
{
    float length;
    float dh;
    length = pow(pow(dx, 2) + pow(dy, 2), 0.5);
    dh = health_per_length * length;
    if (length > max_length)
    {
        dx = dx * max_length / length;
        dy = dy * max_length / length;
        dh = health_per_length * max_length;
    }
    if (dh >= health)
    {
        dx = dx * (0.5 * health) / dh;
        dy = dy * (0.5 * health) / dh;
        dh = 0.5 * health;
    }
    x += dx;
    y += dy;
    health -= dh;
    return true;
}

bool Hare::heal(float dh)
{
    if (health + dh > max_health)
    {
        dh = max_health - health;
    }
    health += dh;
    return true;
}

list<Action*> Hare::propose_action(const Area& area)
{
    //нужно пройтись по всем объектам на карте
    // укусить(eat) любую капусту ближе, чем bite_range
    //если нет, то с вероятностью agression начать двигаться(move) в сторону капусты, которая ближе чем vision_range
    //если и этого нет, то передвинуться на случайный вектор
    list<Action*> proposition;
    float hare_x = area.get_object(get_id())->get_x();
    float hare_y = area.get_object(get_id())->get_y();
    map<int, shared_ptr<Nature> > objects = area.get_objects();
    for (auto it = objects.begin(); it != objects.end(); ++it)
    {
        if (it->second->get_type() == 'c')
        {
            float cabbage_x = it->second->get_x();
            float cabbage_y = it->second->get_y();
            float distance = pow(pow(hare_x - cabbage_x, 2) + pow(hare_y - cabbage_y, 2), 0.5);
            if (distance <= bite_range) //можно ещё сделать видимость через границу, но пока этого нет
            {
                proposition.push_back(new Action_Eat(it->second->get_id(), get_id()));
                return proposition;
            }
                
        }
    }

    for (auto it = objects.begin(); it != objects.end(); ++it)
    {
        if (it->second->get_type() == 'c')
        {
            float cabbage_x = it->second->get_x();
            float cabbage_y = it->second->get_y();
            float distance = pow(pow(hare_x - cabbage_x, 2) + pow(hare_y - cabbage_y, 2), 0.5);
            if (distance <= vision_range)
            {
                proposition.push_back(new Action_Move(get_id(), cabbage_x-hare_x, cabbage_y-hare_y));
                return proposition;
            }
        }
    }

    float dx = pow(max_length,0.5) * (rand() % 10000) / 10000.0;
    float dy = pow(max_length,0.5) * (rand() % 10000) / 10000.0;
    proposition.push_back(new Action_Move(get_id(), dx, dy));
    return proposition;
}