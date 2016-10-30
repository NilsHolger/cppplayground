#include "headers.h"

using namespace std;
using namespace boost;





auto main() -> int
{
	any w;
	any x{ 3.0 };
	string s = "progress";
	vector<any> y{ 1001, s };
	any z = string("yum, yum");

	if (!x.empty())
	{
		cout << x.type().name() << '\n';
	}

	int a = any_cast<int>(y[0]);
	string t = any_cast<string>(y[1]);
	cout << a << " " << t  << " " << any_cast<string>(z) << '\n';
	try
	{
		int b = any_cast<int>(y[1]);
	}
	catch (const bad_any_cast& e)
	{
		cout << e.what() << '\n';
	}

	for (auto a : y)
	{
		int *value = any_cast<int>(&a);
		if (value != nullptr)
		{
			cout << *value << ' ';
			continue;
		}
		auto w = any_cast<string>(a);
		cout << w << ' ';
	}
	cout << any_cast<string>(z) << '\n';
	getchar();
}