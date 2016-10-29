#pragma once
#include "technology.h"
#include <string>
using namespace std;
class Component : public Technology
{
	friend class CompFactory;
private:
	int componentId;
public:
	Component() : Technology(0, "", 0){}
	Component(int power, string const name, int survive, string description = string())
		: Technology(power, name, survive), description(description){
		internalId = 1;
	}

	void salute() override;

	string description;
};