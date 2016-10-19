#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
template <typename T>
bool equals(T value1, T value2){
	return (value1 == value2) ? true : false;
}
int main(){
	int a = 0, b = 1;
	cout << equals(a, b) << "\n";
	string s1, s2;
	s1 = s2 = "you sexy string";
	cout << equals(s1, s2) << "\n";
}