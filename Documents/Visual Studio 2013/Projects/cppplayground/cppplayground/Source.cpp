#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main(){
	const vector<int> v{ 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 2 };
	const bool found = any_of(begin(v), end(v), [](int i){return i > 1; });
	cout << found << "\n";
}	