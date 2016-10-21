#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(){
	const vector<int> v{ 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1 };
	const vector<string> w{ "you", "sexy", "string" };
	const vector<char> x{ 'h','e','l','l','o','w','o','r','l','d' };
	//for (auto itr = v.begin(); itr != v.end(); ++itr){
	//	cout << *itr << "\n";
	//}
	for (const auto &i : x){
		cout << i << "\n";
	}
}	