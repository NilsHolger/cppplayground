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
	string s = "she has a sexy string.";

};

int main(){
	void *p = malloc(sizeof(MyClass));
	MyClass *o = new (p)MyClass();
	cout << o->s << "\n";
	free(p);
}							 