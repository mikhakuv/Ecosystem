#pragma once
#include "Action_Grow.h"
#include "Action_Move.h"
#include "Action_Eat.h"
#include <cmath>
#include<list>
using std::list;

class Nature
{
protected: //не private чтобы наследуемые классы могли использовать эти переменные
    //персональные характеристики:
    int id; //идентификатор
    float x; //координаты
    float y;
    float health; //текущий запас сил
    //методы:
    Nature(int id, float x, float y);//конструктор
    virtual bool move(float dx, float dy); //перемещение на заданный вектор
    virtual bool heal(float dh); //увеличение здоровья
    void teleport(float tp_x, float tp_y) //телепортирование(для случая выхода за границы карты)
    {
        x = tp_x;
        y = tp_y;
    }
    void kill() //уничтожение
    {
        health = 0.0;
    }
    virtual int operator<=> (Nature& w2); //сравнение запасов здоровья у двух существ(& для экономии памяти)
    virtual ~Nature() {} //деструктор виртуальный, чтобы хранить объекты в едином контейнере
public:
    int get_id() const //вывод id
    {
        return id;
    }
    int get_x() const //вывод x
    {
        return x;
    }
    int get_y() const //вывод y
    {
        return y;
    }
    float get_health() const //вывод здоровья
    {
        return health;
    }
    virtual char get_type() const = 0; //вывод типа
    virtual float get_health_refill() const = 0; //вывод увеличения здоровья(для капусты)
    virtual void show() const = 0; //вывод соответствующего символа, нужно для рисования области
    virtual list<Action*> propose_action(const Area&) {return list<Action*>();} //предожить действие для объекта
    friend bool Action_Grow::perform(Area& area); //дружественные функции
    friend bool Action_Move::perform(Area& area);
    friend bool Action_Eat::perform(Area& area);
    friend void test_wolf();
    friend void test_hare();
    friend void test_cabbage();
};

