#include "headers.h"

using namespace std;

struct Cloud
{
	string name;
	int power;
	friend ostream& operator<<(ostream& os, const Cloud& c){
		return os << c.name << " -> " << c.power;
	}
};

auto main() -> int
{
	vector<Cloud> clouds = { { "sc", 100 }, { "ec", 90 }, { "gc", 80 }, { "az", 70 }, { "hu", 60 }, { "oc", 50 }, { "mc", 95 } };

	auto analyze_all = [&]()
	{
		cout << clouds.size() << " clouds:" << '\n';
		for_each(begin(clouds), end(clouds), [](const Cloud& c){ cout << c << '\n'; });
	};
	analyze_all();

	auto strongest = *max_element(clouds.begin(), clouds.end(), [](const Cloud& a, const Cloud& b)
	{
		return a.power < b.power;
	});
	cout << strongest.name << " expand" << '\n';

	auto oc = find_if(clouds.begin(), clouds.end(), [](const Cloud& c)
	{
		return c.name == string("oc");
	});
	if (oc != clouds.end())
	{
		cout << oc->name << " : " << oc->power << '\n';
	}
	auto gts = count_if(clouds.begin(), clouds.end(), [](const Cloud& c){return c.power > 60; });

	cout << "clouds > 60 : " << gts << '\n';

	sort(clouds.begin(), clouds.end(), [](const Cloud& a, const Cloud& b){ return a.power < b.power; });

	cout << "clouds sorted by power (asc): " << '\n';

	analyze_all();

	Cloud zz{ "zz", 97 };
	replace_if(clouds.begin(), clouds.end(), [](const Cloud& a){return a.name == "az"; }, zz);
	analyze_all();

	getchar();
}