#include "headers.h"
using namespace std;


auto main() -> int 
{
	int x = 2;
	auto doubleValue = [](int y) { return y * 2; }; // y!
	cout << doubleValue(x) << '\n';
	int y = 3;
	auto increaseByY = [&y](int z) { return z + y; };
	y = 11;
	cout << increaseByY(5) << '\n';
	getchar();
}



