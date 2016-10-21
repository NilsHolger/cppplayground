#include <iostream>
#include <vector>

using namespace std;
size_t count_1(const vector<int> &t_v){
	return count(begin(t_v), end(t_v), 1);
}
int main(){
	vector<int> v{ 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1 };
	cout << count_1(v) << '\n';	
}	