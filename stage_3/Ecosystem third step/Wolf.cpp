#include "Wolf.h"
#include "Area.h"
#include "Action.h"
#include<list>
using std::list;

bool Wolf::move(float dx, float dy)
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

bool Wolf::heal(float dh)
{
    if (health + dh > max_health)
    {
        dh = max_health - health;
    }
    health += dh;
    return true;
}

list<Action*> Wolf::propose_action(const Area& area)
{
    //если достигнут максимальный запас сил, то нужно размножиться
    //нужно пройтись по всем объектам на карте
    // укусить(eat) любого зайца ближе, чем bite_range
    //если нет, то с вероятностью agression начать догонять(move) каждого зайца ближе, чем vision_range
    //если и этого нет, то передвинуться на случайный вектор
    list<Action*> proposition;
    if (health == max_health)
    {
        proposition.push_back(new Action_Reproduce(get_id()));
        return proposition;
    }

    float wolf_x = area.get_object(get_id())->get_x();
    float wolf_y = area.get_object(get_id())->get_y();
    map<int, shared_ptr<Nature> > objects = area.get_objects();
    for (auto it = objects.begin(); it != objects.end(); ++it)
    {
        if (it->second->get_type() == 'h')
        {
            float hare_x = it->second->get_x();
            float hare_y = it->second->get_y();
            float area_x = area.x_size;
            float area_y = area.y_size;

            //волки не видят через границу
            /*float distance = pow(pow(wolf_x - hare_x, 2) + pow(wolf_y - hare_y, 2), 0.5);
            if (distance <= bite_range)
            {
                proposition.push_back(new Action_Eat(it->second->get_id(), get_id()));
                return proposition;
            }*/

            //волки видят через границу
            float distance1 = pow(pow(wolf_x - hare_x, 2) + pow(wolf_y - hare_y, 2), 0.5);
            float distance2 = pow(pow(area_x + wolf_x - hare_x, 2) + pow(wolf_y - hare_y, 2), 0.5);
            float distance3 = pow(pow(wolf_x - hare_x, 2) + pow(area_y + wolf_y - hare_y, 2), 0.5);
            float distance4 = pow(pow(area_x + wolf_x - hare_x, 2) + pow(area_y + wolf_y - hare_y, 2), 0.5);
            if (distance1 <= bite_range || distance2 <= bite_range || distance3 <= bite_range || distance4 <= bite_range)
            {
                proposition.push_back(new Action_Eat(it->second->get_id(), get_id()));
                return proposition;
            }
        }
    }

    for (auto it = objects.begin(); it != objects.end(); ++it)
    {
        if (it->second->get_type() == 'h')
        {
            float hare_x = it->second->get_x();
            float hare_y = it->second->get_y();
            float area_x = area.x_size;
            float area_y = area.y_size;

            //волки не могут видеть сквозь границу
            /*float distance = pow(pow(wolf_x - hare_x, 2) + pow(wolf_y - hare_y, 2), 0.5);
            if (distance <= vision_range)
            {
                proposition.push_back(new Action_Move(get_id(), hare_x - wolf_x, hare_y - wolf_y));
                return proposition;
            }*/

            //волки могут видеть сквозь границу
            float distance1 = pow(pow(wolf_x - hare_x, 2) + pow(wolf_y - hare_y, 2), 0.5);
            float distance2 = pow(pow(area_x + wolf_x - hare_x, 2) + pow(wolf_y - hare_y, 2), 0.5);
            float distance3 = pow(pow(wolf_x - hare_x, 2) + pow(area_y + wolf_y - hare_y, 2), 0.5);
            float distance4 = pow(pow(area_x + wolf_x - hare_x, 2) + pow(area_y + wolf_y - hare_y, 2), 0.5);
            if (distance1<=distance2 && distance1<=distance3 && distance1<=distance4 && distance1 <= vision_range)
            {
                proposition.push_back(new Action_Move(get_id(), hare_x - wolf_x, hare_y - wolf_y));
                return proposition;
            }
            if (distance2 <= distance1 && distance2 <= distance3 && distance2 <= distance4 && distance2 <= vision_range)
            {
                proposition.push_back(new Action_Move(get_id(), hare_x - wolf_x - area_x, hare_y - wolf_y));
                return proposition;
            }
            if (distance3 <= distance1 && distance3 <= distance2 && distance3 <= distance4 && distance3 <= vision_range)
            {
                proposition.push_back(new Action_Move(get_id(), hare_x - wolf_x, hare_y - wolf_y - area_y));
                return proposition;
            }
            if (distance4 <= distance1 && distance4 <= distance2 && distance4 <= distance3 && distance4 <= vision_range)
            {
                proposition.push_back(new Action_Move(get_id(), hare_x - wolf_x - area_x, hare_y - wolf_y - area_y));
                return proposition;
            }
        }
    }

    float dx = pow(max_length, 0.5) * (rand() % 10000) / 10000.0;
    float dy = pow(max_length, 0.5) * (rand() % 10000) / 10000.0;
    proposition.push_back(new Action_Move(get_id(), dx, dy));
    return proposition;
}