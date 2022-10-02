#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <sstream>
#include <algorithm>

static std::vector<std::string> menu_starts = { "Задать множества", 
												"Найти пересечение множеств", 
												"Найти объединение множеств", 
												"Найти разность множеств A-B", 
												"Найти дополнения множеств",
												"Выход" };
namespace kb { enum Buttons { down = 80, up = 72, enter = 13 }; }

class MenuSet 
{
	HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	std::set<int> set1;
	std::set<int> set2;
public:
	MenuSet();

private:
	void set();

	void set_and();

	void set_or();

	void set_difference();

	void set_addition();

	void print_set();


	void start();
	//Перемещение курсора
	void cursor();

	void print_menu(std::vector<std::string> menu);
};