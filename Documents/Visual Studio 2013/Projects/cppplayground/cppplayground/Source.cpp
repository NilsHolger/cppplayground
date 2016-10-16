#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "geometry.h"
using namespace std;

string multichoiceinit(int in){
	const string s1 = [&](){
		switch (in){
		case 0: return "0 Arguments";
		case 1: return "1 Argument";
		default: return "Many Arguments";
		}
	}();
	return s1;
}

int main(){
	cout << multichoiceinit(1) << "\n";
}