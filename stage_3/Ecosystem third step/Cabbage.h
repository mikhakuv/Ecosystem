#pragma once
#include "Nature.h"
class Cabbage : public Nature
{
public:
    const float start_health = 5.0; //стартовый запас здоровья
    const float max_health = 30.0; //максимальный запас здоровья
    const float health_refill = 2.5; //пополнение здоровья за один шаг
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
    list<Action*> propose_action(const Area& area); //предложить действие
};

