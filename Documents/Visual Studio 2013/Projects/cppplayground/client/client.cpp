#include "precompiled.h"
#include "..\server\server.h"

using namespace Microsoft::WRL;

int main()
{
	ComRuntime runtime;

	ComPtr<IClassFactory> cave;

	HR(CoGetClassObject(__uuidof(Lion),
		CLSCTX_INPROC_SERVER,
		nullptr,
		__uuidof(cave),
		reinterpret_cast<void **>(cave.GetAddressOf())));

	ComPtr<ILion> lion;

	HR(cave->CreateInstance(nullptr, // outer
		__uuidof(lion),
		reinterpret_cast<void **>(lion.GetAddressOf())));

	lion->Roar();
}
