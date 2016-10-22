#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iterator>
#include <cstring>
#include <chrono>
#include <map>
#include <cmath>
#include <typeinfo>
using namespace std;
class Animal {
protected:
	int legs = 4;
public:
	Animal(int legs) : legs(legs)	{}
	virtual int Walk(int steps){
		return legs * steps * 10;
	}
};
class Human : public Animal {
public:
	Human() : Animal(2){}
	int Walk(int steps) override {
		return legs * steps * 20;
	}
};


int main(){
	Animal a(5);
	cout << a.Walk(10) << '\n';
	Human b;
	cout << b.Walk(10) << '\n';


}