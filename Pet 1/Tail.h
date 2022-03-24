#pragma once
#include "Base.h"
#include <array>
class Tail : public Base
{
public:
	short x, y;
	Tail* tail;
	Tail(short x, short y, Tail* = NULL) : Base('T', false), x(x), y(y)
	{
	}
	void Move(std::array<std::array<Base*, 32>, 16>& grid, short x, short y, bool satiety = false);
	void Growth();
};

