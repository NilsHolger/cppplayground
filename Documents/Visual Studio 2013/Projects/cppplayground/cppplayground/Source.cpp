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
#include <assert.h>
using namespace std;

struct Base {
friend int main();
public: int i;
protected: int j;
private: int k;
};
struct Derived : protected Base {
friend int main();
public: int l;
protected: int m;
private: int n;
};
int main(){
	Derived d;d.i = 1;d.j = 2;d.k = 3;d.l = 4;d.m = 5;d.n = 6;
}	