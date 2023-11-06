#pragma once
#include "Nature.h"
class Hare : public Nature
{
public:
    const float agression = 0.9; //вероятность преследования капусты
    const float max_health = 50.0; //максимальный запас здоровья
    const float health_per_length = 0.5; //расход сил на единицу длины
    const float max_length = 3.0; //максимальное перемещение за раз
    const float vision_range = 12.0; //радиус обзора
    const float bite_range = 1.0; //радиус захвата капусты
    Hare(int id, float x, float y) : Nature(id, x, y) { health = max_health; } //конструктор, наследуется от базового класса
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
    void show() const //вывод соответствующего символа(если здоровья много, то символ большой)
    {
        if (health >= max_health / 2)
            printf("H");
        else
            printf("h");
    }
    list<Action*> propose_action(const Area& area); //предложить действие
};

