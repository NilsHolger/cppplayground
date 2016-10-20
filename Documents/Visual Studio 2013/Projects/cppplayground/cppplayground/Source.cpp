#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
using namespace std;

int find(deque<string> d, string v){
	for (int i = 0; i < d.size(); i++){
		if (d.at(i) == v){
			return i;
		}
	}
	return -1;
}
int main(){
	deque<string> tech;tech.push_back("C++");tech.push_front("JavaScript");tech.push_back("NodeJS");
	int found = find(tech, "NodeJS");
	(found > -1) ? cout << tech[found] << "\n" : cout << "not found" << "\n";
}	