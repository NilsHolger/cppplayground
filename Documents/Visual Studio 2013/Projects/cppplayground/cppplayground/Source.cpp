#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

template <typename T, typename U>
T max(T arg1, U arg2){
	return (arg1 > arg2) ? arg1 : arg2;
}
int main(){
	double num1 = 11.01;
	int num2 = 10;
	cout << max(num2, num1) << "\n";
	//loss of data if data type first arg < second arg, truncation
}