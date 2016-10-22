#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iterator>
using namespace std;

class Technology {
public:
	Technology(int id, string description) : m_id(id), m_description(move(description)){}
	string description() const { return m_description; }
private:
	int m_id = 0;
	string m_description;
};

int main(){
	vector<Technology> ts;
	const vector<string> vs{ "C++", "JS", "NodeJS", "V8", "lib_uv" };
	for (int i = 0; i < vs.size(); ++i){
		ts.emplace_back(i, "ID: " + vs[i]);
	}
	for (const auto &t : ts){
		cout << "T: " << t.description() << '\n';
	}
}