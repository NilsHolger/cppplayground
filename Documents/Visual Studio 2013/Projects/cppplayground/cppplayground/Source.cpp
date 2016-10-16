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
using namespace std;

struct MyClass {
	string s = "hello world";
};

int main(){
	MyClass *o = new MyClass();
	cout << o->s << "\n";
	delete o;
}							 