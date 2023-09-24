#pragma once
#include <cmath>
class Wolf
{
    public:
    //персональные характеристики:
    int id; //идентификатор
    float x; //координаты
    float y;
    float health; //текущий запас сил
    //общие характеристики:
    float agression=0.5; //вероятность преследования дичи
    float max_health=100.0; //максимальный запас здоровья
    float health_per_lenght=1.0; //расход сил на единицу длины
    float max_lenght=5.0; //максимальное перемещение за раз
    float vision_range=10.0; //радиус обзора
    float bite_range=3.0; //радиус захвата пищи
    //методы:
    Wolf(int id, float x, float y); //конструктор
    bool move(float dx, float dy); //перемещение на заданный вектор
    bool heal(float dh); //увеличение здоровья
    //int operator<=> (Wolf &w1, Wolf &w2); //сравнение запасов здоровья у двух волков
};

