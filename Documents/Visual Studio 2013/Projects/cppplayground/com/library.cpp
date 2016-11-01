#include "library.h"
#include <atlbase.h>
#include <atlcom.h>


using namespace std;

#define ASSERT _ASSERTE
#define TRACE OutputDebugString

//struct Lion : ILion2, IOfflineLion
struct Lion : CComObjectRootEx<CComMultiThreadModel>, ILion2, IOfflineLion
{
	BEGIN_COM_MAP(Lion)
		COM_INTERFACE_ENTRY(ILion)
		COM_INTERFACE_ENTRY(ILion2)
		COM_INTERFACE_ENTRY(IOfflineLion)
	END_COM_MAP()

	Lion() { TRACE(L"Roar!\n"); }

	~Lion()	{ TRACE(L"Lions never die, they multiply.\n"); }

	//
	//ILion
	//

	void __stdcall Roar() override
	{
		TRACE(L"Roar\n");
	}

	void __stdcall Attack() override
	{
		TRACE(L"Attack\n");
	}

	//
	//ILion2
	//
	void __stdcall Hunt() override
	{
		TRACE(L"Hunt!\n");
	}
	//
	//IOfflineLion
	//
	void __stdcall Load(char const * /*file*/) override
	{

	}
	void __stdcall Save(char const * /*file*/) override
	{

	}

};

struct Module : CAtlDllModuleT<Module>
{

};

static Module _AtlModule;

BOOL __stdcall DllMain(HINSTANCE, DWORD reason, void * reserved)
{
	return _AtlModule.DllMain(reason, reserved);
}


HRESULT __stdcall CreateLion(ILion ** result)
{
	ASSERT(result);
	//*result = new (std::nothrow) Lion;
	*result = nullptr;
	auto object = new (nothrow)CComObject<Lion>;


	if (!object)
	{
		return E_OUTOFMEMORY;
	}
	object->AddRef();
	HRESULT hr = object->QueryInterface(result);
	object->Release();
	return hr;
}