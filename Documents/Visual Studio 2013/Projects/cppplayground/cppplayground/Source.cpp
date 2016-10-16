#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "geometry.h"
using namespace std;

int main(){
	size_t num_ss, total_length;
	vector<string> postfixes;
	string s1, appended;
	s1 = "she has a sexy string"; 
	num_ss = count(begin(s1), end(s1), 's');
	postfixes = { "1", "2", "3" };
	total_length = 0;
	for (const auto &postfix : postfixes){
		appended = s1 + postfix;
		total_length += appended.size();
	}
	cout << "count s " << num_ss << "\n"; //4
	cout << "total length " << total_length << "\n"; //66
}