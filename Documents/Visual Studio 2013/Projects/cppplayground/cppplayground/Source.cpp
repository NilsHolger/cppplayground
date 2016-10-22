#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iterator>
using namespace std;
int main(){
	const string s1 = "she has a sexy string";
	const auto num_rs = count(begin(s1), end(s1), 's');
	auto total_length = 0;
	for (const auto &postfix : { "1", "2", "3" }){
		const auto appended = s1 + postfix;
		total_length += appended.size();
	}
	cout << num_rs + total_length << '\n';
}