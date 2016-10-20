#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <fstream>
using namespace std;


int main(){
	vector<int> numbers(10);
	int sum = 0;
	for (int i = 1; i < 11; ++i){
		numbers.push_back(i);
	}
	for (int i = 0; i < numbers.size(); ++i){
		sum += numbers[i];
	}
	cout << sum << "\n"; //55

}	