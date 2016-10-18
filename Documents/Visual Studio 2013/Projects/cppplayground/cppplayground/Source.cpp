#include <string>
#include <iostream>
#include <sstream>
#include <vector>
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
	~Employee() {}
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
	virtual double grossPay(double hours) {
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
	~Manager() {}
	bool getSalaried(){
		return salaried;
	}
	virtual double grossPay(double hours){
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
	vector<Employee*> emps;
	Employee emp1("Jane", 10.01);
	Manager man1("Bob", 1000.01, true);
	emps.push_back(&emp1); emps.push_back(&man1);
	for (int i = 0; i < emps.size(); ++i){
		cout << emps[i]->grossPay(100) << "\n";
	}
}