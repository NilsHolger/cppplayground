#include "headers.h"
#include "address.h"
#include "technology.h"
#include "component.h"

void Component::salute()
{
	Technology::salute();

	cout << "salute from component " << description << '\n';
}
