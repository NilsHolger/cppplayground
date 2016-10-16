#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "geometry.h"
using namespace std;


int main(){
	vector<int> v1;
	vector<int> v2;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 100);

	for (int i = 0; i < 100; ++i){
		v1.push_back(dis(gen));
		v2.push_back(dis(gen));
	}
	vector<int> in_both;
	for (const auto i : v1){
		for (const auto j : v2){
			if (i == j){
				in_both.push_back(j);
				break;
			}
		}
	}
	for (const auto i : in_both){
		cout << i << ", ";
	}
	cout << "\n";
}