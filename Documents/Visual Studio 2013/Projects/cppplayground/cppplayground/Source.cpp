#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <fstream>
using namespace std;


int main(){
	ifstream file;
	file.exceptions(ifstream::failbit | ifstream::badbit);
	try {
		file.open("file.txt");
		while (!file.eof()){
			cout << file.get();
		}
	}
	catch (ifstream::failure e){
		cout << e.what() << "\n";
		cout << "error opening file." << "\n";
		return 1;
	}
	file.close();
}	