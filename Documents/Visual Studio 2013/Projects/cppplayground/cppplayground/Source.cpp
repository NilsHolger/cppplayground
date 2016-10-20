#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <utility>
#include <map>
using namespace std;
struct Base {
	Base(const int i) : m_i(i){}
	void do_something()	{ m_i += 4; }
	int m_i = 0;
};
struct Derived : Base{
	Derived() : Base(10) {}
	void do_something_else() { ++m_i; }
};
int main(){
	Derived d;
	d.do_something();
	d.do_something_else();
	cout << d.m_i << '\n'; //15
}	