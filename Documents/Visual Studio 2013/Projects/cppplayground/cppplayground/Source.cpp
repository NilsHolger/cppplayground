#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

template <typename T>
void display(T arr[], int size){
	for (int i = 0; i < size; i++){
		cout << arr[i];
	}
	cout << "\n";
}
template <typename T>
T max(T &arg1, T &arg2){
	if (arg1 > arg2){
		return arg1;
	}
	else {
		return arg2;
	}
}
int main(){
	//const int size = 10;
	//int numbers[size];
	//for (int i = 0; i < size; ++i){
	//	numbers[i] = i + 1;
	//}
	//display(numbers, size);
	//string names[] = { "Maria", "Barbara", "Michaela", "Sophie", "Jennifer", "Jane", "Angelika",
	//	"Astrid", "Barbie", "Marie" };
	//display(names, size);
	//int a = 10; int b = 20;
	//cout << max(a, b) << "\n";
	//double x = 30.05; double y = 40.255;
	//cout << max(x, y) << "\n";
	string s1 = "angular"; string s2 = "apple";
	cout << max(s1, s2) << "\n";
}