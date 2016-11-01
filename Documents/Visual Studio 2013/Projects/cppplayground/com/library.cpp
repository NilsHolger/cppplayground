#include "library.h"
#include "precompiled.h"
#include <wrl.h>

using namespace std;
using namespace Microsoft::WRL;

#define ASSERT _ASSERTE
#define TRACE OutputDebugString

//struct Lion : ILion2, IOfflineLion
struct Lion : RuntimeClass<RuntimeClassFlags<ClassicCom>, ILion, ILion2, IOfflineLion>
{
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

HRESULT __stdcall CreateLion(ILion ** result)
{
	ASSERT(result);
	//*result = new (std::nothrow) Lion;
	*result = nullptr;
	ComPtr<ILion2> lion = Make<Lion>();

	if (!lion)
	{
		return E_OUTOFMEMORY;
	}
	//(*result)->AddRef();
	*result = lion.Detach();
	return S_OK;
}