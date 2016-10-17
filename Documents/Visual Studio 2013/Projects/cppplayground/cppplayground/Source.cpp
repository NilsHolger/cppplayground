#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <sstream>
#include <chrono>
#include "geometry.h"
#include "windows.h"
#include <cmath>
#include <memory>
#include <array>
#include <map>
#include <list>
using namespace std;


int main(){
	int count; list<string> words;
	words.push_back("she"); words.push_back("has"); words.push_back("a"); words.push_back("sexy"); words.push_back("string");
	count = 0;
	for (list<string>::const_iterator itr = words.begin(); itr != words.end(); ++itr){
		for (int j = 0; j < static_cast<int>(itr->size()); ++j){
			if ((*itr)[j] == 's'){ ++count; }
		}
	}
	cout << count << "\n";
}							 