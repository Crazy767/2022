#include <iostream>

#define _CRT_NO_WARNINGS
using namespace std;

template <class T1, class T2>
class Coordinates
{
private:
	T1 first;
	T2 second;

public:
	Coordinates(T1 first = 0, T2 second = 0)
	{
		this->first = first;
		this->second = second;
	}

	Coordinates(const Coordinates& obj)
	{
		this->first = obj.first;
		this->second = obj.second;
	}

	const Coordinates operator+(const T1& num) {
		this->first += num;
		this->second += num;
		return *this;
	}

	Coordinates operator=(Coordinates c)
	{
		first = c.first;
		second = c.second;
		return *this;
	}

	template <class T1, class T2>
	friend ostream& operator<<(ostream& os, const Coordinates<T1, T2>& c);

	void print()
	{
		cout << "print(x = " << first << " y = " << second << ")" << endl;
	}
};
template <class T1, class T2>
ostream& operator<<(ostream& os, const Coordinates<T1, T2>& c)
{
	return os << "x = " << c.first << " y = " << c.second << endl;
}

int main()
{
	Coordinates<int, float> coord(1, 2.5);
	Coordinates<int, float> coord2;
	cout << "coord:  ";
	cout << coord;
	cout << "coord2:  ";
	coord2.print();
	coord2 = coord;
	cout << "coord2:  ";
	coord2.print();
	cout << "coord2:  ";
	coord2 = coord2 + 2;
	coord2.print();
}