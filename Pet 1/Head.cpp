#include "Head.h"
#include <iostream>
#include <cstdlib>

void Head::Eat(Food& food) {
	//tail growth
}

bool Head::Move(std::array<std::array<Base*, 32>, 16>& grid, char dir) {
	switch (dir) {
	case 'w':
		if (grid[y - 1][x]->patency == true && grid[y - 1][x]->eatable == true) {
			grid[y - 1][x] = this;
			tail->Move(grid, x, y, true);
			while (true) {
				short randx = rand() % grid[0].size(), randy = rand() % grid.size();
				if (grid[randy][randx]->texture == 'O') {
					delete food;
					food = new Food;
					grid[randy][randx] = food;
					break;
				}
			}
			y--;
			return true;
		}
		else if (grid[y - 1][x]->patency == true) {
			delete grid[y - 1][x];
			grid[y - 1][x] = this; 
			tail->Move(grid, x, y);
			y--;
			return true;
		}
		else {
			return false;
		}
		break;
	case 'a':
		if (grid[y][x - 1]->patency == true && grid[y][x - 1]->eatable == true) {
			grid[y][x - 1] = this;
			tail->Move(grid, x, y, true);
			while (true) {
				short randx = rand() % grid[0].size(), randy = rand() % grid.size();
				if (grid[randy][randx]->texture == 'O') {
					delete food;
					food = new Food;
					grid[randy][randx] = food;
					break;
				}
			}
			x--;
			return true;
		}
		else if (grid[y][x - 1]->patency == true) {
			delete grid[y][x - 1];
			grid[y][x - 1] = this;
			tail->Move(grid, x, y);
			x--;
			return true;
		}
		else {
			return false;
		}
		break;
	case 's':
		if (grid[y + 1][x]->patency == true && grid[y + 1][x]->eatable == true) {
			grid[y + 1][x] = this;
			tail->Move(grid, x, y, true);
			while (true) {
				short randx = rand() % grid[0].size(), randy = rand() % grid.size();
				if (grid[randy][randx]->texture == 'O') {
					delete food;
					food = new Food;
					grid[randy][randx] = food;
					break;
				}
			}
			y++;
			return true;
		}
		else if (grid[y + 1][x]->patency == true) {
			delete grid[y + 1][x];
			grid[y + 1][x] = this;
			tail->Move(grid, x, y);
			y++;
			return true;
		}
		else {
			return false;
		}
		break;
	case 'd':
		if (grid[y][x + 1]->patency == true && grid[y][x + 1]->eatable == true) {
			grid[y][x + 1] = this;
			tail->Move(grid, x, y, true);
			while (true) {
				short randx = rand() % grid[0].size(), randy = rand() % grid.size();
				if (grid[randy][randx]->texture == 'O') {
					delete food;
					food = new Food;
					grid[randy][randx] = food;
					break;
				}
			}
			x++;
			return true;
		}
		else if (grid[y][x + 1]->patency == true) {
			delete grid[y][x + 1];
			grid[y][x + 1] = this;
			tail->Move(grid, x, y);
			x++;
			return true;
		}
		else {
			return false;
		}
		break;
	default:
		break;
	}
}