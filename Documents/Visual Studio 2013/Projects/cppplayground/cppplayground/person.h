#include<string>
#include "resource.h";
#include "headers.h";

#ifndef _PERSON_H
#define _PERSON_H

using namespace std;

class Person {
private:
	string firstname;
	string lastname;
	int arbitrarynumber;
	//unique_ptr<Resource> pResource;
	shared_ptr<Resource> pResource;

public:
	Person(string first, string last, int arbitrary);
	//Person(const Person&);
	//Person& operator=(const Person&);
	string GetName() const;
	int GetNumber()	const { return arbitrarynumber; }
	void SetNumber(int number){ arbitrarynumber = number; }
	void SetFirstName(string first){ firstname = first; }

	void SetResource(string resourcename);
	string GetResourceName() const { return pResource->GetName(); }

};

#endif