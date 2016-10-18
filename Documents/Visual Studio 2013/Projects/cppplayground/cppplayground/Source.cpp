#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Employee {
protected:
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
	~Employee() {
		//do something here
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
	double grossPay(double hours) {
		return pay * hours;
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
	Manager() : salaried(true) {}
	Manager(string name, double payRate, bool isSalaried) : Employee(name, payRate) {
		salaried = isSalaried;
	}
	~Manager() {
		//free allocated resources
	}
	bool getSalaried(){
		return salaried;
	}
	double grossPay(int hours = 0){
		if (salaried){
			return pay;
		}
		else {
			return pay * hours;
		}
	}
	string toString() {
		stringstream stm;
		string salary;
		if (salaried){
			salary = "Salaried";
		}
		else {
			salary = "Hourly";
		}
		stm << name << ": " << pay << " " << salary;
		return stm.str();
	}
};
int main(){
	Employee emp1("Jane Smith", 50.01);
	cout << emp1.toString() << " " << emp1.grossPay(100.01) << "\n";
	Manager man1("Joe Blow", 50000, true);
	cout << man1.toString() << " " << man1.grossPay() << " " << man1.getSalaried() << "\n";
}							 