#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <sstream>
#include <chrono>
#include "geometry.h"
#include "windows.h"
using namespace std;

struct Timer {
	const chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();
	~Timer(){
		cout << chrono::duration<double>{chrono::system_clock::now() - start}.count() << "s\n";
	}
};
bool complex_calculation() {
	//perform a complex calculation here
	Sleep(500);
	return true;
}
int main(){
	Timer t;
	if (complex_calculation()){
		return EXIT_SUCCESS;
	}
	else {
		return EXIT_FAILURE;
	}
}