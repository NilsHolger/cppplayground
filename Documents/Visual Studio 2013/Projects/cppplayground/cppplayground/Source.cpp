#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iterator>
using namespace std;

int main(int argc, const char*[]){
	const string s1 = [&](){
		switch (argc)
		{
		case 0: return "0 args";
		case 1: return "1 args";
		default: return "many args";
		}
	}();
	cout << s1 << '\n';
}