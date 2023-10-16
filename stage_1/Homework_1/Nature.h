#pragma once
#include <cmath>
class Nature
{
public:
    //персональные характеристики:
    int id; //идентификатор
    //private: //не используем, потому что тесты работать не будут
    float x; //координаты
    float y;
    float health; //текущий запас сил
    //общие характеристики:
    const float agression; //вероятность преследования дичи
    const float max_health; //максимальный запас здоровья
    const float health_per_length; //расход сил на единицу длины
    const float max_length; //максимальное перемещение за раз
    const float vision_range; //радиус обзора
    const float bite_range; //радиус захвата пищи
    //методы:
    Nature(int id, float x, float y); //конструктор
    bool move(float dx, float dy); //перемещение на заданный вектор
    bool heal(float dh); //увеличение здоровья
    int operator<=> (Nature& w2); //сравнение запасов здоровья у двух волков(& для экономии памяти)
};