#include "headers.h"
using namespace std;

class Technology {
public:
	Technology(){};
	Technology(const Technology&) { cout << "technology copied" << "\n"; }
	int id;
	double power;
	string description;
};

class Software {
public:
	shared_ptr<Technology> technology;
	Software(){
		technology = make_unique<Technology>();
	}
};

unique_ptr<Technology> create_technology_smart(int id, string description){
	auto t = make_unique<Technology>();
	t->id = id;
	t->description = description;
	return t;
}

int main(){
	auto mts = create_technology_smart(1, "01000101");
	cout << mts->id << " " << mts->description << '\n';
	shared_ptr<Technology> t;
	{
		Software s;
		s.technology->id = 100;
		s.technology->description = "11110011";
		s.technology->power = 100;
		t = s.technology;
	}
	cout << t->power << '\n';
}