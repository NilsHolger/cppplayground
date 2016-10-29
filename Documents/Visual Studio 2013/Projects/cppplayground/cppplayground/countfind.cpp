#include "headers.h"
#include "address.h"
#include "technology.h"
#include "component.h"
#include "compfactory.h"
using namespace std;

auto main() -> int 
{
	Technology t(80, "t", Technology::on);   
	//Technology *t2 = new Technology(50, "t2", Technology::off);

	//t2->salute();
	//int v = t.getViability();
	//cout << v << '\n';

	//Technology *t3 = new Technology(70, "t3", Technology::off);
	//auto* address = new Address(100, "https", "www");
	//t3->address = address;
	//t3->salute();

	//Technology t4(*t3);
	//t3->address->url = "http";
	//cout << t4.address->url << '\n';

	Component c(90, "c", Technology::on,"a c c");

	auto d = [](const Technology& t)
	{
		cout << t.name << '\n';
	};
	d(c);

	Technology &tr = c;
	//Component& cr = static_cast<Component&>(tr);
	//cout << cr.description << '\n';

	Technology& tr2 = t;
	//access violation reading location, static_cast performs no checks
	//Component& cr2 = static_cast<Component&>(tr2);
	//cout << cr2.description << '\n';

	tr.salute();
	try
	{
		Component& cr2 = dynamic_cast<Component&>(tr2);
		cout << cr2.description << '\n';
	}
	catch (const bad_cast& e)
	{
		cout << "cannot cast this " << e.what() << '\n';
	}

	Technology *tt = &t;
	Component *cp = dynamic_cast<Component*>(tt);
	if (cp){
		cout << cp->description << '\n';
	}
	else {
		cout << "failed to cast pointer " << cp << '\n';
	}


	//delete t2;
	//delete t3;
	getchar();
}



