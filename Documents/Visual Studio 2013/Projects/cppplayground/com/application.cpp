#include "library.h"



int main()
{
	ILion *lion = CreateLion();
	lion->Roar();
	lion->Attack();

	delete lion;

}