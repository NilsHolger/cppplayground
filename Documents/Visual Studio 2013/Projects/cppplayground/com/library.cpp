#include "library.h"
#include "windows.h"

#define TRACE OutputDebugString

struct Lion : ILion
{
	Lion(){ TRACE(L"Roar!\n"); }

	~Lion()	{ TRACE(L"Lions never die, they multiply.\n"); }

	void __stdcall Roar()
	{
		TRACE(L"Roar\n");
	}

	void __stdcall Attack()
	{
		TRACE(L"Attack\n");
	}
};

ILion * __stdcall CreateLion()
{
	return new Lion;
}