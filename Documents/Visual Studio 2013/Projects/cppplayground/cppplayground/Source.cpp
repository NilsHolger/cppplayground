#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <list>
using namespace std;

void loopDisplay(list<string> ls){
	list<string>::iterator doit = ls.begin();
	while (doit != ls.end()){
		cout << *doit << "\n";
		++doit;
	}
}
int main(){
	list<string> tdl; tdl.push_back("eat"); tdl.push_back("sleep"); tdl.push_back("code");
	loopDisplay(tdl);
	cout << tdl.front() << " " << tdl.back() << "\n"; tdl.reverse();
	loopDisplay(tdl);
	tdl.sort();
	loopDisplay(tdl);
}	