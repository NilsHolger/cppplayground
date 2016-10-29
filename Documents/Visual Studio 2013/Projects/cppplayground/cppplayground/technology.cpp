#include "headers.h"
#include "address.h"
#include "technology.h"

Technology::Technology(int power, string name, int survive)
	: power(power), name(name), survive(survive)
{
	address = nullptr;
}
Technology::Technology(int power, string name, int survive, int location, string url, string domain)
	: Technology(power, name, survive)
{
	if (address != nullptr){
		delete address;
	}
	address = new Address(location, url, domain);
}

Technology::Technology(Technology const& t) :
power(t.power), name(t.name), survive(t.survive)
{
	auto *a = t.address;
	address = new Address(
		a->location,
		a->url,
		a->domain);
}

Technology::~Technology()
{
	if (address != nullptr){
		delete address;
		address = nullptr;
	}
}

void Technology::salute()
{
	cout << "name is " << name << " and power is " << power << "." <<   '\n';
	if (address){
		cout << "lives at " << address->location << ", " << address->url << ", "
			<< address->domain << '\n';
	}
}

int Technology::getViability()
{
	return viability;
}

int Technology::viability = 10;
