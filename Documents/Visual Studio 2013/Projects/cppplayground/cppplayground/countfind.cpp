#include "headers.h"
using namespace std;

void stack_and_heap()
{
	string s("good evening");
	string* t = new string("joe");
	delete t;
	int* values = new int[128];
	delete[] values;
}

auto add(int a, int b)-> int{ return a + b; }
auto enhance(string& s)-> void{ s += " value"; }
inline auto add(string* s)-> void{ *s += " count"; }

auto main() -> int 
{
	string s = "results";
	cout << s << '\n';
	add(&s);
	cout << s << '\n';

	getchar();
}



