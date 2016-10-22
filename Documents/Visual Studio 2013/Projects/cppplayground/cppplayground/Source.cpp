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
using namespace std;
auto meaning_of_life() -> int{
	return 1;
}
template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u){
	return t + u;
}
auto get_fun(int a) ->double(*)(double){
	switch (a){
	case 1: return fabs;
	case 2: return sin;
	case 3: return cos;
	}
}
int main(){
	auto a = 1 + 2; cout << typeid(a).name() << '\n';
	auto b = add(1, 1.1); cout << typeid(b).name() << '\n';
	auto c = { 1, 2 }; cout << typeid(c).name() << '\n';
	auto d = [](int x) { return x * x; };
	auto my_fun = get_fun(1); cout << typeid(my_fun).name() << '\n';
	cout << my_fun(3) << '\n';
}