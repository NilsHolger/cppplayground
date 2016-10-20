#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <fstream>
using namespace std;


int main(){
	ifstream gradeFile; stringstream grades;
	int grade;  int total = 0; string line;
	gradeFile.open("grades.txt");
	getline(gradeFile, line);
	grades << line;
	gradeFile.close();
	for (int i = 0; i < 5; ++i){
		grades >> grade;
		total += grade;
	}
	double average = total / 5;
	cout << average << "\n"; //80
}	