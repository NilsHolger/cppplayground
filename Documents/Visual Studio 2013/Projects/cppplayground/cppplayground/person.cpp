#include "person.h"

#include "headers.h"

using namespace std;

Person::Person(string first, string last, int arbitrary) : firstname(first), lastname(last),
arbitrarynumber(arbitrary), pResource(""){}

string Person::GetName() const {
	return firstname + " " + lastname;
}
void Person::SetResource(string resourcename) {
	Resource newResource(resourcename);
	pResource = newResource;
}

