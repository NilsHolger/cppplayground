#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
using namespace std;
class DivideByZero : public runtime_error {
public:
	DivideByZero() : runtime_error("divide by zero exception") {}
	~DivideByZero() {}
};

double quotient(double num, double den){
	if (den == 0) { throw DivideByZero(); }
	else { return num / den; }
}

int main(){
	try {
		cout << quotient(10, 0) << "\n";
		//throw "a new exception";
	}
	catch (DivideByZero &except){
		cout << except.what() << "\n";
	}
	catch (...){
		cout << "catch all exceptions" << "\n";
	}
}	