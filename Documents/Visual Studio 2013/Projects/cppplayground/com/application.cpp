#include "library.h"



auto main() -> int
{
	ILion *lion = CreateLion();
	lion->Roar();
	//lion->Attack();
	{
		ILion *lion2 = lion;
		lion2->AddRef();
		lion->Attack();
		lion2->Release();
	}
	lion->Release();
}