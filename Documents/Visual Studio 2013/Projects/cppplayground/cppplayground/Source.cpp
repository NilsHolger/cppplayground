#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "geometry.h"
using namespace std;


int main(){
	vector<int> v1, v2;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 100);
	generate_n(back_inserter(v1), 100, [&]() { return dis(gen); });
	generate_n(back_inserter(v2), 100, [&]() { return dis(gen); });
	vector<int> in_both;
	sort(begin(v1), end(v1));
	sort(begin(v2), end(v2));
	set_intersection(begin(v1), end(v1), begin(v2), end(v2), back_inserter(in_both));
	for (const auto i : in_both){
		cout << i << ", ";
	}
	cout << "\n";
}