#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iterator>
#include <cstring>
#include <chrono>
#include <map>
using namespace std;
struct Description {

};
struct Technologies {
	int id;
	string name;
	Description description;
	Technologies(const int id, const string &name) : id(id), name(name) {}
	Technologies(const Description &description) : description(description){}
};
struct Exchange{
	int count;
	float rates[2];
	Exchange(initializer_list<float> r){
		if (r.size() < 2){ return; }
		auto i = r.begin();
		rates[0] = *i; i++;
		rates[1] = *i;
	}
};
int main(){
	Exchange e{ 1.01f, 1.001f };
	//uniform initialization
	int n{ 1 };
	string s{ "you sexy string" };
	vector<int> v{ 1, 2, 3, 4, 5, 6 };
	map<int, string> c{
		{ 1, "Germany" },
		{ 2, "USA" },
		{ 3, "France" }
	};
	Technologies t{ 1, "JavaScript" };
	cout << t.name << '\n';


}