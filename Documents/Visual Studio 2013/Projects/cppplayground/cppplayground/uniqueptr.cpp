#include "headers.h"

using namespace std;

struct Foo
{
	Foo() { cout << "Foo::Foo\n"; }
	~Foo() { cout << "Foo:~Foo\n"; }
	void bar() { cout << "Foo::bar\n"; }
};

void f(const Foo &)
{
	cout << "f(const Foo&)\n";
}

//auto main() -> int
//{
//	unique_ptr<Foo> p1(new Foo); //p1 owns foo
//	if (p1){ p1->bar(); }
//	{
//		unique_ptr<Foo> p2(move(p1)); //now p2 owns foo
//		f(*p2);
//		p1 = move(p2); //ownership returns to p1
//		cout << "destroying p2 ... \n";
//	}
//	if (p1) { p1->bar(); }
//
//	//getchar();
//}