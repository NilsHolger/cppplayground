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

void loopDisplay(deque<string> ds){
	for (int i = 0; i < ds.size(); ++i){
		cout << ds[i] << "\n";
	}
}
int main(){
	deque<string> tech;tech.push_back("C++");tech.push_front("JavaScript");tech.push_back("NodeJS");
	loopDisplay(tech);tech.pop_back();tech.pop_front();loopDisplay(tech);
	cout << tech.size() << "\n";
}	