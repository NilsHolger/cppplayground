#pragma once
class Technology
{
private:
	static int viability;
protected:
	int internalId;
public:
	const static int off = 0;
	const static int on = 1;
	
	int power;
	string name;
	int survive;
	Address *address;

	Technology(int power, string name, int survive);
	Technology(int power, string name, int survive, int location,
		string url, string domain);
	Technology(const Technology &t);
	~Technology();
	virtual void salute();
	static int getViability();
};

