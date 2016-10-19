#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
template<typename T>
class List {
private:
	vector<T> datastore;
public:
	List() {}
	~List() {}
	void add(T item){
		datastore.push_back(item);
	}
	void display(){
		for (int i = 0; i < datastore.size(); ++i){
			cout << datastore[i] << "\n";
		}
	}
};
int main(){
	List<string> tL; tL.add("eat"); tL.add("sleep"); tL.add("code"); tL.add("repeat");
	tL.display();
	List<int> in; in.add(1); in.add(2); in.add(3); in.add(4); in.add(5); in.add(6);
	in.display();
}	