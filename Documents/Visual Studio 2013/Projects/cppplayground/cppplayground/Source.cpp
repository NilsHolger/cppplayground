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

struct Derived {
	int do_something(){
		return value++;
	}
	int value = 10;
};
struct Derived2 {
	int do_something(){
		return value += 1;
	}
	int value = 100;
};

int main(){
	vector<Derived> objs1;
	vector<Derived2> objs2;

	for (int i = 0; i < 1000; ++i){
		objs1.emplace_back();
		objs2.emplace_back();
	}
	const auto do_something = [](auto &v){
		for (auto &o : v){
			o.do_something();
		}
	};

	do_something(objs1);
	do_something(objs2);
}