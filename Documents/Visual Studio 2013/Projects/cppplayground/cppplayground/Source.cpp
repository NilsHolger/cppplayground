#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Account {
protected:
	double balance;
public:
	Account(double bal){
		if (bal > 0){
			balance = bal;
		}
		else {
			bal = 0.0;
		}
	}
	~Account() {}
	void credit(double amount){
		balance += amount;
	}
	void debit(double amount){
		if (balance > amount){
			balance -= amount;
		}
		else {
			cout << "Insufficient funds." << "\n";
		}
	}
	double getBalance() {
		return balance;
	}
};
class CheckingAccount : public Account {
private:
	double fee;
public:
	CheckingAccount(double bal, double f) : Account(bal)	{ fee = f; }
	~CheckingAccount() {}
	void debit(double amount){
		if (balance > amount){
			balance = balance - amount - fee;
		}
		else {
			cout << "Insufficient funds." << "\n";
		}
	}
};
int main(){
	CheckingAccount myacct(1000, 1.01);
	myacct.credit(100);
	cout << myacct.getBalance() << "\n"; //1100
	myacct.debit(10); 
	cout << myacct.getBalance() << "\n"; //1088.99
	return 0;
}							 