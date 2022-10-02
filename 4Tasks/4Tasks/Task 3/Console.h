#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <stack>

static std::vector<std::string> menu_start = { "Положить элемент", "Забрать элемент", "Вывести стек", "Очистить стек", "Выход" };
enum Button {down = 80, up = 72, enter = 13};

class Console
{
	HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	std::stack<int> stack;

public:
	Console();

private:
	void add_element();

	void del_element();

	void print_stack();

	void clear_stack();

	void start();
	//Перемещение курсора
	void cursor();

	void print_menu(std::vector<std::string> menu);
};

