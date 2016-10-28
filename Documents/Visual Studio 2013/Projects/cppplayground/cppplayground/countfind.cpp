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

auto main() -> int 
{
	string s("sexy string"); //allocated on stack cleaned up when exit scope
	string* t = new string("tuv"); //alloc on heap new needs delete
	delete t;
	int* values = new int[256];
	delete[] values;

	getchar();
}



