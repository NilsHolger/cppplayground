#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iterator>
using namespace std;
int main(){
	vector<int> n1; vector<int> n2;
	random_device rd; mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 100);
	generate_n(back_inserter(n1), 100, [&]() {return dis(gen);});
	generate_n(back_inserter(n2), 100, [&]() {return dis(gen);});
	vector<int> in_both;
	sort(n1.begin(), n1.end());
	sort(n2.begin(), n2.end());
	set_intersection(begin(n1), end(n1), begin(n2), end(n2), back_inserter(in_both));
	for (const auto i : in_both){
		cout << i << ',';
	}
	cout << '\n';
}