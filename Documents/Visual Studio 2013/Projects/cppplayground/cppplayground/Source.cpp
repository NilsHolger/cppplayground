#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iterator>
#include <cstring>
#include <chrono>
#include <windows.h>
using namespace std;

struct Timer {
	~Timer(){
		cout << chrono::duration<double>{chrono::system_clock::now() - start}
		.count() << "s\n";
	}
	chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();
};

int main(){
	Timer t;
	Sleep(100);
}