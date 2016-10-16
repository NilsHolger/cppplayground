#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "geometry.h"
using namespace std;

int main(){
	const string s1 = "she has a sexy string"; 
	const auto num_ss = count(begin(s1), end(s1), 's');
	const vector<string> postfixes = { "1", "2", "3" };
	int total_length = 0;
	for (const auto &postfix : postfixes){
		const auto appended = s1 + postfix;
		total_length += appended.size();
	}
	cout << "count s " << num_ss << "\n" << "total length " << total_length << "\n"; // 4 66
}