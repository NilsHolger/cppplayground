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
#include <list>
using namespace std;

struct Object {
	Object() = default;
	virtual ~Object() = default;
	Object(const Object &) = default;
	Object &operator  = (const Object&) = default;
	//Object(Object &&) = default;
	//Object &operator =(Object&&) = default;
	virtual int value() { return 10; }
};
struct Derived : Object {
	virtual int value() override { return 100; }
};


int main(){
	auto o = make_unique<Derived>();
	cout << o->value() << "\n";
}							 