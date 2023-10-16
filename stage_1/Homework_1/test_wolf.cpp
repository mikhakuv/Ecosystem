#include<cassert>
#include"Wolf.h"

void test_Wolf()
{
	Wolf w1(0, 20.0, 30.0); //проверка создания объекта
	assert(w1.id == 0);
	assert(w1.x == 20.0);
	assert(w1.y == 30.0);
	assert(w1.health == w1.max_health);

	bool bool_result; //проверка движения на допустимое расстояние
	float current_health;
	bool_result = w1.move(5.0, 0.0);
	current_health = w1.max_health - w1.health_per_length*5.0;
	assert(bool_result == true);
	assert(w1.x == 25.0);
	assert(w1.y == 30.0);
	assert(w1.health == current_health);

	bool_result = w1.move(5.0, 7.0); //проверка движения на недопустимое расстояние
	assert(bool_result == false);

	w1.health = 0.1; //проверка движения при нехватке здоровья
	bool_result = w1.move(5.0, 0.0);
	assert(bool_result == false);
	w1.health = current_health;

	float add_health;
	add_health = w1.max_health - current_health; //проверка пополнения здоровья до допустимого уровня
	bool_result = w1.heal(add_health);
	assert(bool_result == true);
	assert(w1.health == w1.max_health);

	bool_result = w1.heal(1.0); //проверка пополнения здоровья до недопустимого уровня
	assert(bool_result == false);

	Wolf w2(1, 40.0, 50.0); //проверка сравнения здоровья
	assert(w2.health == w2.max_health);
	int int_result;
	int_result = w1 <=> w2;
	assert(int_result == 0);
	bool_result = w1.move(5.0, 0.0);
	int_result = w1 <=> w2;
	assert(int_result=1);
	int_result = w2 <=> w1;
	assert(int_result=-1);
}

//int main()
//{
//	test_Wolf(); //видно, что всё работает
//	return 0;
//}