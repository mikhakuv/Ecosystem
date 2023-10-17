#pragma once
#include <cmath>
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
    virtual int operator<=> (Nature& w2); //сравнение запасов здоровья у двух существ(& для экономии памяти)
    virtual ~Nature() {} //деструктор виртуальный, чтобы хранить объекты в едином контейнере
    friend void test_wolf(); //тесты - дружественные функции и имеют доступ к protected переменным
    friend void test_hare();
    friend void test_cabbage();
};

