#pragma once
#include "Base.h"
#include <array>
#include "Tail.h"
#include "Food.h"
class Head : public Base
{
public:
	Tail* tail;
	Food* food;
	short x, y;
	Head(Tail& tail, Food& food, short x, short y) : Base('H', false), x(x), y(y)
	{
		this->tail = &tail;
	}
	bool Move(std::array<std::array<Base*, 32>, 16>& grid, char dir);
	void Eat(Food& food);
};

