#include "windows.h"
#define TRACE OutputDebugString


struct ComException
{
	HRESULT error;

	ComException(HRESULT const hr) : error(hr) {}

};

inline void HR(HRESULT const hr)
{
	if (S_OK != hr)
	{
		throw ComException(hr);
	}
}

auto main() -> int
{
	try {
		long hres = -1;
		HR(hres);
	}
	catch (ComException e)
	{
		e.error;
	}

	HRESULT hr = S_OK;

	if (S_OK == hr)
	{
		TRACE(L"succeeded\n");
	}
	else
	{
		TRACE(L"failed\n");
	}





}