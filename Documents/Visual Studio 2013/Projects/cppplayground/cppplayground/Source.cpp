#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <utility>
#include <map>
using namespace std;

int main(){
	pair<int, string> n(1, "Node");
	cout << n.first << " " << n.second << "\n";
	map<int, string> o; o[1] = "JS"; o[2] = "C++"; o[3] = "V8"; o[4] = "C#";
	cout << o[1] << " " << o.size() << "\n"; o.erase(4); cout << o.size() << "\n";
	int p = 3; if (o.find(p) != o.end()){ cout << o[p] << "\n"; }
	map<int, string>::iterator it = o.begin();
	while (it != o.end()){ cout << it->second << "\n"; it++; }
}	