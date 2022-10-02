#include <vector>
#include <iostream>
#include <algorithm>
struct task1
{
	std::vector<int> vector;
	
	task1() { vector.resize(20); }

	void generate()
	{
		srand(time(0));
		for (std::vector<int>::iterator i = vector.begin(); i != vector.end(); i++)
			{
				*i = (rand() % 201) - 100;
				std::cout << *i << " ";
			}
	}

	void max_min()
	{
		auto a = std::minmax_element(vector.begin(), vector.end());
		std::cout << "min: " << *a.first << "  max :" << *a.second;
	}

	void sort() { std::sort(vector.begin(), vector.end()); }

	void add4_element()
	{
		std::for_each(vector.begin(), vector.begin() + 4, [this](auto i)
			{
				vector.push_back((rand() % 201) - 100);
			});
	}

	void less_10()
	{
		for (auto i = vector.begin(); i != vector.end(); i++)
			if (*i < 10) { *i = 0; }
	}

	void find_over20()
	{
		std::cout << std::endl << "Over 20: ";
		std::count_if(vector.begin(), vector.end(), [](auto i)
			{
				if (i > 20) 
				{
					std::cout << i << " ";
					return i;
				}
			});
	}

	void even_multiply_3()
	{
		std::count_if(vector.begin(), vector.end(), [](auto& i)
			{
				if (i % 2 == 0 && i != 0)
				{ return i*=3; }
			});
	}

	void random()
	{ std::random_shuffle(vector.begin(), vector.end()); }

	void del_over50()
	{
		vector.erase( 
			std::remove_if(
				vector.begin(), vector.end(), [](auto i)
				{ return i > 50; }), 
			vector.end());
	}

	void count_print()
	{
		std::cout << std::endl << "Count: " << vector.size();
		if (vector.size() % 2 == 0) 
		{
			std::cout << std::endl << "Reverse: ";
			for (auto i = vector.rbegin(); i != vector.rend(); i++)
			{
				std::cout << *i << " ";
			}
		}
		else
		{
			vector.erase(vector.end()-1, vector.end());
		}
	}

	void clear()
	{
		if (vector.size() != NULL)
			vector.clear();
		else
			std::cout << std::endl << "Vector clear";
	}

	void print()
	{
		std::cout << std::endl << "Vector: ";
		for (auto i : vector) { std::cout << i << " "; }
	}
};