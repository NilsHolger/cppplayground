#include "headers.h"
using namespace std;

auto main() -> int 
{
	char *s = "playground";
	while (*s)
	{
		putchar(*s);
		s++;
	}

	int *p = nullptr;
	if (p){
		cout << "do something" << '\n';
	}

	int i = 1;
	switch (i)
	{
	case 0:
		cout << "hello" << '\n';
		break;
	case 1:
		cout << "world" << '\n';
		break;
	default:
		break;
	}

	getchar();
}



