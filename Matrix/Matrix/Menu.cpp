#include "Menu.h"

Menu::Menu() { setlocale(LC_ALL, ""); start(); }

void Menu::set_vector()
{
	auto m = [](std::vector<std::vector<int>>& v, int size) {
		std::vector<int> temp;
		srand(time(0));
		if (!v.empty()) { v.clear(); }
		for (int i = 0; i != size; i++)
		{
			for (int j = 0; j != size; j++)
			{
				if (i > j)
				{ temp.push_back(0); }
				else 
				{ temp.push_back((rand()%9)+1); }
			}
		v.push_back(temp);
		temp.clear();
		}
	};

	system("cls");
	std::cout << "Введите размер первой матрицы: ";
	int size;
	std::cin >> size;
	m(v1, size);
	std::cout <<"Введите размер второй матрицы: ";
	std::cin >> size;
	m(v2, size);
	std::cout << std::endl << std::endl << "Нажмите, чтобы продолжить..."; _getch();
}

void Menu::sum()
{
	system("cls");
	auto p = [](std::vector<std::vector<int>>& v) {
		for (auto i : v)
		{
			for (auto j : i)
			{
				std::cout << j << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl;
	};

	if (!v1.empty())
	{
		p(v1);
		p(v2);

		if (v1.size() == v2.size())
		{
			std::vector<std::vector<int>> temp;
			std::vector<int> temp_num;
			for (int i = 0; i != v1.size(); i++)
			{
				for (int j = 0; j != v1.size(); j++)
				{ temp_num.push_back(v1[i][j] + v2[i][j]); }
				temp.push_back(temp_num);
				temp_num.clear();
			}
			std::cout << "Сумма матриц" << std::endl;
			p(temp);
		}
		else
		{
			std::cout << "Матрицы должны быть одинакого размера!";
		}
	}
	else
	{
		std::cout << "Матрицы пустые!";
	}
	std::cout << std::endl << std::endl << "Нажмите, чтобы продолжить..."; _getch();
}

void Menu::minus()
{
	system("cls");
	auto p = [](std::vector<std::vector<int>>& v) {
		for (auto i : v)
		{
			for (auto j : i)
			{
				std::cout << j << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl;
	};

	if (!v1.empty())
	{
		p(v1);
		p(v2);

		if (v1.size() == v2.size())
		{
			std::vector<std::vector<int>> temp;
			std::vector<int> temp_num;
			for (int i = 0; i != v1.size(); i++)
			{
				for (int j = 0; j != v1.size(); j++)
				{
					temp_num.push_back(v1[i][j] - v2[i][j]);
				}
				temp.push_back(temp_num);
				temp_num.clear();
			}
			std::cout << "Разность матриц" << std::endl;
			p(temp);
		}
		else
		{
			std::cout << "Матрицы должны быть одинакого размера!";
		}
	}
	else
	{
		std::cout << "Матрицы пустые!";
	}
	std::cout << std::endl << std::endl << "Нажмите, чтобы продолжить..."; _getch();
}

void Menu::proiz()
{
	system("cls");
	auto p = [](std::vector<std::vector<int>>& v) {
		for (auto i : v)
		{
			for (auto j : i)
			{
				std::cout << j << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl;
	};

	if (!v1.empty())
	{
		p(v1);
		p(v2);

		if (v1.size() == v2.size())
		{
			std::vector<std::vector<int>> temp(v1.size());
			for (int i = 0; i != v1.size(); i++)
			{
				temp[i].resize(v1.size());
				for (int j = 0; j != v1.size(); j++)
				{
					for (int inner = 0; inner != v1.size(); inner++) {
						temp[i][j] += v1[i][inner] * v2[inner][j];
					}
				}
			}
			std::cout << "Произведение матриц" << std::endl;
			p(temp);
		}
		else
		{
			std::cout << "Матрицы должны быть одинакого размера!";
		}
	}
	else
	{
		std::cout << "Матрицы пустые!";
	}
	std::cout << std::endl << std::endl << "Нажмите, чтобы продолжить..."; _getch();
}

void Menu::trans()
{
	system("cls");
	auto p = [](std::vector<std::vector<int>>& v) {
		for (auto i : v)
		{
			for (auto j : i)
			{
				std::cout << j << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl;
	};

	auto t = [](std::vector<std::vector<int>>& temp) {
		for (int i = 0; i < temp.size(); ++i)
			for (int j = i + 1; j < temp.size(); ++j)
				std::swap(temp[i][j], temp[j][i]);
	};

	if (!v1.empty())
	{
		p(v1);
		p(v2);

		t(v1);
		t(v2);
		std::cout << "Транспонированные матрицы" << std::endl;
		p(v1);
		p(v2);
	}
	else
	{
		std::cout << "Матрицы пустые!";
	}
	std::cout << std::endl << std::endl << "Нажмите, чтобы продолжить..."; _getch();
}

void Menu::print()
{
	system("cls");
	auto p = [](std::vector<std::vector<int>>& v) {
		for (auto i : v)
		{
			for (auto j : i)
			{ std::cout << j << " "; }
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl;
	};
	if (!v1.empty()) 
	{
		p(v1);
		p(v2);
	}
	else
	{ std::cout << "Матрицы пустые!"; }
	std::cout << std::endl << std::endl << "Нажмите, чтобы продолжить..."; _getch();
}

void Menu::start()
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
		case kb::enter:
			if (pos.Y == 0) { set_vector(); }
			else if (pos.Y == 1) { sum(); }
			else if (pos.Y == 2) { minus(); }
			else if (pos.Y == 3) { proiz(); }
			else if (pos.Y == 4) { trans(); }
			else if (pos.Y == 5) { print(); }
			else { exit(true); }
			break;
		default:
			break;
		}
	} while (true);
}

void Menu::cursor()
{
	SetConsoleCursorPosition(cons, pos);
	if (pos.Y == 6) { SetConsoleTextAttribute(cons, (((2 << 5) | 0))); }
	else { SetConsoleTextAttribute(cons, (((2 << 4) | 0))); }
	std::cout << menu_starts[pos.Y];
	SetConsoleTextAttribute(cons, 0 | 15);
}

void Menu::print_menu(std::vector<std::string> menu)
{
	system("cls");
	system("color 7");
	for (auto i : menu_starts) //Вывод меню
		std::cout << i << std::endl;
}