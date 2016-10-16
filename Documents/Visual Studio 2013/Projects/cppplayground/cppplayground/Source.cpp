#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <sstream>
#include <chrono>
#include "geometry.h"
#include "windows.h"
#include <cmath>
#include <memory>
#include <array>
#include <map>
using namespace std;

class Person {
public:
	Person() { cout << "person constructor\n"; }
	~Person() { cout << "person destructor\n"; }
	void UsePerson() { cout << "useperson()\n"; }
};

void DoIt(const Person &){
	cout << "in doit()\n";
}

int main(){
	unique_ptr<Person> p1(new Person);
	if (p1){p1->UsePerson();}
	DoIt(*p1);
	{
		unique_ptr<Person> p2(move(p1));
		DoIt(*p2);
		p1 = move(p2);
		cout << "p2 goes out of scope\n";
	}
	if (p1) { p1->UsePerson(); }
}							 