#pragma once
#include "Nature.h"
class Cabbage : public Nature
{
public:
    const float start_health = 5.0; //стартовый запас здоровья
    const float max_health = 30.0; //максимальный запас здоровья
    const float health_per_reproduce = 5.0; //потеря здоровья при делении
    const float health_refill = 0.1; //пополнение здоровья за один шаг
    Cabbage(int id, float x, float y) : Nature(id, x, y) { health = start_health; } //конструктор, наследуется от базового класса
    bool heal(float dh); //увеличение здоровья
    char get_type() const //вывод типа существа
    {
        return 'c';
    }
    void show() const //вывод соответствующего символа(если здоровья много, то символ большой)
    {
        if (health >= max_health / 2)
            printf("C");
        else
            printf("c");
    }
    float get_health_refill() const
    {
        return health_refill;
    }
    float get_health_decrease() const //вывод уменьшения здоровья при делении
    {
        return health_per_reproduce;
    }
    list<Action*> propose_action(const Area& area); //предложить действие
};

