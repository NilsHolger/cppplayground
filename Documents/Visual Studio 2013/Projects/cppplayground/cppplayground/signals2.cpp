#include "headers.h";

using namespace std;
using namespace boost;
//using namespace boost::signals2;

class Component
{
	int numberOfConnections;
public:
	string name;
	Component(string name) : name(name){ numberOfConnections = 0; }
	boost::signals2::signal<void(string, int)> Connects;
	void Connections()
	{
		numberOfConnections++;
		Connects(name, numberOfConnections);
	}
};
auto main() -> int
{
	Component c("a1");
	
	auto a = c.Connects.connect([](string name, int count)
	{
		cout << name << " has connected " << count << " time(s)" << '\n';
	});
	c.Connections();
	c.Connections();

	{
		boost::signals2::shared_connection_block b(a);
		c.Connections();
		c.Connections();
	}
	c.Connections();
	c.Connections();
	c.Connections();
	c.Connections();

	getchar();
}