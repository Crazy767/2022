#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <ctime>

struct vector
{
	std::vector<std::pair <std::string, float> > my_vector;

	vector(int size)
	{
		my_vector.resize(size);
	}

	void input()
	{
		for (std::vector<std::pair <std::string, float> >::iterator it = my_vector.begin(); it != my_vector.end(); it++)
		{
			std::cout << "string: ";
			std::cin >> it->first;
			std::cout << "float: ";
			std::cin >> it->second;
		}
	}

	void generate()
	{
		srand(time(0));
		std::vector<std::string> Status{ "public", "private", "protected" };
		for (auto& i : my_vector)
		{
			i.first = Status[std::rand() % 3];
			int mod = std::rand() % 4;
			i.second = (std::rand() % 100000) / std::pow(10, mod == 0 ? 1 : mod);
		}
	}

	void print()
	{
		for (auto i : my_vector)
		{
			std::cout << "first: " << i.first
				<< (i.first == "protected" ? "\tsecond: " : "\t\tsecond: ") << i.second << std::endl;
		}
	}
	void search()
	{
		float number;
		std::cout << "Input num: ";
		std::cin >> number;
		auto a = std::find_if(my_vector.begin(), my_vector.end(), [&](auto i)
			{
				{ return i.second == number; }
			});
		if (a->first == "public") { a->second = 0; }
		else if (a->first == "protected") { a->first = "private"; }
	}
};