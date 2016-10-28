#include "headers.h"
using namespace std;

namespace life
{
	auto meaning = "progress";
	auto *pm = &meaning;
	auto& rm = meaning;
}

using namespace life;
//using life::meaning;
auto main() -> int 
{
	cout << meaning << " takes up " << sizeof(meaning) << " bytes" << '\n';
	
	*pm = "more progress";
	rm = "and more progress";
	cout << *pm << '\n';

	getchar();
}



