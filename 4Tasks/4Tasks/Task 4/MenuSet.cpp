#include "MenuSet.h"

MenuSet::MenuSet() { start(); }

void MenuSet::set() 
{
	system("cls");
	set1.clear();
	set2.clear();
	auto m = [](std::set<int> &temp) {
		std::string str;
		int n = 0;
		std::getline(std::cin, str);
		std::istringstream i(str);
		while (i >> n)
			temp.insert(n);
	};
	std::cout << "Введите числа (через пробел) для заполнения множества А: ";
	m(set1);
	std::cout << "Введите числа (через пробел) для заполнения множества B: ";
	m(set2);
	std::cout << std::endl << "Нажмите, чтобы продолжить..."; _getch();
}

void MenuSet::set_and()
{
	system("cls");
	print_set();
	
	std::vector<int> v;
	std::set_intersection(set1.begin(), set1.end(),
		set2.begin(), set2.end(), std::back_inserter(v));

	if (v.empty())
		std::cout << std::endl << "Нет совпадений!";
	else
		std::cout << std::endl << "Пересечение: ";
		for (int n : v)
			std::cout << n << ' ';

	std::cout << std::endl << std::endl << "Нажмите, чтобы продолжить..."; _getch();
}

void MenuSet::set_or()
{
	system("cls");
	print_set();

	std::vector<int> v;
	std::set_union(set1.begin(), set1.end(),
		set2.begin(), set2.end(), std::back_inserter(v));

	if (v.empty())
		std::cout << std::endl << "Нет объединения!";
	else
		std::cout << std::endl << "Объединение: ";
	for (int n : v)
		std::cout << n << ' ';

	std::cout << std::endl << std::endl << "Нажмите, чтобы продолжить..."; _getch();
}

void MenuSet::set_difference()
{
	system("cls");
	print_set();

	std::vector<int> v;
	std::set_difference(set1.begin(), set1.end(),
		set2.begin(), set2.end(), std::back_inserter(v));

	if (v.empty())
		std::cout << std::endl << "Нет разницы!";
	else
		std::cout << std::endl << "A-B: ";
	for (int n : v)
		std::cout << n << ' ';

	std::cout << std::endl << std::endl << "Нажмите, чтобы продолжить..."; _getch();
}

void MenuSet::set_addition()
{
	system("cls");
	print_set();

	auto print_set = [](std::set<int> set1, std::set<int> set2, std::string str_set) {
		std::vector<int> v;
		std::set_difference(set1.begin(), set1.end(),
			set2.begin(), set2.end(), std::back_inserter(v));

		if (v.empty())
			std::cout << std::endl << "Нет дополнения для множества " << str_set;
		else
			std::cout << std::endl << "Дополнения множества " << str_set << ": ";
		for (int n : v)
			std::cout << n << ' ';
	};

	print_set(set2, set1, "A");
	print_set(set1, set2, "B");

	std::cout << std::endl << std::endl << "Нажмите, чтобы продолжить..."; _getch();
}

void MenuSet::print_set()
{

	if (set1.empty())
		std::cout << "Множество А пустое";
	else
		std::cout << "Множество А: ";
		for (int n : set1)
			std::cout << n << " ";

	if (set2.empty())
		std::cout << std::endl << "Множество B пустое";
	else
		std::cout << std::endl << "Множество B: ";
		for (int n : set2)
			std::cout << n << " ";

	std::cout << std::endl;
}

void MenuSet::start()
{
	pos.Y = 0, pos.X = 0;
	do
	{
		print_menu(menu_starts);
		cursor();
		auto input = _getch();
		switch (input) //Перемещение по меню (стрелки, ENTER, ESC)
		{
		case kb::down:
			if (pos.Y == menu_starts.size() - 1)
			{
				pos.Y = 0; break;
			}
			pos.Y++;
			break;
		case kb::up:
			if (pos.Y == 0)
			{
				pos.Y = menu_starts.size() - 1; break;
			}
			pos.Y--;
			break;
		case 27:
			system("CLS");
			break;
		case kb::enter:
			if (pos.Y == 0) { set(); }
			else if (pos.Y == 1) { set_and(); }
			else if (pos.Y == 2) { set_or(); }
			else if (pos.Y == 3) { set_difference(); }
			else if (pos.Y == 4) { set_addition(); }
			else { exit(true); }
			break;
		default:
			break;
		}
	} while (true);
}

void MenuSet::cursor()
{
	SetConsoleCursorPosition(cons, pos);
	if (pos.Y == 5) { SetConsoleTextAttribute(cons, (((2 << 5) | 0))); }
	else { SetConsoleTextAttribute(cons, (((2 << 4) | 0))); }
	std::cout << menu_starts[pos.Y];
	SetConsoleTextAttribute(cons, 0 | 15);
}

void MenuSet::print_menu(std::vector<std::string> menu)
{
	system("cls");
	system("color 7");
	for (auto i : menu_starts) //Вывод меню
		std::cout << i << std::endl;
}
