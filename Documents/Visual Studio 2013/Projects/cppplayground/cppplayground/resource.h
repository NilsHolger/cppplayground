#pragma once
#include <string>
using namespace std;
class Resource {
private:
	string name;
public:
	Resource(string n);
	Resource(const Resource& r);
	Resource& operator=(const Resource& r);
	~Resource(void);
	string GetName() const { return name; }
};