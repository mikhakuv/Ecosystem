#pragma once
#include "Nature.h"
class Wolf : public Nature
{
public:
    const float agression = 0.7; //вероятность преследования зайца
    const float max_health = 100.0; //максимальный запас здоровья
    const float health_per_length = 1.0; //расход сил на единицу длины
    const float max_length = 5.0; //максимальное перемещение за раз
    const float vision_range = 7.0; //радиус обзора
    const float bite_range = 3.0; //радиус захвата зайца
    Wolf(int id, float x, float y) : Nature(id, x, y) { health = max_health; } //конструктор, наследуется от базового класса
    bool move(float dx, float dy); //перемещение на заданный вектор
    bool heal(float dh); //увеличение здоровья
    char get_type() const //вывод типа животного
    {
        return 'w';
    }
    float get_health_refill() const //вывод восстановления здоровья
    {
        return 0.0;
    }
    void show() const //вывод соответствующего символа(если здоровья много, то символ большой)
    {
        if (health >= max_health / 2)
            printf("W");
        else
            printf("w");
    }
    list<Action*> propose_action(const Area& area); //предложить действие
};

