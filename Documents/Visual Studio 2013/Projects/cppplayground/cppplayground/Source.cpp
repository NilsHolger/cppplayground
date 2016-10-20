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
class Test {
	int i = 100;
public:
	struct Nested {
		static int get_private_i(const Test &t){
			return t.i;
		}
	};
};

int main(){
	Test t;
	cout << Test::Nested::get_private_i(t) << '\n';
}	