#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
template<class T, class U>
class CMap {
private:
	vector<T> keys;
	vector<U> values;
public:
	void insert(T key, U value){
		keys.push_back(key);
		values.push_back(value);
	}
	void get(int n){
		cout << keys[n] << " : " << values[n] << "\n";
	}
};
int main(){
	CMap<int, string> c;
	c.insert(1, "value1"); c.insert(2, "value2"); c.insert(3, "value3");
	c.get(1);
}