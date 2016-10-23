#include "person.h";

using namespace std;


int main(){

	Person Nils("Nils-Holger", "Nägele", 1001);
	Nils.SetResource("Nils Resource");
	Nils.SetResource("Nils Second Resource");
	Person Nils1 = Nils;
	Nils = Nils1;
	string s = Nils.GetResourceName();
}
