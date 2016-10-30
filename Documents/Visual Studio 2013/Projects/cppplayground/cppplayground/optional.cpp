#include "headers.h"

using namespace std;
using namespace boost;

class Location
{
public:
	Location(string url) :url(url){}
	string url;
};

class Tech
{
public:
	Tech(int id, string name):
		id(id), name(name){}
	int id; string name;
	optional<string> GetDescription() { return description; }
	optional<Location> location;
	optional<string> description;
};

auto main()	-> int
{
	Tech t{ 1, "nodejs" };
	t.description = "javascript runtime built on v8 and libuv. event-driven, non blocking i/o model. lightweight and efficient. npm is largest ecosystem of libraries in the world.";
	if (t.description)
	{
		cout << *t.description << '\n';
	}
	t.description = "disruptive technology. in the future everything will run on node. no more exes and dlls, only node extension.";
	cout << *t.GetDescription() << '\n';
	t.location = Location{ "lives here: https://nodejs.org/dist/latest-v7.x/docs/api/" };
	if (t.location)
	{
		cout << t.location->url << '\n';
	}
	getchar();
}