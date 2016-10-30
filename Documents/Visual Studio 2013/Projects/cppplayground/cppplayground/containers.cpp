#include "headers.h"
using namespace std;


template<int n>
int sum(array<int, n> values)
{
	int result = 0;
	for (int value : values)
	{
		result += value;
	}
	return result;
}

auto main() -> int
{
	//array<int, 6> numbers = { { 1, 2, 3, 4, 5, 6 } };
	//cout << sum(numbers) << '\n';
	//vector<float> values{ 1, 2, 3, 4, 5 };
	/*values.push_back(6.5f);
	values.push_back(7);
	values.pop_back();
	cout << values.size() << '\n';
	for (float value : values){
		cout << value << '\t';
	}
	try {
		float v = values.at(5);
	}
	catch (const out_of_range& e){
		cout << e.what() << '\n';
	}*/
	string s("throw an exception");
	set<char> l;
	for (char c : s)
	{
		if (isalpha(c)){ l.insert(c); }
	}
	for (char c : l)
	{
		cout << c << '\t';
	}
	cout << '\n';

	map<char, int> h;
	for (char c : s)
	{
		if (isalpha(c)){ h[c]++; }
	}
	for (auto u : h)
	{
		cout << u.first << " - " << u.second << '\n';
	}

	getchar();
}