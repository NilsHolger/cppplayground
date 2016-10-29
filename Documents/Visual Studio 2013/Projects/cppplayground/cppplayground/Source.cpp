#include "headers.h"
using namespace std;

class Address
{
public:
	string country;
	Address(){}
	Address(string const& country) : country(country)
	{
		cout << "address created" << '\n';
	}
	~Address()
	{
		cout << "address destroyed" << '\n';
	}
};
class Person
{
public:
	Address *address;
	Person(string const& country)
	{
		address = new Address(country);
		cout << "person created" << '\n';
	}
	~Person()
	{
		delete address;
		cout << "person destroyed" << '\n';
	}
};
class Person2
{
	Person2() {}
	Person2(const Person2& _) {}
	~Person2() {}

	int ref_count;
public:
	static Person2* create()
	{
		auto *p = new Person2();
		p->ref_count = 1;
		return p;
	}
	void add_ref() { ref_count++; }
	void release()
	{
		if (--ref_count == 0)
		{
			delete this;
		}
	}
};
void inc(int& x){ x++; }

string meaningoflife() { return "progress"; }

void move_rvalue()
{
	/*int a = 0;
	inc(a);
	int&& x = meaningoflife();
	cout << x << '\n';*/

	Address book[100];
	book[1] = move(Address("Berlin"));

	auto swap = [](int& a, int& b)
	{
		int tmp{ a };
		a = b;
		b = tmp;
	};
	//move semantics better memory allocation
	auto betterswap = [](int& a, int& b)
	{
		int tmp(move(a));
		a = move(b);
		b = tmp;
	};

	int x = 10, y = 100;
	//betterswap(x, y);
	//cout << x << ": " << y << '\n';
}

auto main() -> int 
{
	move_rvalue();
	getchar();
}