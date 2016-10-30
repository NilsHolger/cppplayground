#include "headers.h"
using namespace std;

#define M_PI 3.14159265358979323846
auto main() -> int
{
	cout << "max integer is " << numeric_limits<int>::max() << '\n';

	cout << sin( M_PI/ 2) << '\n';

	vector<int> v{ 1, 2, 3, 4, 5, 6 };
	next_permutation(v.begin(), v.end());
	for (auto i : v){ cout << i << '\t'; }
	cout << '\n';

	complex<float> f(0.4f, 0.5f);
	cout << f*f << '\n';

	srand((unsigned)time(nullptr));
	for (int i = 0; i < 100; ++i)
	{
		cout << rand() % 10 << "\t";
	}

	auto seed = chrono::system_clock::now().time_since_epoch().count();
	mt19937 gen(seed);
	normal_distribution<float> nd;
	for (size_t i = 0; i < 100; i++)
	{
		cout << nd(gen) << "\t";
	}

	getchar();
}