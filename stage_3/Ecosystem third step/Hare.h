#pragma once
#include "Nature.h"
class Hare : public Nature
{
public:
    const float agression = 0.9; //вероятность преследования капусты
    const float max_health = 50.0; //максимальный запас здоровья
    const float start_health = 30.0; //стартовый запас здоровья
    const float health_per_reproduce = 10.0; //потеря здоровья при делении
    const float health_per_length = 0.5; //расход сил на единицу длины
    const float max_length = 3.0; //максимальное перемещение за раз
    const float vision_range = 12.0; //радиус обзора
    const float bite_range = 1.0; //радиус захвата капусты
    Hare(int id, float x, float y) : Nature(id, x, y) { health = start_health; } //конструктор, наследуется от базового класса
    bool move(float dx, float dy); //перемещение на заданный вектор
    bool heal(float dh); //увеличение здоровья
    char get_type() const //вывод типа животного
    {
        return 'h';
    }
    float get_health_refill() const //вывод восстановления здоровья
    {
        return 0.0;
    }
    float get_health_decrease() const //вывод уменьшения здоровья при делении
    {
        return health_per_reproduce;
    }
    void show() const //вывод соответствующего символа(если здоровья много, то символ большой)
    {
        if (health >= start_health)
            printf("H");
        else
            printf("h");
    }
    list<Action*> propose_action(const Area& area); //предложить действие
};

