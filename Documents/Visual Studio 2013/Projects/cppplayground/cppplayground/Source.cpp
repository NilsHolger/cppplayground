#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

template<typename T>
class Stack {
private:
	T datastore[100];
	int top;
public:
	Stack(){
		top = -1;
	}
	~Stack(){}
	void push(T num){
		++top;
		datastore[top] = num;
	}
	T pop(){
		T value = datastore[top];
		datastore[top] = 0;
		--top;
		return value;
	}
	T peek(){
		return datastore[top];
	}
};
template<>
class Stack<string> {
private:
	string datastore[100];
	int top;
public:
	Stack(){
		top = -1;
	}
	~Stack(){}
	void push(string val){
		++top;
		datastore[top] = val;
	}
	string pop(){
		string value = datastore[top];
		datastore[top] = "";
		--top;
		return value;
	}
	string peek(){
		return datastore[top];
	}
};

int main(){
	Stack<int> numbers;
	numbers.push(10); numbers.push(20); numbers.push(30);
	cout << numbers.peek() << "\n"; //LIFO 30
	cout << numbers.pop() << "\n"; //30
	cout << numbers.peek() << "\n"; //20
	Stack<string> strings; strings.push("Marie"); strings.push("Maria"); strings.push("Eva");
	cout << strings.peek() << "\n"; //Eva
	cout << strings.pop() << "\n"; //Eva
	cout << strings.peek() << "\n"; //Maria
}