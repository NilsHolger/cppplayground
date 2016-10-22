#include "headers.h"
using namespace std;
enum class color {
	red, green, blue, rainbow
};
int main(){
	vector<int> v{ 1, 2, 3, 4, 5 };
	auto res = 1;
	for (int a : { 1, 2, 3, 4, 5, 6 }){
		res *= a;
	}
	cout << res << '\n';
	map<int, string> future; 
	future.insert(pair<int,string>(1, "JavaScript"));
	future.insert(pair<int, string>(2, "C++"));
	future.insert(pair<int, string>(3, "NodeJS"));
	future.insert(pair<int, string>(4, "V8"));
	future.insert(pair<int, string>(5, "ms"));
	future.erase(5);
	for (const auto& kvp : future){
		cout << kvp.first << " " << kvp.second << '\n';
	}

}