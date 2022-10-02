#include "Console.h"

Console::Console() 
{
	start();
}

void Console::add_element()
{
	system("cls");
	int elem;
	std::cout << "Введите элемент: ";
	std::cin >> elem;
	stack.push(elem);
	std::cout << std::endl << "Элемент успешно добавлен!";
	std::cout << std::endl << "Нажмите, чтобы продолжить..."; _getch();
}

void Console::del_element()
{
	system("cls");
	if (!stack.empty())
	{
		std::cout << "Элемент " << stack.top() << " был удален из стека";
		stack.pop();
	}
	else { std::cout << "Стек пуст, невозможно забрать элемент"; }
	std::cout << std::endl << "Нажмите, чтобы продолжить..."; _getch();
}

void Console::print_stack()
{
	auto l = [this](std::stack<int> temp)
	{
		while (!temp.empty())
		{
			SetConsoleTextAttribute(cons, 14);
			std::cout << "| ";
			SetConsoleTextAttribute(cons, 10);
			std::cout << temp.top();
			SetConsoleTextAttribute(cons, 14);
			std::cout << " |" << std::endl;
			temp.pop();
		}
	};

	system("cls");
	SetConsoleTextAttribute(cons, 14);
	std::cout << "|   |" << std::endl;

	l(stack);
	std::cout << "|___|";
	std::cout << std::endl << std::endl << "Нажмите, чтобы продолжить..."; _getch();
}

void Console::clear_stack()
{
	stack = std::stack<int>();
	system("cls");
	std::cout << "Стек очищен...";
	std::cout << std::endl << std::endl << "Нажмите, чтобы продолжить..."; _getch();
}

void Console::start()
{
	pos.Y = 0, pos.X = 0;
	do
	{
		print_menu(menu_start);
		cursor();
		auto input = _getch();
		switch (input) //Перемещение по меню (стрелки, ENTER, ESC)
		{
		case down:
			if (pos.Y == menu_start.size() - 1)
			{
				pos.Y = 0; break;
			}
			pos.Y++;
			break;
		case up:
			if (pos.Y == 0)
			{
				pos.Y = menu_start.size() - 1; break;
			}
			pos.Y--;
			break;
		case 27:
			system("CLS");
			break;
		case enter:
			if (pos.Y == 0) { add_element(); }
			else if (pos.Y == 1) { del_element(); }
			else if (pos.Y == 2) { print_stack(); }
			else if (pos.Y == 3) { clear_stack(); }
			else { exit(true); }
			break;
		default:
			break;
		}
	} while (true);
}

void Console::cursor()
{
	SetConsoleCursorPosition(cons, pos);
	if (pos.Y == 4) { SetConsoleTextAttribute(cons, (((2 << 5) | 0))); }
	else { SetConsoleTextAttribute(cons, (((2 << 4) | 0))); }
	std::cout << menu_start[pos.Y];
	SetConsoleTextAttribute(cons, 0 | 15);
}

void Console::print_menu(std::vector<std::string> menu)
{
	system("cls");
	system("color 7");
	for (auto i : menu_start) //Вывод меню
		std::cout << i << std::endl;
}
