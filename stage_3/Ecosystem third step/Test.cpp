#include<cassert>
#include"Wolf.h"
#include"Hare.h"
#include"Cabbage.h"
#include"Area.h"


void test_wolf()
{
	Wolf w1(0, 20.0, 30.0); //проверка создания объекта
	assert(w1.get_id() == 0);
	assert(w1.get_x() == 20.0);
	assert(w1.get_y() == 30.0);
	assert(w1.get_health() == w1.start_health);

	bool bool_result; //проверка движения на допустимое расстояние
	float current_health;
	bool_result = w1.move(5.0, 0.0);
	current_health = w1.start_health - w1.health_per_length * 5.0;
	assert(bool_result == true);
	assert(w1.get_x() == 25.0);
	assert(w1.get_y() == 30.0);
	assert(w1.get_health() == current_health);

	bool_result = w1.move(0.0, 7.0); //проверка движения на недопустимое расстояние
	assert(w1.get_y() == 35.0); //объект должен передвинуться на параллельный вектор меньшей длины
	bool_result = w1.move(-7.0, 0.0); //ещё одна проверка движения на недопустимое расстояние
	assert(w1.get_x() == 20.0);

	w1.health = 1.0; //проверка движения при нехватке здоровья
	bool_result = w1.move(5.0, 0.0);
	assert(w1.get_health() == 0.5); //объект должен передвинуться так, чтобы осталась ещё половина здоровья

	float add_health;
	add_health = 3.0; //проверка пополнения здоровья до допустимого уровня
	w1.health = w1.max_health - add_health;
	bool_result = w1.heal(add_health);
	assert(bool_result == true);
	assert(w1.get_health() == w1.max_health);

	bool_result = w1.heal(0.1); //проверка пополнения здоровья до недопустимого уровня
	assert(w1.get_health() == w1.max_health);

	Wolf w2(1, 40.0, 50.0); //проверка сравнения здоровья
	assert(w2.get_health() == w2.start_health);
	w2.health = w2.max_health;
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
	assert(h1.get_id() == 0);
	assert(h1.get_x() == 20.0);
	assert(h1.get_y() == 30.0);
	assert(h1.get_health() == h1.start_health);

	bool bool_result; //проверка движения на допустимое расстояние
	float current_health;
	bool_result = h1.move(3.0, 0.0);
	current_health = h1.start_health - h1.health_per_length * 3.0;
	assert(bool_result == true);
	assert(h1.get_x() == 23.0);
	assert(h1.get_y() == 30.0);
	assert(h1.get_health() == current_health);

	bool_result = h1.move(0.0, 7.0); //проверка движения на недопустимое расстояние
	assert(h1.get_y() == 33.0); //объект должен передвинуться на параллельный вектор меньшей длины
	bool_result = h1.move(-7.0, 0.0); //ещё одна проверка движения на недопустимое расстояние
	assert(h1.get_x() == 20.0);

	h1.health = 1.0; //проверка движения при нехватке здоровья
	bool_result = h1.move(2.0, 0.0);
	assert(h1.get_health() == 0.5); //объект должен передвинуться так, чтобы осталась ещё половина здоровья

	float add_health;
	add_health = 3.0; //проверка пополнения здоровья до допустимого уровня
	h1.health = h1.max_health - add_health;
	bool_result = h1.heal(add_health);
	assert(bool_result == true);
	assert(h1.get_health() == h1.max_health);

	bool_result = h1.heal(0.1); //проверка пополнения здоровья до недопустимого уровня
	assert(h1.get_health() == h1.max_health);

	Hare h2(1, 40.0, 50.0); //проверка сравнения здоровья
	assert(h2.get_health() == h2.start_health);
	int int_result;
	h2.health = h2.max_health;
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
	assert(c1.get_id() == 0);
	assert(c1.get_x() == 20.0);
	assert(c1.get_y() == 30.0);
	assert(c1.get_health() == c1.start_health);

	bool bool_result;
	float add_health;
	add_health = c1.max_health - c1.start_health; //проверка пополнения здоровья до допустимого уровня
	bool_result = c1.heal(add_health);
	assert(bool_result == true);
	assert(c1.get_health() == c1.max_health);

	bool_result = c1.heal(0.1); //проверка пополнения здоровья до недопустимого уровня
	assert(c1.get_health() == c1.max_health);

	Cabbage c2(1, 40.0, 50.0); //проверка сравнения здоровья
	assert(c2.get_health() == c2.start_health);
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

void test_area()
{
	Area a1(50.0, 100.0, 2, 10, 20); //проверка создания области
	assert(a1.current_step() == 0);
	assert(a1.free_id() == 33);
	map<int, shared_ptr<Nature> > objects = a1.get_objects();
	int wolves = 0;
	int hares = 0;
	int cabbages = 0;
	for (auto it = objects.begin(); it != objects.end(); ++it)
	{
		assert(it->second->get_x() < a1.x_size || it->second->get_y() < a1.y_size);
		assert(it->second->get_health() > 0);
		assert(it->second->get_id() > 0);
		if (it->second->get_type() == 'w')
			wolves++;
		if (it->second->get_type() == 'h')
			hares++;
		if (it->second->get_type() == 'c')
			cabbages++;
	}
	assert(wolves == 2);
	assert(hares == 10);
	assert(cabbages == 20);

	a1.show_area(); //проверка показа области(ну тут только визуально проверить можно)

	a1.print_info(); //проверка статистики(тоже визуально)

	Nature *w1 = new Wolf(a1.free_id(), 10.0, 10.0); //проверка добавления объекта
	a1.add_object(w1);
	assert(a1.free_id()==34);
	wolves = 0;
	hares = 0;
	cabbages = 0;
	for (auto it = objects.begin(); it != objects.end(); ++it)
	{
		assert(it->second->get_x() < a1.x_size || it->second->get_y() < a1.y_size);
		assert(it->second->get_health() > 0);
		assert(it->second->get_id() > 0);
		if (it->second->get_type() == 'w')
			wolves++;
		if (it->second->get_type() == 'h')
			hares++;
		if (it->second->get_type() == 'c')
			cabbages++;
	}
	assert(a1.wolves_amount == 3);
	assert(a1.hares_amount == 10);
	assert(a1.cabbages_amount == 20);

	printf("Enter smth to start simulation"); //проверка симуляции(того, что шаги совершаются)
	scanf_s("\n");
	for (int i = 1; i <= 30; i++)
	{
		a1.make_step();
	}
	a1.show_area();
	a1.print_info();
	assert(a1.current_step() == 30);
}
