#pragma once
#include "Nature.h"
class Cabbage:  public Nature
{
    public:
    const float start_health=5.0; //стартовый запас здоровья
    const float max_health=30.0; //максимальный запас здоровья
    const float health_refill=2.5; //пополнение здоровья за один шаг
    Cabbage(int id, float x, float y) : Nature(id, x, y) { health = start_health; } //конструктор, наследуется от базового класса
    bool heal(float dh); //увеличение здоровья
};

