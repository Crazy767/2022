#pragma once

#include <iostream>
using namespace std;
template <class T1, class T2>
class TPair
{
	T1 first; T2 second;
public:
	TPair(T1 _first = 0, T2 _second = 0) 
		:first(_first), second(_second) {}

	TPair(const TPair& obj) 
		:first(obj.first), second(obj.second) {}

	TPair operator+(const TPair& c)
	{ return TPair(first + c.first, second + c.second); }

	TPair& operator=(const TPair& c)
	{
		first = c.first;
		second = c.second;
		return *this;
	}

	template <class T1, class T2>
	friend ostream& operator<<(ostream& os, const TPair<T1, T2>& c);

	void print()
	{	std::cout << "First = " << first << " Second = " << second << std::endl; }

	void swap()
	{
		auto _first = first;
		first = second;
		second = _first;
	}
};

template <class T1, class T2>
ostream& operator<<(ostream& os, const TPair<T1, T2>& c)
{
	return os << "First = " << c.first << " Second = " << c.second << endl;
}