#include "library.h"
#include "windows.h"
#include <crtdbg.h>
#include <new>
using namespace std;

#define ASSERT _ASSERTE
#define TRACE OutputDebugString

struct Lion : ILion2, IOfflineLion
{
	long m_count;
	Lion() : m_count(0){ TRACE(L"Roar!\n"); }

	~Lion()	{ TRACE(L"Lions never die, they multiply.\n"); }

	//
	//IUknown
	//
	ULONG __stdcall AddRef()
	{
		TRACE(L"AddRef\n");
		return _InterlockedIncrement(&m_count);
	}

	ULONG __stdcall Release()
	{
		ULONG const result = InterlockedDecrement(&m_count);
		if (0 == result)
		{
			delete this;
		}
		return result;
	}

	HRESULT __stdcall QueryInterface(IID const & id, void ** result)
	{
		ASSERT(result);
		if (id == _uuidof(ILion2) ||
			id == _uuidof(ILion) ||
			id == _uuidof(IUnknown))
		{
			*result = static_cast<ILion2 *>(this);
		}
		else if (id == _uuidof(IOfflineLion))
		{
			*result = static_cast<IOfflineLion *>(this);
		}
		else
		{
			*result = 0;
			return E_NOINTERFACE;
		}
		static_cast<IUnknown *>(*result)->AddRef();
		return S_OK;
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

HRESULT __stdcall CreateLion(ILion ** result)
{
	ASSERT(result);
	*result = new (std::nothrow) Lion;

	if (0 == *result)
	{
		return E_OUTOFMEMORY;
	}
	(*result)->AddRef();
	return S_OK;
}