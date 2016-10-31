#include "library.h"



auto main() -> int
{
	ILion *lion;

	if (S_OK != CreateLion(&lion))
	{
		return 0;
	}
	lion->Roar();
	//lion->Attack();
	
	ILion2 * lion2;

	if (S_OK == lion->QueryInterface(&lion2))
	{
		lion2->Hunt();
		lion2->Release();
	}

	IOfflineLion * offline;


	if (S_OK == lion->QueryInterface(&offline))
	{
		offline->Save("filename");
		offline->Release();
	}


	lion->Release();
}