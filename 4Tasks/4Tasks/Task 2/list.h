#include <list>
#include <iostream>

struct task2
{
private:
	std::list<int> l;
public:
	void add5_back()
	{
		srand(time(0));
		for (int i = 0; i != 5; i++)
			l.push_back(rand() % 1000);
	}

	void print_begin() { std::cout << "First element: " << l.front(); }

	void add2_front()
	{
		srand(time(0));
		l.push_front(rand() % 1000);
		l.push_front(rand() % 1000);
	}

	void del4_element() { l.erase(std::next(l.begin(), 3)); }

	void add_random3()
	{
		srand(time(0));
		int number = rand() % 1000;
		for (int i = 0; i != 3; i++) { l.insert(std::next(l.begin(), rand() % l.size()), number); }
	}

	void pop_back() { l.pop_back(); }
	void pop_front() { l.pop_front(); }

	void add2_middle()
	{
		srand(time(0));
		l.splice(std::next(l.begin(), int(l.size() / 2)), std::list<int>(2, rand() % 100));
	}

	void unique() { l.unique(); }

	void clear() { l.clear(); }

	void print_is_clear() 
	{ std::cout << std::endl << ((l.size() == NULL) ? "List Clear" : "List Not Clear"); }

	void print()
	{
		std::cout << std::endl << "List: ";
		for (auto i : l) { std::cout << i << " "; }
	}
};