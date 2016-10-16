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
using namespace std;
struct Base {
	virtual int do_something() = 0;
	virtual ~Base() = default;
	Base() = default;
	//Base(Base &&) = default;
	Base(const Base &) = default;
	//Base& operator = (Base &&) = default;
	Base& operator = (const Base &) = default;
};

struct Derived : Base {
	virtual int do_something() override {
		return value++;
	}
	int value = 10;
};

struct Derived2 : Base {
	virtual int do_something() override {
		return value += 1;
	}
	int value = 100;
};

int main(){
		
	vector<shared_ptr<Base>> objs;

	for (int i = 0; i < 1000; i++){
		objs.push_back(make_shared<Derived>());
		objs.push_back(make_shared<Derived2>());
	}
	for (const auto &o : objs){
		cout << o->do_something() << "\n";
	}
}