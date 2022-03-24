#include <iostream>
#include <vector>
#include "Base.h"
#include "Head.h"
#include "Wall.h"
#include "Tail.h"
#include "Food.h"
int main() {
	char temp;
	std::cout << "Snake" << std::endl;
	std::cout << "Control: enter w/a/s/d/ and press Enter" << std::endl;
	std::cout << "Enter any key to start" << std::endl;
	std::cin >> temp;
	system("cls");
	//создание поля
	std::array<std::array<Base*, 32>, 16> grid;
	for (int i = 0; i < grid.size(); i++) {
		if (i == 0 || i == (grid.size() - 1)) {
			for (int o = 0; o < grid[i].size(); o++) {
				grid[i][o] = new Wall;
			}
		}
		else {
			for (int o = 0; o < grid[i].size(); o++) {
				if (o == 0 || o == (grid[i].size() - 1)) {
					grid[i][o] = new Wall;
				}
				else {
					grid[i][o] = new Base;
				}
			}
		}
	}
	//создание змейки
	Food* pFood = new Food();
	grid[9][9] = pFood;
	Tail* pTail = new Tail(7, 8);
	grid[8][7] = pTail;
	Head* pHead = new Head(*pTail, *pFood, 8, 8);
	grid[8][8] = pHead;



	//отрисовка поля
	for (int i = 0; i < grid.size(); i++) {
		for (int o = 0; o < grid[i].size(); o++) {
			std::cout << grid[i][o]->texture;
		}
		std::cout << "\n";
	}

	//игровой цикл
	do {
		char input;
		std::cin >> input;
		if (pHead->Move(grid, input)) {
			//отрисовка поля
			system("cls");
			for (int i = 0; i < grid.size(); i++) {
				for (int o = 0; o < grid[i].size(); o++) {
					std::cout << grid[i][o]->texture;
				}
				std::cout << "\n";
			}
			continue;
		}
		else {
			break; // врезание в препятствие, конец игры
		}
	} while (true);
	
	return 0;
}