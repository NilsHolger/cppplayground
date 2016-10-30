#include "library.h"
#include "windows.h"

#define TRACE OutputDebugString

struct Lion : ILion
{
	unsigned m_count;
	Lion() : m_count(0){ TRACE(L"Roar!\n"); }

	~Lion()	{ TRACE(L"Lions never die, they multiply.\n"); }

	void __stdcall Roar()
	{
		TRACE(L"Roar\n");
	}

	void __stdcall Attack()
	{
		TRACE(L"Attack\n");
	}

	void __stdcall AddRef()
	{
		++m_count;
	}

	void __stdcall Release()
	{
		if (0 == --m_count)
		{
			delete this;
		}
	}

};

ILion * __stdcall CreateLion()
{
	ILion * result = new Lion;
	result->AddRef();
	return result;
}