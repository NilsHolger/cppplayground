#include "headers.h"
using namespace std;

auto main() -> int 
{
	int a[]	{1, 2, 3, 4, 5};
	for (int i = 0; i < 5; ++i){cout << a[i] << '\n';}
	for (int *p = a, *e = a + 5; p != e; ++p){cout << *p << '\n';}						   
	auto ba = begin(a);auto ea = end(a);
	for (; ba != ea; ba++){cout << *ba << '\n';}
	for (auto av : a){cout << av << '\n';}
	vector<int> v{ 6, 7, 8, 9, 10 };
	auto bv = v.begin(); //begin(v);
	auto cbv = v.cbegin(); //const itr
	for (auto i = v.rbegin(); i != v.rend(); ++i){cout << *i << '\n';}
	getchar();
}



