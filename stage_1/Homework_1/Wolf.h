#pragma once
#include <cmath>
class Wolf
{
    public:
    //персональные характеристики:
    int id; //идентификатор
    //private: //не используем, потому что тесты работать не будут
    float x; //координаты
    float y;
    float health; //текущий запас сил
    //общие характеристики:
    const float agression=0.5; //вероятность преследования дичи
    const float max_health=100.0; //максимальный запас здоровья
    const float health_per_length=1.0; //расход сил на единицу длины
    const float max_length=5.0; //максимальное перемещение за раз
    const float vision_range=10.0; //радиус обзора
    const float bite_range=3.0; //радиус захвата пищи
    //методы:
    Wolf(int id, float x, float y); //конструктор
    bool move(float dx, float dy); //перемещение на заданный вектор
    bool heal(float dh); //увеличение здоровья
    int operator<=> (Wolf &w2); //сравнение запасов здоровья у двух волков(& для экономии памяти)
};

