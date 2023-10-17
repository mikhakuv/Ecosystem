#include<cassert>
#include"Wolf.h"
#include"Hare.h"
#include"Cabbage.h"


void test_wolf()
{
	Wolf w1(0, 20.0, 30.0); //проверка создания объекта
	assert(w1.id == 0);
	assert(w1.x == 20.0);
	assert(w1.y == 30.0);
	assert(w1.health == w1.max_health);

	bool bool_result; //проверка движения на допустимое расстояние
	float current_health;
	bool_result = w1.move(5.0, 0.0);
	current_health = w1.max_health - w1.health_per_length * 5.0;
	assert(bool_result == true);
	assert(w1.x == 25.0);
	assert(w1.y == 30.0);
	assert(w1.health == current_health);

	bool_result = w1.move(0.0, 7.0); //проверка движения на недопустимое расстояние
	assert(w1.y == 35.0); //объект должен передвинуться на параллельный вектор меньшей длины
	bool_result = w1.move(-7.0, 0.0); //ещё одна проверка движения на недопустимое расстояние
	assert(w1.x == 20.0);

	w1.health = 1.0; //проверка движения при нехватке здоровья
	bool_result = w1.move(5.0, 0.0);
	assert(w1.health == 0.5); //объект должен передвинуться так, чтобы осталась ещё половина здоровья

	float add_health;
	add_health = 3.0; //проверка пополнения здоровья до допустимого уровня
	w1.health = w1.max_health - add_health;
	bool_result = w1.heal(add_health);
	assert(bool_result == true);
	assert(w1.health == w1.max_health);

	bool_result = w1.heal(0.1); //проверка пополнения здоровья до недопустимого уровня
	assert(w1.health==w1.max_health);

	Wolf w2(1, 40.0, 50.0); //проверка сравнения здоровья
	assert(w2.health == w2.max_health);
	int int_result;
	int_result = w1 <=> w2;
	assert(int_result == 0);
	bool_result = w1.move(5.0, 0.0);
	int_result = w1 <=> w2;
	assert(int_result = 1);
	int_result = w2 <=> w1;
	assert(int_result = -1);
}

void test_hare()
{
	Hare h1(0, 20.0, 30.0); //проверка создания объекта
	assert(h1.id == 0);
	assert(h1.x == 20.0);
	assert(h1.y == 30.0);
	assert(h1.health == h1.max_health);

	bool bool_result; //проверка движения на допустимое расстояние
	float current_health;
	bool_result = h1.move(3.0, 0.0);
	current_health = h1.max_health - h1.health_per_length * 3.0;
	assert(bool_result == true);
	assert(h1.x == 23.0);
	assert(h1.y == 30.0);
	assert(h1.health == current_health);

	bool_result = h1.move(0.0, 7.0); //проверка движения на недопустимое расстояние
	assert(h1.y == 33.0); //объект должен передвинуться на параллельный вектор меньшей длины
	bool_result = h1.move(-7.0, 0.0); //ещё одна проверка движения на недопустимое расстояние
	assert(h1.x == 20.0);

	h1.health = 1.0; //проверка движения при нехватке здоровья
	bool_result = h1.move(2.0, 0.0);
	assert(h1.health == 0.5); //объект должен передвинуться так, чтобы осталась ещё половина здоровья

	float add_health;
	add_health = 3.0; //проверка пополнения здоровья до допустимого уровня
	h1.health = h1.max_health - add_health;
	bool_result = h1.heal(add_health);
	assert(bool_result == true);
	assert(h1.health == h1.max_health);

	bool_result = h1.heal(0.1); //проверка пополнения здоровья до недопустимого уровня
	assert(h1.health == h1.max_health);

	Hare h2(1, 40.0, 50.0); //проверка сравнения здоровья
	assert(h2.health == h2.max_health);
	int int_result;
	int_result = h1 <=> h2;
	assert(int_result == 0);
	bool_result = h1.move(5.0, 0.0);
	int_result = h1 <=> h2;
	assert(int_result = 1);
	int_result = h2 <=> h1;
	assert(int_result = -1);
}

void test_cabbage()
{
	Cabbage c1(0, 20.0, 30.0); //проверка создания объекта
	assert(c1.id == 0);
	assert(c1.x == 20.0);
	assert(c1.y == 30.0);
	assert(c1.health == c1.start_health);

	bool bool_result;
	float add_health;
	add_health = c1.max_health-c1.start_health; //проверка пополнения здоровья до допустимого уровня
	bool_result = c1.heal(add_health);
	assert(bool_result == true);
	assert(c1.health == c1.max_health);

	bool_result = c1.heal(0.1); //проверка пополнения здоровья до недопустимого уровня
	assert(c1.health == c1.max_health);

	Cabbage c2(1, 40.0, 50.0); //проверка сравнения здоровья
	assert(c2.health == c2.start_health);
	c1.health = c1.start_health;
	int int_result;
	int_result = c1 <=> c2;
	assert(int_result == 0);
	bool_result = c2.heal(c2.health_refill);
	int_result = c1 <=> c2;
	assert(int_result = 1);
	int_result = c2 <=> c1;
	assert(int_result = -1);
}