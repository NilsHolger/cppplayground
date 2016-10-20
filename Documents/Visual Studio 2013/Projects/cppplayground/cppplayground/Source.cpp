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

int main(){
		
	try {
		throw runtime_error("error occured");
	}
	catch (const exception &e){
		cout << e.what() << "\n";
	}

}	