#pragma once
class Area;
class Action
{
public:
	virtual bool perform(Area &area) = 0; //действие
	virtual ~Action() {} //деструктор
};

