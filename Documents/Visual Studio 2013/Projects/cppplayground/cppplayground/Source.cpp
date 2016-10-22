#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iterator>
using namespace std;

int main(int argc, const char*[]){
	const auto vc = [](){
		vector<int> v(100, 0);
		v[10] = 1;
		return v;
	}();
	cout << vc[10] << '\n';
}