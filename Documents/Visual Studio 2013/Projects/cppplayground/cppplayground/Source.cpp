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

template<typename T>
struct MyStruct {
	T data;
};
int main(){
	MyStruct<int> s;
	s.data = 1;
	assert(typeid(s.data) == typeid(int));
	cout << s.data << '\n';
}	