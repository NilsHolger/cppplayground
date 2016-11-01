#include "precompiled.h"
#include "server.h"


struct Lion : ILion
{
	long m_count;
	Lion() : m_count(0)	{}

	ULONG __stdcall AddRef() override
	{
		return _InterlockedIncrement(&m_count);
	}

	ULONG __stdcall Release() override
	{
		ULONG result = _InterlockedDecrement(&m_count);

		if (0 == result)
		{
			delete this;
		}
		return result;
	}

	HRESULT __stdcall QueryInterface(IID const & id, void ** result) override
	{
		ASSERT(result);
		if (id == __uuidof(ILion) || id == __uuidof(IUnknown))
		{
			*result = static_cast<ILion *>(this);
		}
		else
		{
			*result = 0;
			return E_NOINTERFACE;
		}
		static_cast<IUnknown *>(*result)->AddRef();
		return S_OK;
	}

	void __stdcall Roar() override
	{
		TRACE(L"Roar!\n");
	}

};

struct Cave : ICave
{
	ULONG __stdcall AddRef() override
	{
		return 2;
	}
	ULONG __stdcall Release() override
	{
		return 1;
	}

	HRESULT __stdcall QueryInterface(IID const & id, void ** result) override
	{
		ASSERT(result);
		if (id == __uuidof(ICave) || id == _uuidof(IUnknown))
		{
			*result = static_cast<ICave *>(this);
		}
		else
		{
			*result = 0;
			return E_NOINTERFACE;
		}
		return S_OK;
	}

	HRESULT __stdcall CreateLion(ILion ** result) override
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
};

HRESULT __stdcall DllGetClassObject(CLSID const & clsid, IID const & iid, void ** result)
{
	ASSERT(result);
	*result = nullptr;

	if (__uuidof(Lion) == clsid)
	{
		static Cave cave;
		return cave.QueryInterface(clsid, result);
	}
	return CLASS_E_CLASSNOTAVAILABLE;
}
