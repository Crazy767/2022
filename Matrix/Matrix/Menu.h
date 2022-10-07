#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

static std::vector<std::string> menu_starts = { "Задать матрицы", 
												"Сложить матрицы", 
												"Вычесть матрицы", 
												"Умножить матрицы", 
												"Транспонировать матрицы",
												"Вывести матрицы",
												"Выход" };
namespace kb { enum Buttons { down = 80, up = 72, enter = 13 }; }

class Menu 
{
	HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	std::vector<std::vector<int>> v1;
	std::vector<std::vector<int>> v2;
public:
	Menu();

private:
	void set_vector();

	void sum();

	void minus();

	void proiz();

	void trans();

	void print();

	void start();
	//Перемещение курсора
	void cursor();

	void print_menu(std::vector<std::string> menu);
};