#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Employee {
private:
	string name;
	double pay;
public:
	Employee(){
		name = "";
		pay = 0;
	}
	Employee(string empName, double payRate){
		name = empName;
		pay = payRate;
	}
	string getName(){
		return name;
	}
	void setName(string empName){
		name = empName;
	}
	double getPay(){
		return pay;
	}
	void setPay(double payRate){
		pay = payRate;
	}
	string toString() {
		stringstream stm;
		stm << name << ": " << pay;
		return stm.str();
	}
};
class Manager : public Employee {
private:
	bool salaried;
public:
	Manager(string name, double payRate, bool isSalaried) : Employee(name, payRate) {
		salaried = isSalaried;
	}
	bool getSalaried(){
		return salaried;
	}
};
int main(){
	Employee emp1("Jane Smith", 35000);
	cout << emp1.toString() << "\n";
	Manager man1("Joe Blow", 50000, true);
	cout << man1.toString() << " " << man1.getSalaried() << "\n";

}							 