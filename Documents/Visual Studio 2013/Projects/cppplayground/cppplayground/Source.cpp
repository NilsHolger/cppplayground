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

struct Object {
	shared_ptr<int> i = make_shared<int>(1);
	void update_value(){
		if (*i < 2) i = make_shared<int>(3);
	}
	static void print(const int t_i){ cout << t_i << "\n"; }
	void use_value(){
		//const auto local_i = i;
		update_value();
		print(*i);
	}
};

int main(){
	Object o;
	o.use_value();
}							 