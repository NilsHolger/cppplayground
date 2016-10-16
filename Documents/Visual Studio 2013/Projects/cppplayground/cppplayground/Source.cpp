#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "geometry.h"
using namespace std;

struct S_Counter {
	S_Counter(string t_s):
		s(move(t_s)),
		num_ss(count(s.begin(), s.end(), 's')) {}
	const string s;
	const int num_ss;
};

int main(){
	const string s1 = "she has a sexy string"; 
	cout << S_Counter(s1).num_ss << "\t" << S_Counter(s1).s << "\n";
}