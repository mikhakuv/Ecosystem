#pragma once
#include<map>
#include<memory>
#include<cmath>
using std::map;
using std::shared_ptr;
class Nature;
class Area
{
private:
	map<int, shared_ptr<Nature> > objects; //словарь указателей на базовый класс объектов области
	int step; //номер шага
	int wolves_amount; //количество волков
	int hares_amount; //количество зайцев
	int cabbages_amount; //количество капусты
	int available_id; //номер свободного id
public:
	const float x_size; //ширина карты
	const float y_size; //высота карты
	Area(float x_size, float y_size, int wolves_amount, int hares_amount, int cabbages_amount); //конструктор
	void show_area() const; //вывод области
	void print_info() const; //вывод информации
	bool add_object(Nature* obj);
	void make_step(); //моделирование шага
	shared_ptr<Nature> get_object(int id) const //вывод указателя на объект по его id
	{
		auto it = objects.find(id);
		if (it != objects.end())
			return it->second;
		else
			return nullptr;
	}
	const map<int, shared_ptr<Nature> >& get_objects() const //вывод всего словаря
	{
		return objects;
	}
	int current_step() const //текущий шаг моделирования
	{
		return step;
	}
	int free_id() const //номер свободного id
	{
		return available_id;
	}
	friend void test_area();
};

