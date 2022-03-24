#include "Tail.h"
#include <array>

void Tail::Move(std::array<std::array<Base*, 32>, 16>& grid, short x, short y, bool satiety) {
	grid[y][x] = this;
	if (tail != NULL) {
		tail->Move(grid, this->x, this->y, satiety);
	}
	else if (satiety == true) {
		tail = new Tail(this->x, this->y, this);
		grid[this->y][this->x] = tail;
	}
	else {
		grid[this->y][this->x] = new Base;
	}
	this->x = x;
	this->y = y;
}