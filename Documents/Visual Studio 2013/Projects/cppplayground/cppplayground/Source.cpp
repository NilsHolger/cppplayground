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
using namespace std;

void use_logger(const shared_ptr<FILE> &out, const shared_ptr<FILE> & err){

	string s = "hello world";

	fwrite(s.c_str(), 1, s.size(), out.get());
	fwrite(s.c_str(), 1, s.size(), err.get());
}

int main(){
	const auto FILE_maker = [](const string &t_fname){
		FILE *f = fopen(t_fname.c_str(), "a");
		if (f == nullptr){
			throw runtime_error("unable to open file for appending: " + t_fname);
		}
		else {
			return f;
		}
	};
	const auto FILE_deleter = [](FILE *f) { fclose(f); };
	try {
		shared_ptr<FILE>out(FILE_maker("logout"), FILE_deleter);
		shared_ptr<FILE>err(FILE_maker("logerr"), FILE_deleter);
		use_logger(out,err);
	}
	catch (const exception &e){
		cout << "Exception: " << e.what() << "\n";
	}

}							 