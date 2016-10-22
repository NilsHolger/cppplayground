#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iterator>
using namespace std;

struct SCounter{
	SCounter(string t_s) : s(move(t_s)), num_s(count(s.begin(), s.end(), 's')){}
	const string s;
	const int num_s;
};

int main(){
	const string s1 = "she has a sexy string";
	SCounter s(s1);
	cout << s.num_s << '\n';
}