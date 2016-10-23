#include "resource.h"
#include "headers.h"
using namespace std;


Resource::Resource(string n) :name(n){
	cout << "constructing " << name << '\n';
}

Resource::Resource(const Resource& r) : name(r.name){
	cout << "copy constructing " << name << '\n';
}

Resource& Resource::operator=(const Resource& r){
	name = r.GetName();
	cout << "copy assigning " << name << '\n';
	return *this;
}

Resource::~Resource(void){
	cout << "destructing " << name << '\n';
}

