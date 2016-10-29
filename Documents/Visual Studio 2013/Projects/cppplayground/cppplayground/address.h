#pragma once
#include "headers.h"
using namespace std;
class Address
{
public:
	int location;
	string url;
	string domain;

	Address(int location, string const& url, string const& domain) : location(location),
		url(url), domain(domain){}
};

