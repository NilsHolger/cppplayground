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

template<typename T>
void print_elements(const T &items){
	for (const auto &e : items){
		cout << e << "\n";
	}
}

int main(){
	array<int, 3> ints{ { 3, 2, 1 } };
	array<string, 6> strings{ { "she", "has", "the", "sexiest", "string", "!" } };
	array<char, 3> chars{ { 'a', 'b', 'c' } };
	print_elements(chars);
}							 