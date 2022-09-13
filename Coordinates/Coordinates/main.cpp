#include <iostream>
using namespace std;
class Coordinates 
{
private:
	int first, second;

public:
	Coordinates(int first = 0, int second = 0)
	{
		this->first = first;
		this->second = second;
	}

	Coordinates(const Coordinates &obj)
	{
		this->first = obj.first;
		this->second = obj.second;
	}

	const Coordinates operator+(const int& num) {
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

	friend ostream& operator<<(ostream& os, const Coordinates& c);

	void print()
	{
		cout << "print(x = " << first << " y = " << second << ")" << endl;
	}
};

ostream& operator<<(ostream& os, const Coordinates& c)
{
	return os << "x = " << c.first << " y = " << c.second << endl;
}

int main()
{
	Coordinates coord(1,2);
	Coordinates coord2;
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

