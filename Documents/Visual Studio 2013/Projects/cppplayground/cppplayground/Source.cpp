#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(){
	const int DivideByZero = 1;
	try	{
		int num = 10; int den = 0;
		if (den == 0){
			throw DivideByZero;
		}
		else {
			cout << num / den << "\n";
		}
	}
	catch (int e){
		if (e == DivideByZero){
			cout << "can't divide by zero" << "\n";
		}
	}
}	