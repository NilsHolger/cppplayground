#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iterator>
#include <cstring>
#include <chrono>
#include <map>
#include <cmath>
#include <typeinfo>
#include <functional>
using namespace std;

int main(){
	vector<int> scores{ 10, 5, 1, 7, 9, 11 };
	for_each(begin(scores), end(scores), [](int n){cout << n << '\n'; });
	auto one = 1;
	auto is_positive_tier = [=](int n){ return n > one; };
	cout << boolalpha <<  is_positive_tier(2) << '\n';
	function<int(int)> fib = [&fib](int x){return x < 2 ? 1 : fib(x - 1) + fib(x - 2); };
	cout << fib(10) << '\n';
	for (int i = 1; i <= 10; ++i){
		cout << fib(i) << '\n';
	}
}