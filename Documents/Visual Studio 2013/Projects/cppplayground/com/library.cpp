#include "library.h"
#include "windows.h"

#define TRACE OutputDebugString

struct Lion : ILion2, IOfflineLion
{
	unsigned m_count;
	Lion() : m_count(0){ TRACE(L"Roar!\n"); }

	~Lion()	{ TRACE(L"Lions never die, they multiply.\n"); }

	//
	//IObject
	//
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

	void * __stdcall As(const char *type)
	{
		if (0 == strcmp(type, "ILion2") || 0 == strcmp(type, "ILion") || 0 == strcmp(type, "IObject"))
		{
			AddRef();
			return static_cast<ILion2 *>(this);
		}
		else if (0 == strcmp(type, "IOfflineLion"))
		{
			AddRef();
			return static_cast<IOfflineLion*>(this);
		}
		else
		{
			return 0;
		}
	}

	//
	//ILion
	//

	void __stdcall Roar()
	{
		TRACE(L"Roar\n");
	}

	void __stdcall Attack()
	{
		TRACE(L"Attack\n");
	}

	//
	//ILion2
	//
	void __stdcall Hunt()
	{
		TRACE(L"Hunt!\n");
	}
	//
	//IOfflineLion
	//
	void __stdcall Load(char const * /*file*/)
	{

	}
	void __stdcall Save(char const * /*file*/)
	{

	}

};

ILion * __stdcall CreateLion()
{
	ILion * result = new Lion;
	result->AddRef();
	return result;
}