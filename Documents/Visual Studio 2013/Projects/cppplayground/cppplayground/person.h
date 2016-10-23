#include<string>
#include "resource.h";

#ifndef _PERSON_H
#define _PERSON_H

using namespace std;

class Person {
private:
	string firstname;
	string lastname;
	int arbitrarynumber;
	Resource pResource;
public:
	Person(string first, string last, int arbitrary);
	string GetName() const;
	int GetNumber()	const { return arbitrarynumber; }
	void SetNumber(int number){ arbitrarynumber = number; }
	void SetFirstName(string first){ firstname = first; }

	void SetResource(string resourcename);
	string GetResourceName() const { return pResource.GetName(); }

};

#endif