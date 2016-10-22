#include "headers.h"
using namespace std;

string getName(){
	return "Node";
}
void printName(const string& name){
	cout << "stand ref: " << name << '\n';
}
void printName(string&& name){
	cout << "rvalue ref: " << name << '\n';
}

int main(){
	
	string name1 = getName(); cout << name1 << '\n';

	string& name2 = getName(); cout << name2 << '\n';
	name2 = "V8"; cout << name2 << '\n';

	string&& name3 = getName();
	name3 = "lib_uv"; cout << name3 << '\n';

	string name4{ "JavaScript" };
	printName(getName());
	printName(name4);
	string name5{ "C++" };
	printName(getName());
	printName(name5);
}